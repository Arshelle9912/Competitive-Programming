#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int> (m));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cin >> grid[i][j];
        }
    }
    int n1, n2;
    cin >> n1 >> n2;
    --n1;
    --n2;
    vector<int> dir1 = {-1, 1, 1, -1, 0, 0, 1, -1};
    vector<int> dir2 = {0, 0, -1, 1, 1, -1, 1, -1};
    int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    dist[n1][n2] = grid[n1][n2];
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({dist[n1][n2], n1, n2});
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>> (m));
    while (!pq.empty()) {
        auto [d, u1, u2] = pq.top();
        pq.pop();
        if (d != dist[u1][u2]) continue;
        for (int i = 0; i<8; i++) {
            int v1 = u1+dir1[i];
            int v2 = u2+dir2[i];
            if (v1<0 || v1>=n || v2<0 || v2>=m) continue;
            if (grid[v1][v2]>=0) continue;
            int w = max(dist[u1][u2], grid[v1][v2]);
            if (w<dist[v1][v2]) {
                dist[v1][v2] = w;
                pq.push({dist[v1][v2], v1, v2});
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] < 0) ans += -1LL * dist[i][j];
        }
    }
    printf("%lld\n", ans);
}