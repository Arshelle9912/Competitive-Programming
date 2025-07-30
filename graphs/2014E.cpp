#include <bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<pair<int, int>>>& adj, vector<long long>& dist, int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(0, start);
    dist[start] = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d>dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v]>dist[u]+w) {
                dist[v] = dist[u]+w;
                pq.emplace(dist[v], v);
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> horses(h);
        for (int i = 0; i<h; i++) {
            cin >> horses[i];
        }
        vector<vector<pair<int, int>>> adj(2*n+1);
        for (int i = 0; i<m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[u+n].push_back(make_pair(v+n, w/2));
            adj[u+n].push_back(make_pair(u, 0));
            adj[v].push_back(make_pair(u, w));
            adj[v+n].push_back(make_pair(u+n, w/2));
            adj[v+n].push_back(make_pair(v, 0));
        }
        for (int i : horses) {
            adj[i].push_back(make_pair(i+n, 0));
        }
        vector<long long> dist1(2*n+1, LLONG_MAX);
        vector<long long> dist2(2*n+1, LLONG_MAX);
        dijkstra(adj, dist1, 1);
        dijkstra(adj, dist2, n);
        if (dist1[n]==LLONG_MAX) {
            cout << "-1\n";
            continue;
        }
        long long ans = LLONG_MAX;
        for (int i = 1; i<=n; i++) {
            ans = min(ans, max(dist1[i], dist2[i]));
        }
        cout << ans << "\n";
    }
}