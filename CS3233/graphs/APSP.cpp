#include <bits/stdc++.h>
using namespace std;
int main() {
    const long long INF = 4e18;
    while (true) {
        int n, m, q;
        cin >> n >> m >> q;
        if (n==0 && m==0 && q==0) break;
        vector<vector<long long>> dist(n, vector<long long>(n, INF));
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (int i = 0; i<m; i++) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            dist[u][v] = min(dist[u][v], w);
        }
        for (int k = 0; k<n; k++) {
            for (int i = 0; i<n; i++) {
                if (dist[i][k]==INF) continue;
                for (int j = 0; j<n; j++) {
                    if (dist[k][j] == INF) continue;
                    long long nd = dist[i][k] + dist[k][j];
                    dist[i][j] = min(dist[i][j], nd);
                }
            }
        }
        vector<vector<bool>> neg(n, vector<bool>(n, false));
        for (int k = 0; k < n; k++) {
            if (dist[k][k] < 0) {
                for (int i = 0; i < n; i++) {
                    if (dist[i][k] == INF) continue;
                    for (int j = 0; j < n; j++) {
                        if (dist[k][j] == INF) continue;
                        neg[i][j] = true;
                    }
                }
            }
        }
        while (q--) {
            int u, v;
            cin >> u >> v;
            if (dist[u][v] == INF) {
                cout << "Impossible\n";
            } else if (neg[u][v]) {
                cout << "-Infinity\n";
            } else {
                cout << dist[u][v] << '\n';
            }
        }
        cout << '\n';
    }
}