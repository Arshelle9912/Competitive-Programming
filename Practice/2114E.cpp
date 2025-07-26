#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<long long>>& adj, long long parent1, long long parent2, long long node, vector<long long>& arr, vector<long long>& ans) {
    if (parent2!=-1) {
        ans[node] = max(arr[node], arr[node]+ans[parent2]-arr[parent1]);
    } else {
        ans[node] = arr[node];
    }
    for (long long i : adj[node]) {
        if (i!=parent1) {
            dfs(adj, node, parent1, i, arr, ans);
        }
    }
}
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> arr(n+1);
        for (long long i = 1; i<=n; i++) {
            cin >> arr[i];
        }
        vector<vector<long long>> adj(n+1);
        for (long long i = 1; i<n; i++) {
            long long temp1, temp2;
            cin >> temp1 >> temp2;
            adj[temp1].push_back(temp2);
            adj[temp2].push_back(temp1);
        }
        vector<long long> ans(n+1);
        dfs(adj, -1, -1, 1, arr, ans);
        for (long long i = 1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}