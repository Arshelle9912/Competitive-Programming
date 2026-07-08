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
            while (!q.empty()) q.pop();
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
    int low = 0;
    int high = 1e9;
    map<int, string> ind;
    vector<vector<int>> adj(n);
    int count = 0;
    for (int i = 0; i<n; i++) {
        string name;
        cin >> name;
        ind[count] = name;
        int k;
        cin >> k;
        for (int j = 0; j<k; j++) {
            int day;
            cin >> day;
            adj[count].push_back(day);
        }
        count++;
    }
    int ans;
    while (low<=high) {
        int mid = (low+high)/2;
        Dinic din = Dinic(n+m+2, 0, n+m+1);
        for (int i = 1; i<=n; i++) {
            din.add_edge(0, i, mid);
            for (int day : adj[i-1]) {
                din.add_edge(i, n+day, 1);
            }
        }
        for (int i = n+1; i<=n+m; i++) {
            din.add_edge(i, n+m+1, 2);
        }
        if (din.flow()==2*m) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    printf("%d\n", ans);
    Dinic din(n + m + 2, 0, n + m + 1);
    for (int i = 1; i<=n; i++) {
        din.add_edge(0, i, ans);
        for (int day : adj[i-1]) {
            din.add_edge(i, n+day, 1);
        }
    }
    for (int i = n+1; i<=n+m; i++) {
        din.add_edge(i, n+m+1, 2);
    }
    din.flow();
    vector<vector<int>> who(m + 1);
    for (int i = 0; i<(int)din.edges.size(); i+=2) {
        auto &e = din.edges[i];
        if (1<=e.v && e.v<=n && (n+1)<=e.u && e.u<=(n+m) && e.flow==1) {
            int day = e.u-n;
            int ra = e.v-1;
            who[day].push_back(ra);
        }
    }
    for (int day = 1; day<=m; day++) {
        printf("Day %d: %s %s\n", day, ind[who[day][0]].c_str(), ind[who[day][1]].c_str());
    }
}