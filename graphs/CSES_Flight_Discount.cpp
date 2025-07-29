#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, int>>> adj(n+1);
    vector<vector<pair<ll, int>>> rev(n+1);
    vector<ll> dist1(n+1, LLONG_MAX);
    vector<ll> dist2(n+1, LLONG_MAX);
    vector<tuple<int,int,ll>> edges;
    edges.reserve(m);
    for (int i = 0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        rev[v].emplace_back(u, w);
        edges.emplace_back(u, v, w);
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq1;
    pq1.emplace(0, 1);
    dist1[1] = 0;
    while (!pq1.empty()) {
        auto [d, u] = pq1.top();
        pq1.pop();
        if (d>dist1[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist1[v]>dist1[u]+w) {
                dist1[v] = dist1[u]+w;
                pq1.emplace(dist1[v], v);
            }
        }
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq2;
    pq2.emplace(0, n);
    dist2[n] = 0;
    while (!pq2.empty()) {
        auto [d, u] = pq2.top();
        pq2.pop();
        if (d>dist2[u]) continue;
        for (auto [v, w] : rev[u]) {
            if (dist2[v]>dist2[u]+w) {
                dist2[v] = dist2[u]+w;
                pq2.emplace(dist2[v], v);
            }
        }
    }
    ll ans = LLONG_MAX;
    for (auto &[u,v,w] : edges) {
        if (dist1[u] == LLONG_MAX || dist2[v]==LLONG_MAX) continue;
        ll candidate = dist1[u] + w/2 + dist2[v];
        ans = min(ans, candidate);
    }
    cout << ans << "\n";
}