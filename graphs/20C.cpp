#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    for (int i = 0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<long long> dist(n+1, LLONG_MAX);
    vector<int> parent(n+1, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[1] = 0;
    pq.emplace(0, 1); 
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d>dist[u]) continue;
        for (auto [v,w] : adj[u]) {
            if (dist[v]>d+w) {
                dist[v] = d + w;
                parent[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }
    if (dist[n]==LLONG_MAX) {
        cout << "-1\n";
        return 0;
    }
    vector<int> path;
    for (int v = n; v!=-1; v=parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for(int x : path){
        cout << x << ' ';
    }
}