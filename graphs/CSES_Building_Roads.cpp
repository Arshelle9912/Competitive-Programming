#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, vector<int>& visited, int node, int parent, int segment, vector<int>& component) {
    visited[node] = true;
    component[node] = segment;
    for (int i : adj[node]) {
        if (i!=parent && !visited[i]) {
            dfs(adj, visited, i, node, segment, component);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i<m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    vector<int> visited(n+1);
    vector<int> component(n+1);
    int count(0);
    for (int i = 1; i<=n; i++) {
        if (!visited[i]) {
            count++;
            dfs(adj, visited, i, 0, i, component);
        }
    }
    set<int> se;
    se.insert(component[1]);
    cout << count - 1 << "\n";
    int last = 1;
    for (int i = 2; i<=n; i++) {
        if (se.find(component[i])==se.end()) {
            cout << last << " " << i << "\n";
            last = i;
            se.insert(component[i]);
        }
    }
}