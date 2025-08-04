#include <bits/stdc++.h>
using namespace std;
void dfs2(vector<vector<int>>& arr, int node, vector<bool>& visited, vector<int>& order) {
    visited[node] = true;
    for (int i : arr[node]) {
        if (!visited[i]) {
            dfs2(arr, i, visited, order);
        }
    }
    order.push_back(node);
}
int main() {
    int MOD = 1000000007;
    int n;
    cin >> n;
    vector<int> costs(n);
    for (int i = 0; i<n; i++) {
        cin >> costs[i];
    }
    int m;
    cin >> m;
    vector<vector<int>> adj(n+1);
    vector<vector<int>> rev(n+1);
    vector<int> indegree(n+1);
    for (int i = 0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
        indegree[v]++;
    }
    vector<int> toposort;
    vector<bool> visited1(n+1);
    for (int i = 1; i<=n; i++) {
        if (!visited1[i]) {
            dfs2(adj, i, visited1, toposort);
        }
    }
    reverse(toposort.begin(), toposort.end());
    vector<bool> visited(n+1);
    vector<vector<int>> scc;
    for (int i = 0; i<n; i++) {
        if (!visited[toposort[i]]) {
            vector<int> order;
            dfs2(rev, toposort[i], visited, order);
            scc.push_back(order);
        }
    }
    long long sum(0);
    vector<int> minCounts;
    for (vector<int> vec : scc) {
        long long minimum = LLONG_MAX;
        long long min_count = 0;
        for (int i : vec) {
            if (costs[i-1]<minimum) {
                minimum = costs[i-1];
                min_count = 1;
            } else if (costs[i-1]==minimum) {
                min_count++;
            }
        }
        sum+=minimum;
        minCounts.push_back(min_count);
    }
    cout << sum << " ";
    long long count = 1;
    for (int i : minCounts) {
        count = (count*i)%MOD;
    }
    cout << count << "\n";
}