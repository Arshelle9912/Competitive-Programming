#include <bits/stdc++.h>
using namespace std;
void dfs1(vector<vector<int>>& adj, vector<int>& subtreeValue, int node, int parent, vector<int>& colors) {
    subtreeValue[node] = colors[node];
    for (int i : adj[node]) {
        if (i!=parent) {
            dfs1(adj, subtreeValue, i, node, colors);
            subtreeValue[node] += max(subtreeValue[i], 0);
        }
    }
}
void dfs2(vector<vector<int>>& adj, vector<int>& subtreeValue, vector<int>& ans, int node, int parent) {
    for (int i : adj[node]) {
        if (i!=parent) {
            ans[i] = subtreeValue[i] + max(0, ans[node] - max(0, subtreeValue[i]));
            dfs2(adj, subtreeValue, ans, i, node);
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> colors(n+1);
    for (int i = 1; i<=n; i++) {
        int temp;
        cin >> temp;
        temp = temp ? 1 : -1;
        colors[i] = temp;
    }
    vector<vector<int>> adj(n+1);
    for (int i = 1; i<n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    vector<int> subtreeValue(n+1);
    dfs1(adj, subtreeValue, 1, 0, colors);
    vector<int> ans(n+1);
    ans[1] = subtreeValue[1];
    dfs2(adj, subtreeValue, ans, 1, 0);
    for (int i = 1; i<=n; i++) {
        cout << ans[i] << " ";
    }
}