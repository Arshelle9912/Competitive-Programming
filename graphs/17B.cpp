#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> skills(n);
    vector<vector<int>> adj(n+1);
    for (int i = 0; i<n; i++) {
        cin >> skills[i];
    }
    int m;
    cin >> m;
    vector<int> outgoing(n);
    for (int i = 0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (skills[u-1]>skills[v-1]) {
            adj[v].push_back(w);
            outgoing[v-1]++;
        }
    }
    int count(0);
    for (int i : outgoing) {
        if (i==0) {
            count++;
        }
    }
    if (count>1) {
        cout << -1 << "\n";
        return 0;
    }
    int ans(0);
    for (vector<int> vec : adj) {
        sort(vec.begin(), vec.end());
        if (!vec.empty()) {
            ans+=vec[0];
        }
    }
    cout << ans << "\n";
}