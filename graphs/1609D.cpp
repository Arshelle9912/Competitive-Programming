#include <bits/stdc++.h>
using namespace std;
vector<int> parent, sz;
multiset<int> ms;
int find_set(int a) {
    if (parent[a]!=a) {
        return parent[a] = find_set(parent[a]);
    }
    return parent[a];
}
void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u!=v) {
        if (sz[u]<sz[v]) {
            swap(u, v);
        }
        parent[v] = u;
        ms.erase(ms.find(sz[u]));
        ms.erase(ms.find(sz[v]));
        sz[u]+=sz[v];
        sz[v] = sz[u];
        ms.insert(sz[u]);
    }
}
int main() {
    int n, d;
    cin >> n >> d;
    parent.resize(n, 0);
    sz.resize(n, 1);
    for (int i = 0; i<n; i++) {
        ms.insert(1);
    }
    int count = 0;
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i<d; i++) {
        int u, v;
        cin >> u >> v;
        --v;
        --u;
        int find_u = find_set(u);
        int find_v = find_set(v);
        if (find_u == find_v) {
            count++;
        } else {
            union_sets(find_u, find_v);
        }
        long long sum = 0;
        auto it = ms.rbegin();
        for (int i = 0; i < count+1 && it != ms.rend(); ++i, ++it) {
            sum += *it;
        }
        cout << sum-1 << "\n";
    }
}