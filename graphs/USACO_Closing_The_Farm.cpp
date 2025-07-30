#include <bits/stdc++.h>
using namespace std;
vector<int> parents, sz;
int find_set(int u) {
    if (parents[u]!=u) {
        return parents[u] = find_set(parents[u]);
    }
    return parents[u];
}

void union_set(int a, int b) {
    int u = find_set(a);
    int v = find_set(b);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    parents[v] = u;
    sz[u] += sz[v];
}

int main() {
    freopen("closing.in",  "r", stdin);
    freopen("closing.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    sz.assign(n+1, 1);
    for (int i = 0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        --v;
        --u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> removals(n);
    for (int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        --temp;
        removals[i] = temp;
    }
    parents.resize(n+1);
    vector<string> result;
    result.push_back("YES");
    iota(parents.begin(), parents.end(), 0);
    set<int> se;
    se.insert(removals[n-1]);
    for (int i = n-2; i>=0; i--) {
        int u = removals[i];
        for (int j : adj[u]) {
            if (se.count(j)) {
                union_set(u, j);
            }
        }
        se.insert(u);
        if (sz[find_set(u)]==se.size()) {
            result.push_back("YES");
        } else {
            result.push_back("NO");
        }
    }
    reverse(result.begin(), result.end());
    for (string s : result) {
        cout << s << "\n";
    }
}