#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int src) {
    int V = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);
    dist[src] = 0;
    pq.emplace(0, src);
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int d = top.first;  
        int u = top.second; 
        if (d > dist[u])
            continue;
        for (auto &p : adj[u]) {
            int v = p.first; 
            int w = p.second; 
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;   
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}
int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> times(n);
    for (int i = 0; i<n; i++) {
        cin >> times[i];
    }
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i<m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--;
        v--;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    vector<vector<int>> dist(n);
    for (int i = 0; i<n; i++) {
        dist[i] = dijkstra(adj, i);
    }
    vector<vector<int>> dp(1<<n, vector<int> (n, 1e9));
    dp[1][0] = 0;
    for (int mask = 1; mask<(1<<n); mask++) {
        for (int u = 0; u<n; u++) {
            if (dp[mask][u]==1e9) continue;
            for (int v = 0; v<n; v++) {
                if (mask&(1<<v)) continue;
                if (dist[u][v] == 1e9) continue;
                int nmask = mask|(1<<v);
                dp[nmask][v] = min(dp[nmask][v], dp[mask][u]+dist[u][v]);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i<n; i++) {
        ans = min(dp[(1<<n)-1][i], ans);
    }
    sort(times.begin(), times.end());
    for (int i = 0; i<times.size()-s; i++) {
        ans+=times[i];
    }
    printf("%d\n", ans);
}