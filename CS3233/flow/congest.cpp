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

struct Road {
    int a, b;
    long long w;
};

struct DirEdge {
    int u, v;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<Road> roads;
    roads.reserve(m);
    vector<vector<pair<int,long long>>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        roads.push_back({a, b, w});
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    vector<int> starts(k);
    for (int i = 0; i < k; i++) cin >> starts[i];

    const long long INF = (long long)4e18;
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    vector<DirEdge> sp_edges;
    sp_edges.reserve(2 * m);
    for (auto &r : roads) {
        int a = r.a, b = r.b;
        long long w = r.w;
        if (dist[a] == dist[b] + w) sp_edges.push_back({a, b});
        if (dist[b] == dist[a] + w) sp_edges.push_back({b, a});
    }

    vector<int> cntAtNode(n + 1, 0);
    for (int s : starts) cntAtNode[s]++;

    map<long long, vector<pair<int,int>>> groups;
    for (int u = 1; u <= n; u++) {
        if (cntAtNode[u] > 0) {
            groups[dist[u]].push_back({u, cntAtNode[u]});
        }
    }

    long long answer = 0;
    const long long BIG = (long long)1e18;

    for (auto &entry : groups) {
        long long T = entry.first;
        auto &startsInGroup = entry.second;

        vector<int> id(n + 1, -1);
        int nextId = 0;
        int SRC = nextId++;
        for (int u = 1; u <= n; u++) {
            if (dist[u] <= T) id[u] = nextId++;
        }
        int SNK = nextId++;

        Dinic din(nextId, SRC, SNK);

        for (auto &[u, cnt] : startsInGroup) {
            din.add_edge(SRC, id[u], cnt);
        }

        din.add_edge(id[1], SNK, BIG);

        for (auto &e : sp_edges) {
            int u = e.u, v = e.v;
            if (dist[u] <= T && dist[v] <= T) {
                din.add_edge(id[u], id[v], 1);
            }
        }

        answer += din.flow();
    }

    cout << answer << "\n";
    return 0;
}