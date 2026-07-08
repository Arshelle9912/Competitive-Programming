#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> bfs(vector<vector<char>>& grid, pair<int, int>& start) {
    int n = grid.size();
    int m = grid[0].size();
    int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    dist[start.first][start.second] = 0;
    deque<pair<int, int>> q;
    q.push_front(start);
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {-1, 1, 0, 0};
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop_front();
        for (int i = 0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr<0 || nr>=n || nc<0 || nc>=m) continue;
            if (grid[nr][nc] == '*') continue;
            int w = (grid[nr][nc] == '#');
            if (dist[nr][nc] > dist[r][c] + w) {
                dist[nr][nc] = dist[r][c] + w;
                if (w) q.push_back({nr, nc});
                else q.push_front({nr, nc});
            }
        }
    }
    return dist;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> ngrid(n);
        for (int i = 0; i<n; i++) {
            cin >> ngrid[i];
        }
        vector<vector<char>> grid(n+2, vector<char> (m+2, '.'));
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<=m; j++) {
                grid[i][j] = ngrid[i-1][j-1];
            }
        }
        pair<int, int> be = {0, 0};
        vector<vector<int>> dist1 = bfs(grid, be);
        pair<int, int> start1 = {-1, -1};
        pair<int, int> start2 = {-1, -1};
        for (int i = 0; i<=n+1; i++) {
            for (int j = 0; j<=m+1; j++) {
                if (grid[i][j]=='$') {
                    pair<int, int> temp = {-1, -1};
                    if (start1==temp) start1 = {i, j};
                    else {start2={i, j}; break;}
                }
            }
        }
        vector<vector<int>> dist2 = bfs(grid, start1);
        vector<vector<int>> dist3 = bfs(grid, start2);
        int ans = INT_MAX;
        for (int i = 0; i<=n+1; i++) {
            for (int j = 0; j<=m+1; j++) {
                if (grid[i][j]=='*') continue;
                if (dist1[i][j] == 1e9 || dist2[i][j] == 1e9 || dist3[i][j] == 1e9) continue;
                int cost = dist1[i][j] + dist2[i][j] + dist3[i][j];
                if (grid[i][j]=='#') cost-=2;
                ans = min(ans,  cost);
            }
        }
        printf("%d\n", ans);
    }
}