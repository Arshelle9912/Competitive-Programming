#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<long long> dp(n+1);
    vector<int> indegree(n+1);
    dp[1] = 1;
    for (int i = 0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for (int i = 1; i<=n; i++) {
        if (indegree[i]==0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i : adj[node]) {
            dp[i] = (dp[i]+dp[node])%MOD;
            indegree[i]--;
            if (indegree[i]==0) {
                q.push(i);
            }
        }
    }
    cout << dp[n] << "\n";
}