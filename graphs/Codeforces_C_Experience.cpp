#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<long long> add;
vector<long long> delta;
int find_set(int u) {
    if (parent[u] == u) return u;
    int p = parent[u];
    int root = find_set(p);
    delta[u] += delta[p];
    parent[u] = root;
    return root;
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u == v) return;
    parent[u] = v;
    delta[u] = add[u] - add[v];
}
int main() {
    int n, m;
    cin >> n >> m;
    parent.resize(n+1);
    add.assign(n+1, 0);
    delta.assign(n+1, 0);
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i<m; i++) {
        string s;
        int n1, n2;
        cin >> s >> n1;
        if (s=="get") {
            int r = find_set(n1);
            cout << add[r] + delta[n1] << "\n";
        } else if (s=="add") {
            cin >> n2;
            int r = find_set(n1);
            add[r] += n2;
        } else {
            cin >> n2;
            union_set(n1, n2);
        }
    }
}