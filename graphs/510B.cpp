#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
bool dfs(vector<vector<char>>& adj, int row, int col, int rowPar, int colPar, vector<vector<bool>>& visited, char color) {
    visited[row][col] = true;
    int n = adj.size();
    int m = adj[0].size();
    for (int i = 0; i<4; i++) {
        int nrow = row + dx[i], ncol = col + dy[i];
        if (nrow < 0 || nrow>=n || ncol<0 || ncol>=m) continue;
        if (adj[nrow][ncol]!=color) continue;
        if (nrow==rowPar && ncol==colPar) continue;
        if (visited[nrow][ncol]) return true;
        if (dfs(adj, nrow, ncol, row, col, visited, color)) return true;
    }
    return false;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char> (m));
    for (int i = 0; i<n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j<m; j++) {
            adj[i][j] = s[j];
        }
    }
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            vector<vector<bool>> visited(n, vector<bool> (m, false));
            if (dfs(adj, i, j, 0, 0, visited, adj[i][j])) {
                cout << "Yes" << "\n";
                return 0;
            };
        }
    }
    cout << "No" << "\n";
}