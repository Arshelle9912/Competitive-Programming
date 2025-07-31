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

bool get(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    return u==v;
}

int main() {
    int n, m;
    cin >> n >> m;
    parent.resize(n+1);
    iota(parent.begin(), parent.end(), 0);
    rnk.assign(n+1, 0);
    for (int i = 0; i<m; i++) {
        string s;
        int x, y;
        cin >> s >> x >> y;
        if (s=="get") {
            if (get(x, y)) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        } else union_set(x,y);
    }
}