#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1);
    for (int i = 0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    vector<int> toposort;
    for (int i = 1; i<=n; i++) {
        if (indegree[i]==0) {
            q.push(i);
            toposort.push_back(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i : adj[node]) {
            indegree[i]--;
            if (indegree[i]==0) {
                q.push(i);
                toposort.push_back(i);
            }
        }
    }
    vector<int> dp(n+1, INT_MIN);
    vector<int> parent(n+1);
    dp[1] = 1;
    for (int i : toposort) {
        if (dp[i]<0) continue;
        for (int j : adj[i]) {
            if (dp[j]<dp[i]+1) {
                dp[j] = dp[i] + 1;
                parent[j] = i;
            }
        }
    }
    if (parent[n]==0) {
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    vector<int> ans;
    ans.push_back(n);
    int node = n;
    while (parent[node]!=1) {
        ans.push_back(parent[node]);
        node = parent[node];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << dp[n] << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
}