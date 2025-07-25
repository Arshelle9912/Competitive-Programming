#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
int dfs(vector<vector<char>>& adj, vector<vector<bool>>& visited, int row, int col, int parRow, int parCol) {
    visited[row][col] = true;
    int n = adj.size();
    int m = adj[0].size();
    int count = 0;
    if (adj[row][col]=='G') count++;
    for (int i = 0; i<4; i++) {
        int newRow = row+dx[i];
        int newCol = col+dy[i];
        if (newRow<0 || newRow>=n || newCol<0 || newCol>=m) continue;
        if (visited[newRow][newCol]) continue;
        if (adj[newRow][newCol]=='#') continue;
        count += dfs(adj, visited, newRow, newCol, row, col);
    }
    return count;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> adj(n, vector<char> (m));
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                cin >> adj[i][j];
            }
        }
        bool check = true;
        int actual(0);
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                if (adj[i][j]=='B') {
                    for (int k = 0; k<4; k++) {
                        int newRow = i+dx[k];
                        int newCol = j+dy[k];
                        if (newRow<0 || newRow>=n || newCol<0 || newCol>=m) continue;
                        if (adj[newRow][newCol]=='G') check = false;
                        if (adj[newRow][newCol]=='.') adj[newRow][newCol] = '#';
                    }
                } else if (adj[i][j]=='G') {
                    actual++;
                }
            }
        }
        vector<vector<bool>> visited(n, vector<bool> (m));
        if (adj[n-1][m-1]=='#') check = false;
        int count = dfs(adj, visited, n-1, m-1, -1, -1);
        if (count!=actual) check = false;
        if (actual==0) check = true;
        if (check) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}