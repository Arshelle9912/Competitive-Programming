#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, flower, bee;
    cin >> n >> flower >> bee;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i<n-1; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    vector<int> parent(n+1, -1);
    queue<int> q;
    q.push(flower);
    parent[flower] = 0;
    while (!q.empty() && parent[bee] == -1) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (parent[v] == -1) {
                parent[v] = u;
                q.push(v);
            }
        }
    }
    vector<int> path;
    for (int cur = bee; cur != 0; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    int a = path[1];  
    int b = path[path.size()-2];
    auto dfs = [&](int start, int forbid)-> long long {
        long long cnt = 0;
        stack<pair<int,int>> st;
        st.push({start, 0});
        while (!st.empty()) {
            auto [u, p] = st.top();
            st.pop();
            cnt++;
            for (int v : adj[u]) {
                if (v == p || v == forbid) continue;
                st.push({v, u});
            }
        }
        return cnt;
    };
    long long Sx = dfs(flower, a);
    long long Sy = dfs(bee, b);
    long long total = (long long)n * (n - 1);
    long long forbidden = Sx * Sy;
    cout << (total - forbidden) << "\n";

    return 0;
}