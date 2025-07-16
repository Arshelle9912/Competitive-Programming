#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, vector<vector<int>>& parents, vector<int>& depth, int node, int parent, int LOG) {
    depth[node] = 1+depth[parent];
    parents[node][0] = parent;
    for (int i = 1; i<LOG; i++) {
        int mid = parents[node][i-1];
        parents[node][i] = mid ? parents[mid][i-1] : 0;
    }
    for (int i : adj[node]) {
        if (i!=parent) {
            dfs(adj, parents, depth, i, node, LOG);
        } 
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n+1);
    int LOG = 1;
    while ((1<<LOG) <= n) {
        ++LOG;
    }
    vector<vector<int>> parents(n+1, vector<int> (LOG));
    vector<int> depth(n+1);
    for (int i = 1; i<n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    depth[0] = -1;
    dfs(adj, parents, depth, 1, 0, LOG);
    auto lift = [&] (int u, int diff) {
        for (int i = 0; i<LOG; i++) {
            if (diff & (1<<i)) {
                u = parents[u][i];
            }
        }
        return u;
    };
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (depth[a]<depth[b]) {
            swap(a, b);
        }
        int diff = depth[a] - depth[b];
        int dep = depth[b];
        a = lift(a, diff);
        if (a == b) {
            cout << diff << "\n";
            continue;
        }
        for (int i = LOG-1; i>=0; i--) {
            if (parents[a][i]!=parents[b][i]) {
                a = parents[a][i];
                b = parents[b][i];
            }
        }
        int LCA = parents[a][0];
        cout << dep*2 + diff - 2*depth[LCA] << "\n";
    }
}