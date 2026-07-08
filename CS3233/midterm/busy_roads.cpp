#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<tuple<long long, long long, long long, long long>>> adj(n+1);
    for (int i = 0; i<m; i++) {
        long long ai, bi, ti, li, ri;
        cin >> ai >> bi >> ti >> li >> ri;
        adj[ai].push_back({bi, ti, li, ri});
        adj[bi].push_back({ai, ti, li, ri});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});
    long long INF = 1e17;
    vector<long long> dist(n+1, INF);
    dist[1] = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        long long d = top.first;
        int u = top.second;
        long long curr = dist[u]%c;
        long long wait;
        pq.pop();
        for (auto& [bi, ti, li, ri] : adj[u]) {
            if (li<=curr && curr<=ri) wait = 0;
            else if (curr<li) wait = li-curr;
            else wait = (c-curr)+li;
            long long d = dist[u] + wait + ti;
            if (d<dist[bi]) {
                dist[bi] = d;
                pq.push({dist[bi], bi});
            }
        }
    }
    printf("%lld\n", dist[n]);
}