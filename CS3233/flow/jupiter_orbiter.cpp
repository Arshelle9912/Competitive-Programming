#include <bits/stdc++.h>
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
    int n, q, s;
    cin >> n >> q >> s;
    vector<int> sensors(s);
    for (int i = 0; i<s; i++) {
        cin >> sensors[i];
    }
    vector<int> queueSize(q);
    for (int i = 0; i<q; i++) {
        cin >> queueSize[i];
    }
    int INF = 1e9;
    long long total = 0;
    int base = s + 2*q + 2;
    Dinic din = Dinic(base*n+2, 0, base*n+1);
    for (int i = 0; i<n; i++) {
        int d;
        cin >> d;
        vector<int> sensorSize(s);
        for (int j = 0; j<s; j++) {
            cin >> sensorSize[j];
            total+=sensorSize[j];
        }
        din.add_edge(0, base*i+1, INF);
        for (int j = 0; j<s; j++) {
            din.add_edge(base*i+1, (base)*i+j+2, INF);
            din.add_edge((base)*i+j+2, 2*(sensors[j]-1)+s+(base)*i+2, sensorSize[j]);
        }
        for (int j = 0; j<q; j++) {
            din.add_edge(s+2*j+2+(base)*i, (base)*i+s+2*j+3, queueSize[j]);
            din.add_edge(base*i+3+s+2*j, base*i+2+s+2*q, INF);
            if (i!=n-1) din.add_edge(base*i+3+s+2*j, base*(i+1)+2+s+2*j, queueSize[j]);
        }
        din.add_edge(base*i+2+s+2*q, base*n+1, d);
    }
    long long flow = din.flow();
    if (flow!=total) printf("impossible\n");
    else printf("possible\n");
}