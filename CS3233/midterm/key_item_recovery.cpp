#include <bits/stdc++.h>
using namespace std;
void solve (const vector<int>& nodes, vector<vector<int>>& arr, vector<pair<int, int>>& edges) {
    if (nodes.size()<=1) return;
    int root = *min_element(nodes.begin(), nodes.end());
    vector<vector<int>> groups;
    for (int i : nodes) {
        if (i==root) continue;
        bool placed = false;
        for (auto &g : groups) {
            if (arr[i][g[0]]>root) {
                g.push_back(i);
                placed = true;
                break;
            }
        }
        if (!placed) groups.push_back({i});
    }
    for (auto& g : groups) {
        edges.push_back({root, g[0]});
        solve(g, arr, edges);
    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n+1, vector<int> (n+1));
    vector<pair<int, int>> edges;
    vector<int> all;
    for (int i = 1; i <= n; i++) all.push_back(i);
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            cin >> arr[i][j];
        }
    }
    solve(all, arr, edges);
    for (auto &[u, v] : edges) {
        cout << u << ' ' << v << '\n';
    }
}