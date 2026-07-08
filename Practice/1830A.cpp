#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void dfs(vector<vector<pair<int, int>>>& adj, int node, int parent, int val, int edgeind) {
    ans = max(val, ans);
    for (auto [v, ind] : adj[node]) {
        if (v==parent) continue;
        if (ind<edgeind) dfs(adj, v, node, val+1, ind);
        else dfs(adj, v, node, val, ind);
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i<n-1; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            adj[x].push_back({y, i});
            adj[y].push_back({x, i});
        }
        dfs(adj, 0, -1, 0, INT_MAX);
        cout << ans << "\n";
        ans = 0;
    }
}