#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>>& adj, vector<int>& ans, int parent, int node, set<pair<int, int>>& check) {
    int count(0);
    for (int i : adj[node]) {
        if (i!=parent) {
            count += dfs(adj, ans, node, i, check);
        }
    }
    pair<int, int> p = {parent, node};
    if (check.find(p)!=check.end() && count==0) {
        ans.push_back(node);
        count++;
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    set<pair<int,int>> check;
    for (int i = 0; i<n-1; i++) {
        int temp1, temp2, bad;
        cin >> temp1 >> temp2 >> bad;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
        if (bad==2) {
            check.insert({temp1, temp2});
            check.insert({temp2, temp1});
        }
    }
    vector<int> ans;
    cout << dfs(adj, ans, -1, 1, check) << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
}