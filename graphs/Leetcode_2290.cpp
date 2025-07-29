#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};
int minimumObstacles(vector<vector<int>>& grid) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
    pq.emplace(grid[0][0], make_pair(0, 0));
    dist[0][0] = grid[0][0];
    while (!pq.empty()) {
        auto [d, coord] = pq.top();
        auto [u, v] = coord;
        pq.pop();
        if (d>dist[u][v]) continue;
        for (int i = 0; i<4; i++) {
            int newU = u + dx[i];
            int newV = v + dy[i];
            if (newU<0 || newU>=n || newV<0 || newV>=m) continue;
            if (dist[newU][newV]>dist[u][v]+grid[newU][newV]) {
                dist[newU][newV]=dist[u][v]+grid[newU][newV];
                pq.emplace(dist[newU][newV], make_pair(newU, newV));
            }
        }
    }
    return dist[n-1][m-1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int> (m));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cin >> grid[i][j];
        }
    }
    cout << minimumObstacles(grid) << "\n";
}