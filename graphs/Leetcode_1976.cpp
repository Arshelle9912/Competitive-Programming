#include <bits/stdc++.h>
using namespace std;
int countPaths(int n, vector<vector<int>>& roads) {
    int MOD = 1000000007;
    vector<long long> dist(n, LLONG_MAX);
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i<roads.size(); i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        int w = roads[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<long long> count(n);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(0, 0);
    dist[0] = 0;
    count[0] = 1;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d>dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > w + dist[u]) {
                dist[v] = w + dist[u];
                count[v] = count[u];
                pq.emplace(dist[v], v);
            } else if (dist[v]==w+dist[u]) {
                count[v] = (count[v]+count[u])%MOD;
            }
        }
    }
    return count[n-1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(m, vector<int> (3));
    for (int i = 0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[i][0] = u;
        dist[i][1] = v;
        dist[i][2] = w;
    }
    cout << countPaths(n, dist) << "\n";
}