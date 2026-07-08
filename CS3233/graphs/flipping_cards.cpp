#include <bits/stdc++.h>
using namespace std;
bool kuhn(int u, vector<vector<int>>& adj, vector<int>& matchR, vector<bool>& visited) {
    for (int i : adj[u]) {
        if (visited[i]) continue;
        visited[i] = true;
        if (matchR[i]==-1 || kuhn(matchR[i], adj, matchR, visited)) {
            matchR[i] = u;
            return true;
        }
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> arr(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        for (int i = 0; i<n; i++) {
            adj[i].push_back(arr[i].first+n);
            adj[i].push_back(arr[i].second+n);
        }
        vector<int> matchR(3*n+1, -1);
        int matchCount = 0;
        for (int i = 0; i<n; i++) {
            vector<bool> visited(3*n+1);
            if (kuhn(i, adj, matchR, visited)) {
                matchCount++;
            }
        }
        if (matchCount==n) printf("possible\n");
        else printf("impossible\n");
    }
}