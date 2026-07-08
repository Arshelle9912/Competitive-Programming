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
    int n, f, r;
    cin >> n >> f >> r;
    int c, m, ind, o;
    cin >> c >> m >> ind >> o;
    Dinic din = Dinic(5*f+2+n, 0, 5*f+n+1);
    auto id1 = [&] (char race, int fl) {
        if (race=='C') {
            return (fl-1)*4+1+n;
        } else if (race=='M') {
            return (fl-1)*4+2+n;
        } else if (race=='I') {
            return (fl-1)*4+3+n;
        } else {
            return (fl-1)*4+4+n;
        }
    };
    auto id2 = [&] (int floor) {
        return floor+f*4+n;
    };
    for (int i = 0; i<n; i++) {
        char race;
        cin >> race;
        int preference;
        cin >> preference;
        din.add_edge(0, i+1, 1);
        for (int j = 0; j<preference; j++) {
            int floor;
            cin >> floor;
            if (race=='C') {
                // printf("%d %d\n", i+1, id1('C', floor));
                din.add_edge(i+1, id1('C', floor), 1);
            } else if (race=='M') {
                din.add_edge(i+1, id1('M', floor), 1);
            } else if (race=='I') {
                din.add_edge(i+1, id1('I', floor), 1);
            } else if (race=='O') {
                din.add_edge(i+1, id1('O', floor), 1);
            } 
        }
    }
    for (int i = 1; i<=4*f; i+=4) {
        din.add_edge(i+n, id2((i-1)/4+1), c);
        din.add_edge(i+n+1, id2((i-1)/4+1), m);
        din.add_edge(i+n+2, id2((i-1)/4+1), ind);
        din.add_edge(i+n+3, id2((i-1)/4+1), o);
    }
    for (int i = 1; i<=f; i++) {
        // printf("%d\n", id2(i));
        din.add_edge(id2(i), 5*f+n+1, r);
    }
    printf("%lld\n", din.flow());
}