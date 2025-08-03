#include <bits/stdc++.h>
using namespace std;
void dfs1(vector<vector<int>>& rev, int node, vector<bool>& visited, vector<int>& res) {
    res.push_back(node);
    visited[node] = true;
    for (int i : rev[node]) {
        if (!visited[i]) {
            dfs1(rev, i, visited, res);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<vector<int>> rev(n+1);
    for (int i = 0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    auto toposort = [&] () -> vector<int> {
        vector<bool> visited(n+1, false);
        vector<int> order;
        auto dfs = [&] (auto self, int u) -> void {
            visited[u] = true;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    self(self, v);
                }
            }
            order.push_back(u);
        };
        for (int i = 1; i<=n; i++) {
            if (!visited[i]) {
                dfs(dfs, i);
            }
        }
        return order;
    };
    vector<int> sorted = toposort();
    reverse(sorted.begin(), sorted.end());
    vector<bool> visited(n+1);
    vector<vector<int>> scc;
    for (int i = 0; i<n; i++) {
        if (!visited[sorted[i]]) {
            vector<int> res;
            dfs1(rev, sorted[i], visited, res);
            scc.push_back(res);
        }
    }
    if (scc.size()>1) {
        cout << "NO" << "\n";
        cout << scc[1][0] << " " <<  scc[0][0];
    } else {
        cout << "YES" << "\n";
    }
}