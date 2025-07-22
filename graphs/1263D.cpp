#include <bits/stdc++.h>
using namespace std;
void dfs(vector<set<int>>& adj, vector<int>& visited, int parent, int node) {
    visited[node] = true;
    for (int i : adj[node]) {
        if (i!=parent && !visited[i]) {
            dfs(adj, visited, node, i);
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<set<int>> adj(26);
    vector<int> count(26);
    for (int i = 0; i<n; i++) {
        string s;
        cin >> s;
        count[s[0]-'a']++;
        for (int i = 1; i<s.length(); i++) {
            adj[s[i-1]-'a'].insert(s[i]-'a');
            adj[s[i]-'a'].insert(s[i-1]-'a');
            count[s[i]-'a']++;
        }
    }
    vector<int> visited(26);
    int ans(0);
    for (int i = 0; i<26; i++) {
        if (!visited[i] && count[i]!=0) {
            ans++;
            dfs(adj, visited, -1, i);
        }
    }
    cout << ans << "\n";
}