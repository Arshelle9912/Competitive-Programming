#include <bits/stdc++.h>
using namespace std;

struct Hungarian {
    using ll = long long;
    static constexpr ll INF = (ll)4e18;

    int n;                              // internal square size
    int rows, cols;                     // original dimensions
    vector<vector<ll>> a;               // cost/profit matrix (internally square)
    vector<ll> u, v, minv;              // potentials / reduced cost helpers
    vector<int> p, way;                 // matching reconstruction helpers
    bool minimize;                      // true = min assignment, false = max assignment

    Hungarian() {}

    Hungarian(const vector<vector<ll>>& mat, bool minimize_ = true) {
        init(mat, minimize_);
    }

    // Initialize with rectangular or square matrix
    void init(const vector<vector<ll>>& mat, bool minimize_ = true) {
        minimize = minimize_;
        rows = (int)mat.size();
        cols = rows ? (int)mat[0].size() : 0;
        n = max(rows, cols);

        a.assign(n + 1, vector<ll>(n + 1, 0));

        // copy into 1-indexed square matrix
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                a[i][j] = mat[i - 1][j - 1];
            }
        }

        // For max assignment, convert to min by negating real entries
        if (!minimize) {
            for (int i = 1; i <= rows; i++) {
                for (int j = 1; j <= cols; j++) {
                    a[i][j] = -a[i][j];
                }
            }
        }

        u.assign(n + 1, 0);
        v.assign(n + 1, 0);
        p.assign(n + 1, 0);
        way.assign(n + 1, 0);
        minv.assign(n + 1, 0);
    }

    // Optional helper: reset dual arrays if you want to rerun solve on same object
    void reset_state() {
        fill(u.begin(), u.end(), 0);
        fill(v.begin(), v.end(), 0);
        fill(p.begin(), p.end(), 0);
        fill(way.begin(), way.end(), 0);
        fill(minv.begin(), minv.end(), 0);
    }

    // Reduced cost of edge (i, j)
    ll reduced_cost(int i, int j) const {
        return a[i][j] - u[i] - v[j];
    }

    // Main solve:
    // returns optimal value and assignment row -> col (0-indexed, -1 if matched to dummy)
    pair<ll, vector<int>> solve() {
        reset_state();

        for (int i = 1; i <= n; i++) {
            p[0] = i;
            int j0 = 0;
            vector<ll> minv(n + 1, INF);
            vector<char> used(n + 1, false);

            do {
                used[j0] = true;
                int i0 = p[j0], j1 = 0;
                ll delta = INF;

                for (int j = 1; j <= n; j++) {
                    if (used[j]) continue;
                    ll cur = a[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }

                for (int j = 0; j <= n; j++) {
                    if (used[j]) {
                        u[p[j]] += delta;
                        v[j] -= delta;
                    } else {
                        minv[j] -= delta;
                    }
                }

                j0 = j1;
            } while (p[j0] != 0);

            // augment
            do {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0 != 0);
        }

        vector<int> assignment(rows, -1);   // row i -> assigned col
        for (int j = 1; j <= n; j++) {
            if (p[j] >= 1 && p[j] <= rows) {
                int r = p[j] - 1;
                int c = j - 1;
                if (c < cols) assignment[r] = c;
            }
        }

        ll value = 0;
        for (int i = 0; i < rows; i++) {
            if (assignment[i] != -1) value += a[i + 1][assignment[i] + 1];
        }

        if (!minimize) value = -value;

        return {value, assignment};
    }

    // Convenience wrapper: only optimal value
    ll solve_value() {
        return solve().first;
    }

    // Convenience wrapper: only assignment
    vector<int> solve_assignment() {
        return solve().second;
    }

    // Build inverse assignment col -> row from row -> col
    vector<int> inverse_assignment(const vector<int>& row_to_col) const {
        vector<int> col_to_row(cols, -1);
        for (int i = 0; i < (int)row_to_col.size(); i++) {
            if (row_to_col[i] != -1) col_to_row[row_to_col[i]] = i;
        }
        return col_to_row;
    }

    // Return matched pairs (row, col)
    vector<pair<int,int>> assignment_pairs(const vector<int>& row_to_col) const {
        vector<pair<int,int>> pairs;
        for (int i = 0; i < (int)row_to_col.size(); i++) {
            if (row_to_col[i] != -1) pairs.push_back({i, row_to_col[i]});
        }
        return pairs;
    }

    // Static helper: solve min-cost assignment directly
    static pair<ll, vector<int>> min_assignment(const vector<vector<ll>>& mat) {
        Hungarian H(mat, true);
        return H.solve();
    }

    // Static helper: solve max-profit assignment directly
    static pair<ll, vector<int>> max_assignment(const vector<vector<ll>>& mat) {
        Hungarian H(mat, false);
        return H.solve();
    }
};

int main() {
    using ll = long long;
    int job, worker;
    cin >> worker >> job;
    vector<vector<ll>> grid(worker, vector<ll>(job));
    for (int i = 0; i < worker; i++) {
        for (int j = 0; j < job; j++) {
            cin >> grid[i][j];
        }
    }
    auto [minCost, assignMin] = Hungarian::min_assignment(grid);
    cout << "Min cost = " << minCost << "\n";
    for (int i = 0; i < (int)assignMin.size(); i++) {
        cout << "row " << i << " -> col " << assignMin[i] << "\n";
    }
    cout << "\n";
    auto [maxProfit, assignMax] = Hungarian::max_assignment(grid);
    cout << "Max profit = " << maxProfit << "\n";
    for (int i = 0; i < (int)assignMax.size(); i++) {
        cout << "row " << i << " -> col " << assignMax[i] << "\n";
    }
    return 0;
}