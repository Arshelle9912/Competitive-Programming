#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, vector<vector<int>>& parents, int node, int parent, int LOG, vector<int>& depths) {
    parents[node][0] = parent;
    depths[node] = 1 + depths[parent];
    for (int i = 1; i<LOG; i++) {
        int mid = parents[node][i-1];
        parents[node][i] = mid ? parents[mid][i-1] : 0;
    }
    for (int u : adj[node]) {
        if (u!=parent) {
            dfs(adj, parents, u, node, LOG, depths);
        }
    }
}
void accumulate(int node, int parent, vector<vector<int>>& adj, vector<int>& counter) {
    for (int u : adj[node]) {
        if (u != parent) {
            accumulate(u, node, adj, counter);
            counter[node] += counter[u];
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 1; i<n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    int LOG = 1;
    while ((1<<LOG)<=n) {
        ++LOG;
    }
    vector<vector<int>> parents(n+1, vector<int> (LOG));
    vector<int> depths(n+1);
    depths[0] = -1;
    dfs(adj, parents, 1, 0, LOG, depths);
    auto lift = [&] (int u, int diff) {
        for (int i = 0; i<LOG; i++) {
            if (diff & (1<<i)) {
                u = parents[u][i];
            }
        }
        return u;
    };
    vector<int> counter(n + 1, 0);
    while (m--) {
        int a, b;
        cin >> a >> b;
        int org_a = a;
        int org_b = b;
        if (depths[a]<depths[b]) {
            swap(a, b);
        }
        a = lift(a, depths[a]-depths[b]);
        if (a==b) {
            counter[org_a] += 1;
            counter[org_b] += 1;
            counter[a] -= 1;
            if (parents[a][0]) counter[parents[a][0]] -= 1;
            continue;
        }
        for (int i = LOG-1; i>=0; i--) {
            if (parents[a][i]!=parents[b][i]) {
                a = parents[a][i];
                b = parents[b][i];
            }
        }
        int lca = parents[a][0];
        counter[org_a] += 1;
        counter[org_b] += 1;
        counter[lca] -= 1;
        if (parents[lca][0]) counter[parents[lca][0]] -= 1;
    }
    accumulate(1, 0, adj, counter);
    for (int i = 1; i <= n; i++) {
        cout << counter[i] << " ";
    }
    cout << "\n";
}