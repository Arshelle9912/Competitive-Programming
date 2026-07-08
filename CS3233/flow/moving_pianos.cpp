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
    int t;
    cin >> t;
    while (t--) {
        int pianos, workers;
        cin >> pianos >> workers;
        int capacity = workers/2;
        int maxDay = 0;
        vector<pair<int, int>> days(pianos);
        for (int i = 0; i<pianos; i++) {
            cin >> days[i].first >> days[i].second;
            maxDay = max(maxDay, days[i].second);
        }
        Dinic din1 = Dinic(2+pianos+maxDay, 0, pianos+maxDay+1);
        for (int i = 0; i<pianos; i++) {
            din1.add_edge(0, i+1, 1);
            for (int j = days[i].first; j<=days[i].second; j++) {
                if ((j-6)%7==0 || (j%7)==0) continue;
                din1.add_edge(i+1, pianos+j, 1);
            }
        }
        for (int i = 1; i<=maxDay; i++) {
            if ((i-6)%7==0 || (i%7)==0) continue;
            din1.add_edge(pianos+i, pianos+maxDay+1, capacity);
        }
        int flow1 = din1.flow();
        if (flow1==pianos) {
            printf("fine\n");
            continue;
        }
        Dinic din2 = Dinic(2+pianos+maxDay, 0, pianos+maxDay+1);
        for (int i = 0; i<pianos; i++) {
            din2.add_edge(0, i+1, 1);
            for (int j = days[i].first; j<=days[i].second; j++) {
                din2.add_edge(i+1, pianos+j, 1);
            }
        }
        for (int i = 1; i<=maxDay; i++) {
            din2.add_edge(pianos+i, pianos+maxDay+1, capacity);
        }
        int flow2 = din2.flow();
        if (flow2<pianos) {
            printf("serious trouble\n");
        } else {
            printf("weekend work\n");
        }
    }
}