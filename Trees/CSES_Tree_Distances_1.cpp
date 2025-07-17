#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, int parent, int node, vector<int>& dist) {
    dist[node] = dist[parent] + 1;
    for (int i : adj[node]) {
        if (i!=parent) {
            dfs(adj, node, i, dist);
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 1; i<n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    vector<int> dist1(n+1);
    vector<int> dist2(n+1);
    vector<int> dist3(n+1);
    dist1[0] = -1;
    dist2[0] = -1;
    dist3[0] = -1;
    dfs(adj, 0, 1, dist1);
    int deepest1;
    int maxDist1(-1);
    for (int i = 1; i<=n; i++) {
        if (dist1[i]>maxDist1) {
            maxDist1 = dist1[i];
            deepest1 = i;
        }
    }
    dfs(adj, 0, deepest1, dist2);
    int deepest2;
    int maxDist2(-1);
    for (int i = 1; i<=n; i++) {
        if (dist2[i]>maxDist2) {
            maxDist2 = dist2[i];
            deepest2 = i;
        }
    }
    dfs(adj, 0, deepest2, dist3);
    for (int i = 1; i<=n; i++) {
        cout << max(dist2[i], dist3[i]) << " ";
    }
}