#include <bits/stdc++.h>
using namespace std;

int find_set(int u, vector<int>& parent) {
    if (parent[u]!=u) {
        return parent[u] = find_set(parent[u], parent);
    }
    return parent[u];
}

void union_set(int u, int v, vector<int>& parent, vector<int>& rnk) {
    u = find_set(u, parent);
    v = find_set(v, parent);
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
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> adj1(n+1);
    vector<vector<int>> adj2(n+1);
    vector<int> parent1(n+1);
    vector<int> parent2(n+1);
    iota(parent1.begin(), parent1.end(), 0);
    iota(parent2.begin(), parent2.end(), 0);
    vector<int> rnk1(n+1, 0);
    vector<int> rnk2(n+1, 0);
    for (int i = 0; i<m1; i++) {
        int u, v;
        cin >> u >> v;
        union_set(u,v, parent1, rnk1);
    }
    for (int i = 0; i<m2; i++) {
        int u, v;
        cin >> u >> v;
        union_set(u, v, parent2, rnk2);
    }
    vector<pair<int, int>> added;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (find_set(i, parent1) != find_set(j, parent1) && find_set(i, parent2) != find_set(j, parent2)) {
                added.emplace_back(i, j);
                union_set(i, j, parent1, rnk1);
                union_set(i, j, parent2, rnk2);
            }
        }
    }
    cout << added.size() << "\n";
    for (auto &p : added) {
        cout << p.first << " " << p.second << "\n";
    }
}