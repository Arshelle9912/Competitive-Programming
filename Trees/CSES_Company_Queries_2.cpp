#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, vector<vector<int>>& parents, int node, int parent, int LOG, vector<int>& depths) {
    parents[0][node] = parent;
    depths[node] = 1 + depths[parent];
    for (int i = 1; i<LOG; i++) {
        int mid = parents[i-1][node];
        parents[i][node] = mid ? parents[i-1][mid] : 0;
    }
    for (int u : adj[node]) {
        if (u!=parent) {
            dfs(adj, parents, u, node, LOG, depths);
        }
    }
}
int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n+1);
    for (int i = 2; i<=n; i++) {
        int temp;
        cin >> temp;
        adj[temp].push_back(i);
    }
    int LOG = 1;
    while ((1<<LOG) <=n) {
        ++LOG;
    }
    vector<vector<int>> parents(LOG, vector<int> (n+1));
    vector<int> depths(n+1);
    depths[0] = -1;
    dfs(adj, parents, 1, 0, LOG, depths);
    auto lift = [&] (int u, int diff) {
        for (int i = 0; i<LOG; i++) {
            if (diff & (1<<i)) {
                u = parents[i][u];
            }
        }
        return u;
    };
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (depths[a]<depths[b]) {
            swap(a, b);
        }
        a = lift(a, depths[a]-depths[b]);
        if (a==b) {
            cout << a << "\n";
            continue;
        }
        for (int i = LOG-1; i>=0; i--) {
            if (parents[i][a]!=parents[i][b]) {
                a = parents[i][a];
                b = parents[i][b];
            }
        }
        cout << parents[0][a] << "\n";
    }
}