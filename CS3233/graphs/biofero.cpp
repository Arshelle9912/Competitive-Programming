#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> matchR, vis; 
bool dfs(int u) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (matchR[v]==-1 || dfs(matchR[v])) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}
int maxMatching() {
    matchR.assign(n+1, -1);
    int ans = 0;
    for (int u = 0; u<n; u++) {
        vis.assign(n+1, 0);
        if (dfs(u)) ans++;
    }
    return ans;
}
int main() {
    cin >> n;
    adj.assign(n, {});
    for (int i = 0; i<n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j<k; j++) {
            int num;
            cin >> num;
            adj[i].push_back(num);
        }
    }
    maxMatching();
    for (int i = 1; i<=n; i++) {
        if (matchR[i]==-1) {
            printf("Neibb\n");
            return 0;
        }
    }
    for (int i = 1; i<=n; i++) {
        printf("%d ", matchR[i]+1);
    }
}