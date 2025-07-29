#include <bits/stdc++.h>
using namespace std;
vector<int> parent, rnk;
const int MOD = 1e9 + 7;
int find_set(int u) {
    if (parent[u]!=u) {
        return parent[u] = find_set(parent[u]);
    }
    return parent[u];
}

void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u!=v) {
        if (rnk[u]<rnk[v]) {
            swap(u, v);
        }
        parent[v] = u;
        if (rnk[u]==rnk[v]) {
            rnk[u]++;
        }
    }
}

long long exponentiation(long long base, long long power) {
    long long result = 1;
    while (power>0) {
        if (power&1) {
            result = (result*base)%MOD;
        }
        base = (base*base)%MOD;
        power>>=1;
    }
    return result;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    parent.resize(n);
    rnk.assign(n, 0);
    iota(parent.begin(), parent.end(), 0);
    for (int start = 0; start<=n-k; start++) {
        for (int off = 0; off < k/2; off++) {
            int left = start+off;
            int right = start+k-1-off;
            union_sets(left, right);
        }
    }
    set<int> s;
    for (int i = 0; i<n; i++) {
        s.insert(find_set(i));
    }
    cout << exponentiation(m, s.size()) << "\n";
}