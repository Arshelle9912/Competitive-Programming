#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, int node, int parent, vector<int>& ans) {
    int count = 0;
    for (int i : adj[node]) {
        if (i!=parent) {
            dfs(adj, i, node, ans);
            count++;
        }
    }
    if(count == 0) {
        ans.push_back(node);
    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> degree(n+1);
    for (int i = 0; i<n-1; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
        degree[temp1]++;
        degree[temp2]++;
    }
    int count(0);
    int root;
    for (int i = 1; i<=n; i++) {
        if (degree[i]>=3) {
            count++;
            root = i;
        }
    }
    if (count>=2) {
        cout << "No" << "\n";
        return 0;
    }
    cout << "Yes" << "\n";
    if (count==1) {
        vector<int> ans;
        dfs(adj, root, -1, ans);
        cout << ans.size() << "\n";
        for (int i : ans) {
            cout << root << " " << i << "\n";
        }
    } else {
        cout << 1 << "\n";
        for (int i = 1; i<=n; i++) {
            if (degree[i]==1) {
                cout << i << " ";
            }
        }
    }
}