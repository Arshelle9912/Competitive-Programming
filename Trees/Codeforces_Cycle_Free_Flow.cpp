#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<pair<int, int>>>& adj, vector<vector<int>>& parents, vector<vector<int>>& minimum, vector<int>& depth, int parent, int node, int w) {
    depth[node] = 1+depth[parent];
    parents[node][0] = parent;
    minimum[node][0] = w;
    for (auto& i : adj[node]) {
        int to = i.first, wt = i.second;
        if (to!=parent) {
            dfs(adj, parents, minimum, depth, node, to, wt);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i<m; i++) {
        int temp1, temp2, w;
        cin >> temp1 >> temp2 >> w;
        adj[temp1].push_back({temp2, w});
        adj[temp2].push_back({temp1, w});
    }
    int LOG = 1;
    while ((1<<LOG)<=n) {
        ++LOG;
    }
    vector<vector<int>> parents(n+1, vector<int> (LOG));
    vector<int> depth(n+1);
    depth[0] = -1;
    vector<vector<int>> minimum(n+1, vector<int>(LOG, INT_MAX));
    dfs(adj, parents, minimum, depth, 0, 1, INT_MAX);
    for (int k = 1; k < LOG; k++) {
        for (int v = 1; v <= n; v++) {
            int mid = parents[v][k-1];
            parents[v][k] = parents[mid][k-1];
            minimum[v][k] = min(minimum[v][k-1],minimum[mid][k-1]);
        }
    }
    auto query = [&](int a, int b) {
        int ans = INT_MAX;
        if (depth[a] < depth[b]) swap(a,b);
        int diff = depth[a] - depth[b];
        for (int i = 0; i < LOG; i++) {
            if (diff & (1<<i)) {
                ans = min(ans, minimum[a][i]);
                a = parents[a][i];
            }
        }
        if (a == b) return ans;
        for (int i = LOG-1; i >= 0; i--) {
            if (parents[a][i] != parents[b][i]) {
                ans = min(ans, minimum[a][i]);
                ans = min(ans, minimum[b][i]);
                a = parents[a][i];
                b = parents[b][i];
            }
        }
        ans = min(ans, minimum[a][0]);
        ans = min(ans, minimum[b][0]);
        return ans;
    };
    int q; 
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query(a,b) << "\n";
    }
}