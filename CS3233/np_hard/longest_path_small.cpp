#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> vis;
int dfs(int u) {
    vis[u] = 1;
    int best = 0;
    for (int v : adj[u]) {
        if (!vis[v]) {
            best = max(best, 1+dfs(v));
        }
    }
    vis[u] = 0;
    return best;
}
int main() {
    scanf("%d\n", &n);
    scanf("%d\n", &m);
    int ans = 0;
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    vis.assign(n, 0);
    for (int s = 0; s<n; s++) {
        ans = max(ans, dfs(s));
    }
    printf("%d\n", ans);
}