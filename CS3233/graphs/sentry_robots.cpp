#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> matchR, vis; 
bool dfs(int u) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (matchR[v]==-1 || dfs(matchR[v])) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}
int maxMatching(int row, int col) {
    matchR.assign(row+1, -1);
    int ans = 0;
    for (int u = 0; u<=col; u++) {
        vis.assign(row+1, 0);
        if (dfs(u)) ans++;
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h, w;
        cin >> h >> w;
        int ps;
        cin >> ps;
        vector<vector<char>> grid(h, vector<char>(w, '.'));
        vector<pair<int, int>> points(ps);
        for (int i = 0; i<ps; i++) {
            int num1, num2;
            cin >> num1 >> num2;
            num1--, num2--;
            points[i].first = num1;
            points[i].second = num2;
            grid[num1][num2] = '*';
        }
        int os;
        cin >> os;
        for (int i = 0; i<os; i++) {
            int num1, num2;
            cin >> num1 >> num2;
            num1--, num2--;
            grid[num1][num2] = '#';
        }
        map<pair<int, int>, int> rowSeg;
        map<pair<int, int>, int> colSeg;
        int row = 0;
        int col = 0;
        for (int i = 0; i<h; i++) {
            for (int j = 0; j<w; j++) {
                if (grid[i][j]=='#') {
                    row++;
                    continue;
                }
                rowSeg[{i, j}] = row;
            }
            row++;
        }
        for (int i = 0; i<w; i++) {
            for (int j = 0; j<h; j++) {
                if (grid[j][i]=='#') {
                    col++;
                    continue;
                }
                colSeg[{j, i}] = col;
            }
            col++;
        }
        adj.assign(col+1, {});
        matchR.assign(row+1, -1);
        for (int i = 0; i<ps; i++) {
            adj[colSeg[{points[i].first, points[i].second}]].push_back(rowSeg[{points[i].first, points[i].second}]);
        }
        printf("%d\n", maxMatching(row, col));
    }
}