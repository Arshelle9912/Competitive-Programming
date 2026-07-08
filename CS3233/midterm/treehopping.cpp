#include <bits/stdc++.h>
using namespace std;
struct LCA {
    int n, LOG;
    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> adj;
    LCA(int n) : n(n) {
        LOG = 1;
        while ((1<<LOG)<=n) LOG++;
        adj.assign(n+1, {});
        up.assign(n+1, vector<int> (LOG, 0));
        depth.assign(n+1, 0);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void build (int root = 1) {
        vector<int> parent(n+1, 0);
        queue<int> q;
        q.push(root);
        parent[root] = root;
        depth[root] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            up[u][0] = parent[u];
            for (int j = 1; j<LOG; j++) {
                up[u][j] = up[up[u][j-1]][j-1];
            }
            for (int v : adj[u]) {
                if (v==parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u]+1;
                q.push(v);
            }
        }
    }
    int kthAncestor(int u, int k) {
        for (int j = 0; j<LOG; j++) {
            if (k&(1<<j)) {
                u = up[u][j];
            }
        }
        return u;
    }
    int lca (int a, int b) {
        if (depth[a]<depth[b]) swap(a, b);
        int diff = depth[a]-depth[b];
        a = kthAncestor(a, diff);
        if (a==b) return a;
        for (int j = LOG-1; j>=0; j--) {
            if (up[a][j]!=up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    }
    int dist(int a, int b) {
        int c = lca(a, b);
        return depth[a]+depth[b]-2*depth[c];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        LCA tree(n);
        for (int i = 0; i<n-1; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            tree.addEdge(n1, n2);
        }
        vector<int> permut(n);
        for (int i = 0; i<n; i++) {
            cin >> permut[i];
        }
        tree.build(1);
        bool checker = true;
        for (int i = 1; i<n; i++) {
            checker &= (tree.dist(permut[i-1], permut[i])<=3);
        }
        if (checker) printf("1\n");
        else printf("0\n");
    }
}