#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, w;
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i<m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    int INF = 1e9;
    vector<int> dist(n, INF);
    dist[0] = 0;
    for (int i = 1; i<=n-1; i++) {
        for (auto& e : edges) {
            if (dist[e.u]==INF) continue;
            if (dist[e.u]+e.w<dist[e.v]) {
                dist[e.v] = dist[e.u]+e.w;
            }
        }
    }
    
}