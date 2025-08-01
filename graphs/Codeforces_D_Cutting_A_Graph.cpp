#include <bits/stdc++.h>
using namespace std;
vector<int> parent, rnk;
int find_set(int u) {
    if (parent[u]!=u) {
        return parent[u] = find_set(parent[u]);
    }
    return parent[u];
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u!=v) {
        if (rnk[u]<rnk[v]) {
            parent[u] = v;
        } else {
            parent[v] = u;
        }
        if (rnk[u]==rnk[v]) {
            rnk[u]++;
        }
    }
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    parent.resize(n+1);
    iota(parent.begin(), parent.end(), 0);
    rnk.assign(n+1, 0);
    vector<vector<int>> adj(n+1);
    for (int i = 0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<tuple<string, int, int>> queries;
    for (int i = 0; i<k; i++) {
        string s;
        int n1, n2;
        cin >> s >> n1 >> n2;
        queries.emplace_back(s, n1, n2);
    }
    vector<string> ans;
    for (int i = k-1; i>=0; i--) {
        auto [s, n1, n2] = queries[i];
        if (s=="ask") {
            int find_n1 = find_set(n1);
            int find_n2 = find_set(n2);
            if (find_n1==find_n2) {
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            }
        } else {
            union_set(n1, n2);
        }
    }
    reverse(ans.begin(), ans.end());
    for (string s : ans) {
        cout << s << "\n";
    }
}