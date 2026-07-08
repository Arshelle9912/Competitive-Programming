#include <bits/stdc++.h>
using namespace std;
class DSU {
public:
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i<n; i++) {
            parent[i] = i;
        }
    }
    int find (int x) {
        if (parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a==b) return;
        if (sz[a]<sz[b]) swap(a, b);
        parent[b] = a;
        sz[a]+=sz[b];
    }
    int size(int x) {
        return sz[find(x)];
    }
};