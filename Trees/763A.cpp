#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> p;
void dfs(vector<vector<int>>& adj, vector<int>& colors, int parent, int node) {
    for (int i : adj[node]) {
        if (i != parent) {
            if (colors[i-1]!=colors[node-1]) {
                p.push_back({node, i});
            }
            dfs(adj, colors, node, i);
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i<n-1; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    vector<int> colors(n);
    for (int i = 0; i<n; i++) {
        cin >> colors[i];
    }
    dfs(adj, colors, -1, 1);
    if (p.empty()) {
        cout << "YES" << "\n";
        cout << 1 << "\n";
        return 0;
    }
    set<int> check;
    check.insert(p[0].first);
    bool c = true;
    for (pair<int, int> pt : p) {
        if (check.find(pt.first)==check.end() && check.find(pt.second)==check.end()) {
            c = false;
            break;
        }
    }
    if (c) {
        cout << "YES" << "\n";
        cout << p[0].first << "\n";
        return 0;
    }
    check.clear();
    check.insert(p[0].second);
    c = true;
    for (pair<int, int> pt : p) {
        if (check.find(pt.first)==check.end() && check.find(pt.second)==check.end()) {
            c = false;
            break;
        }
    }
    if (c) {
        cout << "YES" << "\n";
        cout << p[0].second << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
}