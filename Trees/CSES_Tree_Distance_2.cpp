#include <bits/stdc++.h>
using namespace std;
void dfs1(vector<vector<long long>>& adj, vector<long long>& subtree, long long parent, long long node, vector<long long>& depths) {
    depths[node] = 1 + depths[parent];
    subtree[node] = 1;
    for (long long i : adj[node]) {
        if (i!=parent) {
            dfs1(adj, subtree, node, i, depths);
            subtree[node]+=subtree[i];
        }
    }
}
void dfs2(vector<vector<long long>>& adj, vector<long long>& subtree, long long parent, long long node, vector<long long>& ans, long long n) {
    for (long long i : adj[node]) {
        if (i!=parent) {
            ans[i] = ans[node] + n - 2*subtree[i];
            dfs2(adj, subtree, node, i, ans, n);
        }
    }
}
int main() {
    long long n;
    cin >> n;
    vector<vector<long long>> adj(n+1);
    for (long long i = 1; i<n; i++) {
        long long temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    vector<long long> depths(n+1);
    vector<long long> subtree(n+1);
    depths[0] = -1;
    dfs1(adj, subtree, 0, 1, depths);
    vector<long long> ans(n+1);
    for (long long i = 1; i<=n; i++) {
        ans[1] += depths[i];
    }
    dfs2(adj, subtree, -1, 1, ans, n);
    for (long long i = 1; i<=n; i++) {
        cout << ans[i] << " ";
    }
}