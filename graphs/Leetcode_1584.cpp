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

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    vector<tuple<long long, int, int>> edgeList;
    rnk.assign(n, 0);
    for (int i = 0; i<n; i++) {
        for (int j = i; j<n; j++) {
            if (i!=j) {
                long long dist = llabs(points[i][0]-points[j][0]) + llabs(points[i][1]-points[j][1]);
                edgeList.emplace_back(dist, i, j);
            }
        }
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
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int> (2));
    for (int i = 0; i<n; i++) {
        cin >> points[i][0] >> points[i][1];
    }
    cout << minCostConnectPoints(points) << "\n";
}