#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<vector<int>>& adj, vector<vector<int>>& parents, int LOG) {
    parents[0][node] = parent;
    for (int i = 1; i<LOG; i++) {
        int mid = parents[i-1][node];
        parents[i][node] = mid ? parents[i-1][mid] : 0;
    }
    for(int u : adj[node]) {
        if(u != parent) {
            dfs(u, node, adj, parents, LOG);
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
    while((1<<LOG) <= n) ++LOG;
    vector<vector<int>> parents(LOG, vector<int>(n+1, 0));
    dfs(1, 0, adj, parents, LOG);
    while(q--){
        int x, k;
        cin >> x >> k;
        for(int i = 0; i < LOG && x != 0; ++i){
            if(k & (1<<i)) {
                x = parents[i][x];
            }
        }
        cout << (x == 0 ? -1 : x) << "\n";
    }
}