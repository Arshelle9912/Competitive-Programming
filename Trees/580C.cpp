#include <bits/stdc++.h>
using namespace std;
int dfs(int parent, vector<vector<int>>& adj, vector<int>& cats, int node, int m, int count) {
    if (cats[node]) {
        count++;
        if (count>m) {
            return 0;
        }
    } else {
        count = 0;
    }
    int ans(0);
    bool isleaf=true;
    for (int i : adj[node]) {
        if (i==parent) {
            continue;
        }
        isleaf=false;
        ans += dfs(node, adj, cats, i, m, count);
    }
    if (isleaf) {
        return 1;
    }
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cats(n+1);
    vector<vector<int>> adj(n+1);
    for (int i = 1; i<=n; i++) {
        cin >> cats[i];
    }
    for (int i = 0; i<n-1; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    cout << dfs(-1, adj, cats, 1, m, 0) << "\n";
}