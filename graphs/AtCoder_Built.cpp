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
    int n;
    cin >> n;
    parent.resize(n+1);
    iota(parent.begin(), parent.end(), 0);
    rnk.resize(n);
    vector<tuple<int, int, int>> coords(n);
    vector<tuple<int, int, int>> oppcoords(n);
    for (int i = 0; i<n; i++) {
        int u, v;
        cin >> u >> v;
        coords[i] = {u, v, i};
        oppcoords[i] = {v, u, i};
    }
    sort(coords.begin(), coords.end());
    sort(oppcoords.begin(), oppcoords.end());
    vector<tuple<long long, int, int>> edgeList;
    auto [indcoord1, indcoord2, indcoord3] = coords[0];
    auto [indcoord4, indcoord5, indcoord6] = coords[1];
    auto [indopp1, indopp2, indopp3] = oppcoords[0];
    auto [indopp4, indopp5, indopp6] = oppcoords[1];
    edgeList.emplace_back(min(llabs(indcoord1-indcoord4), llabs(indcoord2-indcoord5)), indcoord3, indcoord6);
    edgeList.emplace_back(min(llabs(indopp1-indopp4), llabs(indopp2-indopp5)), indopp3, indopp6);
    for (int i = 1; i<n-1; i++) {
        auto [indcoord1, indcoord2, indcoord3] = coords[i];
        auto [indcoord4, indcoord5, indcoord6] = coords[i+1];
        auto [indopp1, indopp2, indopp3] = oppcoords[i];
        auto [indopp4, indopp5, indopp6] = oppcoords[i+1];
        edgeList.emplace_back(min(llabs(indcoord1-indcoord4), llabs(indcoord2-indcoord5)), indcoord3, indcoord6);
        edgeList.emplace_back(min(llabs(indopp1-indopp4), llabs(indopp2-indopp5)), indopp3, indopp6);
    }
    sort(edgeList.begin(), edgeList.end());
    long long ans(0);
    for (auto [w, u, v] : edgeList) {
        int fu = find_set(u);
        int fv = find_set(v);
        if (fu!=fv) {
            ans+=w;
            union_set(u, v);
        }
    }
    cout << ans << "\n";
}