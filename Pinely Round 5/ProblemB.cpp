#include <bits/stdc++.h>
using namespace std;

static bool hasTripleOrTwoGroups(const string& s) {
    int n = (int)s.size();
    int groups = 0;
    for (int i = 0; i < n; ) {
        if (s[i] == '#') {
            int j = i;
            while (j < n && s[j] == '#') ++j;
            int len = j - i;
            if (len >= 3) return true;      // "###"
            ++groups;                        // count this contiguous block
            if (groups >= 2) return true;    // e.g., "#...#" or multiple blocks
            i = j;
        } else ++i;
    }
    return false;
}

static bool checkLines(const vector<string>& g) {
    int n = (int)g.size();
    // rows
    for (int r = 0; r < n; ++r)
        if (hasTripleOrTwoGroups(g[r])) return false;
    // cols
    for (int c = 0; c < n; ++c) {
        string col; col.reserve(n);
        for (int r = 0; r < n; ++r) col.push_back(g[r][c]);
        if (hasTripleOrTwoGroups(col)) return false;
    }
    return true;
}

static bool noSandwiches(const vector<string>& g) {
    int n = (int)g.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (g[i][j] == '#') {
            // vertical sandwich
            if (i-1 >= 0 && i+1 < n && g[i-1][j] == '#' && g[i+1][j] == '#')
                return false;
            // horizontal sandwich
            if (j-1 >= 0 && j+1 < n && g[i][j-1] == '#' && g[i][j+1] == '#')
                return false;
        }
    }
    return true;
}

static int countSquares(const vector<string>& g) {
    int n = (int)g.size(), sq = 0;
    for (int i = 0; i+1 < n; ++i) {
        for (int j = 0; j+1 < n; ++j) {
            if (g[i][j] == '#' && g[i][j+1] == '#' && g[i+1][j] == '#' && g[i+1][j+1] == '#')
                ++sq;
        }
    }
    return sq;
}

// Check if all '#' lie on ONE 2-wide diagonal ribbon (either main-diagonal slope or anti-diagonal)
static bool fitsTwoWideDiagonalRibbon(const vector<pair<int,int>>& cells, int n) {
    if (cells.empty()) return true;

    // Build rows -> set of columns containing '#'
    vector<vector<int>> colsInRow(n);
    for (auto [r,c] : cells) colsInRow[r].push_back(c);
    for (int r = 0; r < n; ++r) sort(colsInRow[r].begin(), colsInRow[r].end());

    auto testMain = [&]() -> bool {
        // Try to find integer k such that for any row with cells: columns == {k+r, k+r+1}
        // If a row has exactly 2 cells, they must be consecutive; deduce k = c0 - r or c1 - r - 1.
        // If a row has 1 cell, it must be either k+r or k+r+1; we’ll verify after deducing k from a 2-cell row, or try both candidates.
        vector<int> kCandidates;
        for (int r = 0; r < n; ++r) {
            if ((int)colsInRow[r].size() == 2) {
                int c0 = colsInRow[r][0], c1 = colsInRow[r][1];
                if (c1 != c0 + 1) return false; // not consecutive -> cannot fit ribbon
                kCandidates.push_back(c0 - r);
            }
        }
        // If no 2-cell row, derive candidates from one 1-cell row (two options)
        if (kCandidates.empty()) {
            for (int r = 0; r < n; ++r) if ((int)colsInRow[r].size() == 1) {
                int c = colsInRow[r][0];
                kCandidates.push_back(c - r);     // assume it's k+r
                kCandidates.push_back(c - r - 1); // assume it's k+r+1
                break;
            }
            if (kCandidates.empty()) return true; // no cells at all
        }

        // Try each candidate k
        for (int k : kCandidates) {
            bool ok = true;
            for (int r = 0; r < n && ok; ++r) {
                const auto& v = colsInRow[r];
                if (v.empty()) continue;
                if (v.size() == 2) {
                    int expect0 = k + r, expect1 = k + r + 1;
                    if (!(v[0] == expect0 && v[1] == expect1)) ok = false;
                } else if (v.size() == 1) {
                    int expect0 = k + r, expect1 = k + r + 1;
                    if (!(v[0] == expect0 || v[0] == expect1)) ok = false;
                } else ok = false; // >2 in a row can't fit a 2-wide ribbon
            }
            if (ok) return true;
        }
        return false;
    };

    auto testAnti = [&]() -> bool {
        // Anti-diagonal: columns must be {k - r, k - r + 1}
        vector<int> kCandidates;
        for (int r = 0; r < n; ++r) {
            if ((int)colsInRow[r].size() == 2) {
                int c0 = colsInRow[r][0], c1 = colsInRow[r][1];
                if (c1 != c0 + 1) return false;
                kCandidates.push_back(c0 + r);
            }
        }
        if (kCandidates.empty()) {
            for (int r = 0; r < n; ++r) if ((int)colsInRow[r].size() == 1) {
                int c = colsInRow[r][0];
                kCandidates.push_back(c + r);     // assume it's k - r
                kCandidates.push_back(c + r - 1); // assume it's k - r + 1
                break;
            }
            if (kCandidates.empty()) return true;
        }
        for (int k : kCandidates) {
            bool ok = true;
            for (int r = 0; r < n && ok; ++r) {
                const auto& v = colsInRow[r];
                if (v.empty()) continue;
                if (v.size() == 2) {
                    int expect0 = k - r, expect1 = k - r + 1;
                    if (!(v[0] == expect0 && v[1] == expect1)) ok = false;
                } else if (v.size() == 1) {
                    int expect0 = k - r, expect1 = k - r + 1;
                    if (!(v[0] == expect0 || v[0] == expect1)) ok = false;
                } else ok = false;
            }
            if (ok) return true;
        }
        return false;
    };

    return testMain() || testAnti();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;
        vector<string> g(n);
        for (int i = 0; i < n; ++i) cin >> g[i];

        bool ok = true;

        // Rule 1 & 2: rows/cols: reject "###" and multiple groups like "#...#"
        if (ok) ok = checkLines(g);

        // Rule 3 & 4: no vertical/horizontal sandwiches
        if (ok) ok = noSandwiches(g);

        // Rule 5: at most one 2x2 square
        if (ok) {
            int sq = countSquares(g);
            if (sq >= 2) ok = false;
        }

        // Rule 6: if any horizontal pair "##" exists anywhere,
        // enforce that ALL '#' lie on ONE 2-wide diagonal ribbon (either main or anti).
        if (ok) {
            bool hasHorzPair = false;
            vector<pair<int,int>> cells;
            int nrows = n, ncols = n;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) if (g[i][j] == '#') {
                    cells.emplace_back(i,j);
                    if (j+1 < n && g[i][j+1] == '#') hasHorzPair = true;
                }
            }
            if (hasHorzPair) {
                if (!fitsTwoWideDiagonalRibbon(cells, n)) ok = false;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
