#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indeg(n);
    for (int i = 0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    vector<int> toposort;
    for (int i = 0; i<n; i++) {
        if (indeg[i]==0) q.push(i);
    }
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        toposort.push_back(front);
        for (int v : adj[front]) {
            indeg[v]--;
            if (indeg[v]==0) {
                q.push(v);
            }
        }
    }
    vector<int> dp(n, 0);
    for (int u : toposort) {
        for (int v : adj[u]) {
            dp[v] = max(dp[v], 1+dp[u]);
        }
    }
    int ans = 0;
    for (int i = 0; i<n; i++) {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}