#include <bits/stdc++.h>
using namespace std;
void dfs1(vector<vector<long long>>& adj, vector<long long>& subtreeCost, vector<long long>& depth, long long node, long long parent, vector<long long>& ai) {
    subtreeCost[node] = ai[node];
    depth[node] = depth[parent]+1;
    for (long long i : adj[node]) {
        if (i!=parent) {
            dfs1(adj, subtreeCost, depth, i, node, ai);
            subtreeCost[node] += (subtreeCost[i]);
        }
    }
}
void dfs2(vector<vector<long long>>& adj, vector<long long>& subtreeCost, long long node, long long parent, vector<long long>& ans, long long cost) {
    for (long long i : adj[node]) {
        if (i!=parent) {
            ans[i] = ans[node] + cost - 2*subtreeCost[i];
            dfs2(adj, subtreeCost, i, node, ans, cost);
        }
    }
}
int main() {
    long long n;
    cin >> n;
    vector<long long> ai(n+1);
    long long cost = 0;
    for (long long i = 1; i<=n; i++) {
        cin >> ai[i];
        cost+=ai[i];
    }
    vector<vector<long long>> adj(n+1);
    for (long long i = 1; i<n; i++) {
        long long temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    vector<long long> subtreeCost(n+1);
    vector<long long> depth(n+1);
    depth[0] = -1;
    dfs1(adj, subtreeCost, depth, 1, 0, ai);
    vector<long long> ans(n+1);
    for (long long i = 1; i<=n; i++) {
        ans[1] += ai[i] * depth[i];
    }
    dfs2(adj, subtreeCost, 1, 0, ans, cost);
    long long result = 0;
    for (long long i : ans) {
        result = max(result, i);
    }
    cout << result << "\n";
}