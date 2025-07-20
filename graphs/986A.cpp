#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> items(n);
    for (int i = 0; i<n; i++) {
        cin >> items[i];
        items[i]--;
    }
    vector<vector<int>> adj(n+1);
    for (int i = 0; i<m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        temp1--;
        temp2--;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    vector<vector<int>> dist(n, vector<int>(k, 1e9));
    for (int t = 0; t < k; t++) {
        queue<int> q;
        vector<int> d(n, -1);
        for (int i = 0; i < n; i++) {
            if (items[i] == t) {
                q.push(i);
                d[i] = 0;
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            dist[i][t] = d[i];
        }
    }

    for (int i = 0; i < n; i++) {
        sort(dist[i].begin(), dist[i].end());
        int res = 0;
        for (int j = 0; j < s; j++) {
            res += dist[i][j];
        }
        cout << res << " ";
    }
    cout << "\n";
}