#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>>& adj, vector<bool>& visited, int node, int parent) {
    visited[node] = true;
    int count = 1;
    for (int i : adj[node]) {
        if (i!=parent && !visited[i]) {
            count += dfs(adj, visited, i, node);
        }
    }
    return count;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> govt(k);
    for (int i = 0; i<k; i++) {
        cin >> govt[i];
    }
    vector<vector<int>> adj(n+1);
    for (int i = 0; i<m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    vector<bool> visited(n+1);
    vector<int> componentSize(k);
    int maximum = 0;
    int maxIndex = 0;
    for (int i = 0; i<k; i++) {
        componentSize[i] = dfs(adj, visited, govt[i], 0);
        if (componentSize[i]>maximum) {
            maximum = componentSize[i];
            maxIndex = i;
        }
    }
    int unvisited = 0;
    for (int i = 1; i<=n; i++) {
        if (!visited[i]) {
            unvisited++;
        }
    }
    componentSize[maxIndex]+=unvisited;
    int ans = 0;
    for (int i = 0; i<k; i++) {
        ans += (componentSize[i]*(componentSize[i]-1))/2;
    }
    cout << ans - m << "\n";
}