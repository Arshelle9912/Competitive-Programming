#include <bits/stdc++.h>
using namespace std;

struct Hungarian {
    using ll = long long;
    static constexpr ll INF = (ll)4e18;

    struct Result {
        ll value;                           // optimal total cost / profit
        vector<int> left_to_right;          // left node i -> right node j
        vector<int> right_to_left;          // right node j -> left node i
    };

    int n;                                  // internal square size
    int left_size, right_size;              // original bipartite sizes
    vector<vector<ll>> a;                   // internal 1-indexed square matrix
    vector<ll> u, v, minv;                  // potentials
    vector<int> p, way;                     // matching reconstruction
    bool minimize;                          // true = min assignment, false = max assignment

    Hungarian() {}

    Hungarian(const vector<vector<ll>>& mat, bool minimize_ = true) {
        init(mat, minimize_);
    }

    void init(const vector<vector<ll>>& mat, bool minimize_ = true) {
        minimize = minimize_;
        left_size = (int)mat.size();
        right_size = left_size ? (int)mat[0].size() : 0;
        n = max(left_size, right_size);

        a.assign(n + 1, vector<ll>(n + 1, 0));

        // Copy real matrix into 1-indexed square matrix
        for (int i = 1; i <= left_size; i++) {
            for (int j = 1; j <= right_size; j++) {
                a[i][j] = mat[i - 1][j - 1];
            }
        }

        // Convert max assignment into min assignment by negating real entries
        if (!minimize) {
            for (int i = 1; i <= left_size; i++) {
                for (int j = 1; j <= right_size; j++) {
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

    void reset_state() {
        fill(u.begin(), u.end(), 0);
        fill(v.begin(), v.end(), 0);
        fill(p.begin(), p.end(), 0);
        fill(way.begin(), way.end(), 0);
        fill(minv.begin(), minv.end(), 0);
    }

    ll reduced_cost(int i, int j) const {
        return a[i][j] - u[i] - v[j];
    }

    Result solve() {
        reset_state();

        for (int i = 1; i <= n; i++) {
            p[0] = i;
            int j0 = 0;
            vector<ll> minv(n + 1, INF);
            vector<char> used(n + 1, false);

            do {
                used[j0] = true;
                int i0 = p[j0];
                int j1 = 0;
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

            // Augment along alternating path
            do {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0 != 0);
        }

        vector<int> left_to_right(left_size, -1);
        vector<int> right_to_left(right_size, -1);

        for (int j = 1; j <= n; j++) {
            if (p[j] >= 1 && p[j] <= left_size) {
                int left = p[j] - 1;
                int right = j - 1;

                if (right < right_size) {
                    left_to_right[left] = right;
                    right_to_left[right] = left;
                }
            }
        }

        ll value = 0;
        for (int i = 0; i < left_size; i++) {
            if (left_to_right[i] != -1) {
                value += a[i + 1][left_to_right[i] + 1];
            }
        }

        if (!minimize) value = -value;

        return {value, left_to_right, right_to_left};
    }

    ll solve_value() {
        return solve().value;
    }

    vector<int> solve_left_to_right() {
        return solve().left_to_right;
    }

    vector<int> solve_right_to_left() {
        return solve().right_to_left;
    }

    vector<pair<int,int>> assignment_pairs(const vector<int>& left_to_right) const {
        vector<pair<int,int>> pairs;
        for (int i = 0; i < (int)left_to_right.size(); i++) {
            if (left_to_right[i] != -1) {
                pairs.push_back({i, left_to_right[i]});
            }
        }
        return pairs;
    }

    static Result min_assignment(const vector<vector<ll>>& mat) {
        Hungarian H(mat, true);
        return H.solve();
    }

    static Result max_assignment(const vector<vector<ll>>& mat) {
        Hungarian H(mat, false);
        return H.solve();
    }
};

int main() {
    using ll = long long;

    // Example cost/profit matrix:
    // left side nodes = rows
    // right side nodes = cols
    vector<vector<ll>> mat = {
        {2500, 4000, 3500},
        {4000, 6000, 3500},
        {2000, 4000, 2500}
    };

    // Minimum assignment
    auto minRes = Hungarian::min_assignment(mat);

    cout << "Minimum assignment value = " << minRes.value << "\n";

    cout << "Left -> Right:\n";
    for (int i = 0; i < (int)minRes.left_to_right.size(); i++) {
        cout << "Left " << i << " -> Right " << minRes.left_to_right[i] << ", Value: " << mat[i][minRes.left_to_right[i]] << "\n";
    }

    cout << "Right -> Left:\n";
    for (int j = 0; j < (int)minRes.right_to_left.size(); j++) {
        cout << "Right " << j << " -> Left " << minRes.right_to_left[j] << "\n";
    }

    cout << "Matched pairs:\n";
    for (auto [l, r] : Hungarian(mat, true).assignment_pairs(minRes.left_to_right)) {
        cout << "(" << l << ", " << r << ")\n";
    }

    cout << "\n";

    // Maximum assignment
    auto maxRes = Hungarian::max_assignment(mat);

    cout << "Maximum assignment value = " << maxRes.value << "\n";

    cout << "Left -> Right:\n";
    for (int i = 0; i < (int)maxRes.left_to_right.size(); i++) {
        cout << "Left " << i << " -> Right " << maxRes.left_to_right[i] << "\n";
    }

    cout << "Right -> Left:\n";
    for (int j = 0; j < (int)maxRes.right_to_left.size(); j++) {
        cout << "Right " << j << " -> Left " << maxRes.right_to_left[j] << "\n";
    }

    cout << "Matched pairs:\n";
    for (auto [l, r] : Hungarian(mat, false).assignment_pairs(maxRes.left_to_right)) {
        cout << "(" << l << ", " << r << ")\n";
    }

    return 0;
}