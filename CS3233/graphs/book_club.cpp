#include <bits/stdc++.h>
using namespace std;
bool kuhn(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& matchR) {
    for (int v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;
        if (matchR[v] == -1 || kuhn(matchR[v], adj, visited, matchR)) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i<m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
    }
    vector<int> matchR(n, -1);
    int matchCount = 0;
    for (int i = 0; i<n; i++) {
        vector<bool> visited(n);
        if (kuhn(i, adj, visited, matchR)) {
            matchCount++;
        }
    }
    if (matchCount==n) printf("YES\n");
    else printf("NO\n");
}