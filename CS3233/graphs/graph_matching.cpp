#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> matchR, vis; 
bool dfs(int u) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (matchR[v]==-1 || dfs(matchR[v])) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}
int maxMatching() {
    matchR.assign(m+1, -1);
    int ans = 0;
    for (int u = 1; u<=n; u++) {
        vis.assign(m+1, 0);
        if (dfs(u)) ans++;
    }
    return ans;
}
int main() {
    cin >> n >> m;
    adj.assign(n+1, {});
    int e;
    cin >> e;
    while (e--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << maxMatching() << "\n";
}