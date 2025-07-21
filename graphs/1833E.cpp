#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<set<int>> adj(n+1);
        for (int i = 1; i<=n; i++) {
            int temp;
            cin >> temp;
            adj[i].insert(temp);
            adj[temp].insert(i);
        }
        vector<char> visited(n+1, 0);
        int comp = 0;
        long long missing = 0;
        int path_comps = 0;
 
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                comp++;
                int temp = 0;
                queue<int> q;
                q.push(i);
                visited[i] = 1;
 
                while (!q.empty()) {
                    int u = q.front(); 
                    q.pop();
                    temp += 2 - adj[u].size();
                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = 1;
                            q.push(v);
                        }
                    }
                }
                missing += temp;
                if (temp > 0) path_comps++;
            }
        }
        int cycle_comps = comp - path_comps;
        int minimum  = cycle_comps + (path_comps > 0 ? 1 : 0);
        int maximum  = comp;
        cout << minimum << " " << maximum << "\n";
    }
}