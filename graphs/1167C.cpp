#include <bits/stdc++.h>
using namespace std;
void dfs(vector<set<int>>& adj, vector<int>& components, int node, int parent, vector<int>& componentSize, vector<int>& visited, int c) {
    visited[node] = true;
    components[node] = c;
    componentSize[c]++;
    for (int i : adj[node]) {
        if (i!=parent && !visited[i]) {
            dfs(adj, components, i, node, componentSize, visited, c);
        }
    }
}
int main() {
    int n, g;
    cin >> n >> g;
    vector<set<int>> adj(n+1);
    for (int i = 0; i<g; i++) {
        int size;
        cin >> size;
        int temp1;
        if (size>0) cin >> temp1;
        for (int j = 1; j<size; j++) {
            int temp2;
            cin >> temp2;
            adj[temp1].insert(temp2);
            adj[temp2].insert(temp1);
            temp1 = temp2;
        }
    }
    vector<int> visited(n+1);
    vector<int> components(n+1);
    vector<int> componentSize(n+1);
    for (int i = 1; i<=n; i++) {
        if (!visited[i]) {
            dfs(adj, components, i, 0, componentSize, visited, i);
        }
    }
    for (int i = 1; i<=n; i++) {
        cout << componentSize[components[i]] << " ";
    }
}