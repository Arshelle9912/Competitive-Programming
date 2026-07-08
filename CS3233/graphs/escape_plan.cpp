#include <bits/stdc++.h>
using namespace std;
bool dfs(int u, vector<vector<int>>& adj, vector<int>& matchR, vector<int>& vis) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (matchR[v]==-1 || dfs(matchR[v], adj, matchR, vis)) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}
int matching(vector<vector<int>>& adj, int n, int m) {
    vector<int> matchR(n, -1);
    vector<int> vis;
    int ans = 0;
    for (int u = 0; u<m; u++) {
        vis.assign(n, 0);
        if (dfs(u, adj, matchR, vis)) ans++;
    }
    return ans;
}
int main() {
    int m, n;
    int count = 1;
    while (true) {
        cin >> m;
        if (m==0) break;
        vector<pair<double, double>> pos(m);
        for (int i = 0; i<m; i++) {
            cin >> pos[i].first >> pos[i].second;
        }
        cin >> n;
        vector<pair<double, double>> holes(n);
        for (int i = 0; i<n; i++) {
            cin >> holes[i].first >> holes[i].second;
        }
        vector<pair<int, double>> dist(n*m);
        vector<vector<int>> adj1(m);
        vector<vector<int>> adj2(m);
        vector<vector<int>> adj3(m);
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                double distance = (pos[i].first-holes[j].first)*(pos[i].first-holes[j].first) + (pos[i].second-holes[j].second)*(pos[i].second-holes[j].second);
                if (distance<=(2500)) {
                    adj1[i].push_back(j);
                }
                if (distance<=(10000)) {
                    adj2[i].push_back(j);
                }
                if (distance<=(40000)) {
                    adj3[i].push_back(j);
                }
            }
        }
        int ans1 = matching(adj1, n, m);
        int ans2 = matching(adj2, n, m);
        int ans3 = matching(adj3, n, m);
        printf("Scenario %d\n", count);
        printf("In 5 seconds %d robot(s) can escape\n", ans1);
        printf("In 10 seconds %d robot(s) can escape\n", ans2);
        printf("In 20 seconds %d robot(s) can escape\n\n", ans3);
        count++;
    }
}