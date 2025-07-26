#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n, vector<int>(m));
        int maximum = INT_MIN;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> adj[i][j];
                if (adj[i][j] > maximum) 
                    maximum = adj[i][j];
            }

        vector<vector<int>> rowCols(n);
        vector<int> colCount(m, 0);
        vector<bool> colHasMax(m, false);
        int distinct = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (adj[i][j] == maximum) {
                    rowCols[i].push_back(j);
                    if (!colHasMax[j]) {
                        colHasMax[j] = true;
                        distinct++;
                    }
                    colCount[j]++;
                }
            }
        }

        bool check = false;
        if (distinct <= 1) {
            check = true;
        } else {
            for (int i = 0; i < n; i++) {
                if (rowCols[i].empty()) continue;
                map<int,int> cnt;
                for (int c : rowCols[i])
                    cnt[c]++;
                int covered = 0;
                for (auto &p : cnt) {
                    if (colCount[p.first] == p.second)
                        covered++;
                }
                if (covered >= distinct - 1) {
                    check = true;
                    break;
                }
            }
        }

        cout << (check ? maximum - 1 : maximum) << "\n";
    }
}