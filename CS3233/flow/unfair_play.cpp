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
    int n, m;
    while (cin >> n) {
        if (n==-1) break;
        cin >> m;
        vector<int> points(n);
        for (int i = 0; i<n; i++) {
            cin >> points[i];
        }
        vector<pair<int, int>> games;
        Dinic din = Dinic(m+n+2, 0, m+n+1);
        vector<int> remGames(m);
        int total = 0;
        map<int, int> mp;
        for (int i = 0; i<m; i++) {
            int num1, num2;
            cin >> num1 >> num2;
            --num1;
            --num2;
            if (num1==n-1 || num2==n-1) {
                points[n-1]+=2;
                remGames[i] = (num1==n-1 ? 0 : 2);
                continue;
            };
            total+=2;
            games.push_back({num1, num2});
            din.add_edge(0, i+1, 2);
            int indA = din.m;
            din.add_edge(i+1, num1+m+1, 2);
            mp[i] = indA;
            din.add_edge(i+1, num2+m+1, 2);
        }
        bool ok = true;
        for (int i = 0; i<n-1; i++) {
            long long cap = points[n-1]-1-points[i];
            if (cap < 0) { 
                printf("NO\n"); 
                ok = false;
                goto nextcase;
            }
            din.add_edge(1+m+i, m+n+1, cap);
        }
        nextcase:
        if (!ok) continue;
        int flow = din.flow();
        if (total!=flow) {
            printf("NO\n");
            continue;
        }
        for (int i = 0; i<m; i++) {
            if (!mp.count(i)) continue;
            int edgeInd = mp[i];
            if (din.edges[edgeInd].flow==0) {
                remGames[i] = 2;
            } else if (din.edges[edgeInd].flow==1) {
                remGames[i] = 1;
            } else {
                remGames[i] = 0;
            }
        }
        for (int i = 0; i<m; i++) {
            printf("%d ", remGames[i]);
        }
        printf("\n");
    }
}