#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> deg(n + 1);
        vector<int> depth(n + 1);
        vector<vector<int>> adj(n + 1);
        vector<pair<int, int>> edges;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges.emplace_back(u, v);
        }
        int node = -1;
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] == 2)
            {
                node = i;
                break;
            }
        }
        if (node == -1)
        {
            cout << "NO" << "\n";
            continue;
        }
        int a = adj[node][0];
        int b = adj[node][1];
        cout << "YES" << "\n";
        vector<pair<int, int>> ans;
        ans.emplace_back(node, a);
        ans.emplace_back(b, node);
        function<void(int, int, bool)> dfs = [&](int v, int p, bool in)
        {
            for (int to : adj[v])
            {
                if (to != p)
                {
                    if (in)
                        ans.emplace_back(to, v);
                    else
                        ans.emplace_back(v, to);
                    dfs(to, v, !in);
                }
            }
        };
        dfs(a, node, true);
        dfs(b, node, false);
        for (auto [u, v] : ans)
            cout << u << ' ' << v << '\n';
    }
}