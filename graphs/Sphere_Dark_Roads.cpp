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
    int n, m;
    while (cin >> n >> m) {
        if (n==0 && m==0) {
            break;
        }
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rnk.assign(n, 0);
        vector<tuple<long long, int, int>> edgeList;
        long long totalCost(0);
        for (int i = 0; i<m; i++) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            totalCost+=w;
            edgeList.emplace_back(w, u, v);
        }
        long long savedCost(0);
        sort(edgeList.begin(), edgeList.end());
        for (auto [w, u, v] : edgeList) {
            int fu = find_set(u);
            int fv = find_set(v);
            if (fu!=fv) {
                savedCost+=w;
                union_set(u, v);
            }
        }
        cout << totalCost - savedCost << "\n";
    }
}