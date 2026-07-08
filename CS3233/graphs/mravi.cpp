#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int v, perc, p;
};
double dfs(vector<vector<Edge>>& adj, vector<int>& need, int parent, int curr) {
    bool hasChild = false;
    double total = 0;
    double reqAtCurr = 0.0;
    for (auto e : adj[curr]) {
        if (e.v!=parent) {
            hasChild = true;
            double childNeed = dfs(adj, need, curr, e.v);
            double normal = childNeed*100/e.perc;
            double contrib = normal;
            if (e.p==1) {
                double superOn = sqrt(childNeed) * 100.0 / e.perc;
                contrib = min(superOn, contrib);
            }
            reqAtCurr = max(reqAtCurr, contrib);
        }
    }
    if (!hasChild) return (double) need[curr];
    return reqAtCurr;
}
int main() {
    int n;
    cin >> n;
    vector<vector<Edge>> adj(n+1);
    for (int i = 0; i<n-1; i++) {
        int a, b, perc, p;
        cin >> a >> b >> perc >> p;
        adj[a].push_back({b, perc, p});
        adj[b].push_back({a, perc, p});
    }
    vector<int> need(n+1);
    for (int i = 1; i<=n; i++) {
        cin >> need[i];
    }
    printf("%.8f", dfs(adj, need, -1, 1));
}