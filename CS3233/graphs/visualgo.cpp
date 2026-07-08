#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    int INF = 1e9;
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int s, t;
    cin >> s >> t;
    dist[s] = 0;
    pq.push({0, s});
    vector<int> ways(n);
    ways[s] = 1;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        for (auto& [v, w] : adj[u]) {
            if (d!=dist[u]) continue;
            if (dist[u]+w<dist[v]) {
                dist[v] = dist[u]+w;
                ways[v] = ways[u];
                pq.push({dist[v], v});
            } else if (dist[u]+w==dist[v]) {
                ways[v]+=ways[u];
            }
        }
    }
    printf("%d\n", ways[t]);
}