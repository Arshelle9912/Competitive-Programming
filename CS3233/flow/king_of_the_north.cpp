#include <bits/stdc++.h>
using ll = long long;
using namespace std;
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {};
};
struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
    Dinic (int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m+1);
        m+=2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap==edges[id].flow) {
                    continue;
                }
                if (level[edges[id].u]!=-1) {
                    continue;
                }
                level[edges[id].u] = level[v]+1;
                q.push(edges[id].u);
            }
        }
        return level[t]!=-1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed==0) {
            return 0;
        }
        if (v==t) {
            return pushed;
        }
        for (int &cid = ptr[v]; cid<(int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v]+1!=level[u]) {
                continue;
            }
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr==0) {
                continue;
            }
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll> (m));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cin >> grid[i][j];
        }
    }
    pair<int, int> target;
    cin >> target.first >> target.second;
    Dinic din = Dinic(2*n*m+2, 0, 2*n*m+1);
    const long long INF = (long long)1e18;
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for (int i = 1; i<=m; i++) {
        din.add_edge(0, i*2-1, INF);
        din.add_edge(0, 2*(m*(n-1)+i)-1, INF);
    }
    for (int i = 2; i<n; i++) {
        din.add_edge(0, (i-1)*m*2+1, INF);
        din.add_edge(0, (i)*m*2-1, INF);
    }
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            int val = (i*m + j)*2+1;
            din.add_edge(val, val+1, grid[i][j]);
            for (int k = 0; k<4; k++) {
                int nI = dir[k].first+i;
                int nJ = dir[k].second+j;
                int nVal = (nI*m + nJ)*2+1; 
                if (nI>=n || nI<0 || nJ>=m || nJ<0) continue; 
                din.add_edge(val+1, nVal, INF);
            }
        }
    }
    int tarVal = (target.first*m + target.second)*2 + 1;
    din.add_edge(tarVal+1, 2*n*m+1, INF);
    printf("%lld\n", din.flow());
}