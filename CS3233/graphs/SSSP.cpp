#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, q, s;
    while (cin >> n >> m >> q >> s) {
        if (n==0 && m==0 && q==0 && s==0) break;
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i<m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }
        int INF = 1e9;
        vector<int> dist(n, INF);
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            for (auto& [v, w] : adj[u]) {
                if (d>dist[u]) continue;
                if (dist[u]+w<dist[v]) {
                    dist[v] = dist[u]+w;
                    pq.push({dist[v], v});
                }
            }
        }
        for (int i = 0; i<q; i++) {
            int num;
            cin >> num;
            if (dist[num]==INF) {
                printf("Impossible\n");
                continue;
            }
            printf("%d\n", dist[num]);
        }
        printf("\n");
    }
}