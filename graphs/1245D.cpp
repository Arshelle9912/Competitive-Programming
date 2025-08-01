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
    rnk.assign(n+1, 0);
    vector<int> cost(n+1);
    vector<pair<int, int>> coords(n+1);
    vector<int> ks(n+1);
    for (int i = 1; i<=n; i++) {
        cin >> coords[i].first >> coords[i].second;
    }
    for (int i = 1; i<=n; i++) {
        cin >> cost[i];
    }
    for (int i = 1; i<=n; i++) {
        cin >> ks[i];
    }
    vector<tuple<long long, int, int>> edgeList;
    for (int i = 1; i<=n; i++) {
        edgeList.emplace_back(cost[i], 0, i);
    }
    for (int i = 1; i<=n; i++) {
        for (int j = i+1; j<=n; j++) {
            if (i!=j) {
                long long dist = llabs(coords[i].first - coords[j].first) 
                + llabs(coords[i].second - coords[j].second);
                edgeList.emplace_back(dist*(ks[i]+ks[j]), i, j);
            }
        }
    }
    sort(edgeList.begin(), edgeList.end());
    vector<int> power;
    long long total = 0;
    vector<pair<int, int>> edges;
    for (auto [w, u, v]: edgeList) {
        int fu = find_set(u);
        int fv = find_set(v);
        if (fu!=fv) {
            total+=w;
            if (u==0) {
                power.push_back(v);
            } else {
                edges.push_back(make_pair(u, v));
            }
            union_set(u, v);
        }
    }
    cout << total << "\n";
    cout << power.size() << "\n";
    for (int i : power) {
        cout << i << " ";
    }
    cout << "\n";
    cout << edges.size() << "\n";
    for (pair<int, int> p : edges) {
        cout << p.first << " " << p.second << "\n";
    }
}