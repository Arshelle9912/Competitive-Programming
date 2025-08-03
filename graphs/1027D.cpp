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
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    rnk.assign(n, 0);
    vector<int> costs(n);
    for (int i = 0; i<n; i++) {
        cin >> costs[i];
    }
    vector<int> nodes(n);
    for (int i = 0; i<n; i++) {
        cin >> nodes[i];
        nodes[i]--;
    }
    vector<int> state(n, 0);
    long long answer = 0;
    for (int i = 0; i<n; i++) {
        if (state[i]!=0) {
            continue;
        }
        int u = i;
        vector<int> path;
        while (state[u]==0) {
            state[u]=1;
            path.push_back(u);
            u = nodes[u];
        }
        if (state[u]==1) {
            int min_cost = INT_MAX;
            for (int j = path.size()-1; j>=0; j--) {
                min_cost = min(min_cost, costs[path[j]]);
                if (path[j]==u) break;
            }
            answer+=min_cost;
        }
        for (int v : path) {
            state[v] = 2;
        }
    }
    cout << answer << "\n";
}