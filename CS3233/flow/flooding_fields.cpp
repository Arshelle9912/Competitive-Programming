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
    int n, c, h;
    cin >> n >> c >> h;
    vector<vector<int>> grid(n, vector<int> (n));
    Dinic din = Dinic(2+c+n*n*h*2, 0, 1+c+n*n*h*2);
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<pair<int, int>> cows(c);
    vector<int> dir1 = {-1, 1, 0, 0};
    vector<int> dir2 = {0, 0, -1, 1};
    for (int i = 0; i<c; i++) {
        cin >> cows[i].first >> cows[i].second;
        // --cows[i].first;
        // --cows[i].second;
        din.add_edge(0, i+1, 1);
        din.add_edge(i+1, c+1+(cows[i].first*n+cows[i].second)*2, 1);
        for (int j = 0; j<4; j++) {
            int nI = cows[i].first+dir1[j];
            int nJ = cows[i].second+dir2[j];
            if (nI<0 || nI>=n || nJ<0 || nJ>=n) continue;
            din.add_edge(i+1, c+1+(nI*n+nJ)*2, 1);
        }
    }
    for (int i = 0; i<h-1; i++) {
        int water;
        cin >> water;
        for (int u = 0; u<n; u++) {
            for (int v = 0; v<n; v++) {
                if (grid[u][v]<=water) {
                    din.add_edge(c+1+(i*n*n+(u*n+v))*2, c+1+(i*n*n+(u*n+v))*2+1, 0);
                    // for (int k = 0; k<4; k++) {
                    //     int nU = u+dir1[k];
                    //     int nV = v+dir2[k];
                    //     din.add_edge(c+1+(i*n*n+(nU*n+nV))*2, c+1+((i+1)*n*n+(nU*n+nV))*2-1, 0);
                    // }
                    // din.add_edge(c+1+(i*n*n+(u*n+v))*2, c+1+((i+1)*n*n+(u*n+v))*2-1, 0);
                } else {
                    din.add_edge(c+1+(i*n*n+(u*n+v))*2, c+1+(i*n*n+(u*n+v))*2+1, 1);
                    for (int k = 0; k<4; k++) {
                        int nU = u+dir1[k];
                        int nV = v+dir2[k];
                        if (nU<0 || nU>=n || nV<0 || nV>=n) continue;
                        din.add_edge(c+1+(i*n*n+(u*n+v))*2+1, c+1+((i+1)*n*n+(nU*n+nV))*2, 1);
                    }
                    din.add_edge(c+1+(i*n*n+(u*n+v))*2+1, c+1+((i+1)*n*n+(u*n+v))*2, 1);
                }
            }
        }
    }
    int lastWater;
    cin >> lastWater;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (grid[i][j]<=lastWater) {
                din.add_edge(c+1+((h-1)*n*n+(i*n+j))*2, c+1+((h-1)*n*n+(i*n+j))*2+1, 0);
                // din.add_edge(c+1+(h-1)*n*n+(i*n+j), 1+c+n*n*h, 0);
            } else {
                din.add_edge(c+1+((h-1)*n*n+(i*n+j))*2, c+1+((h-1)*n*n+(i*n+j))*2+1, 1);
                din.add_edge(c+1+((h-1)*n*n+(i*n+j))*2+1, 1+c+n*n*h*2, 1);
            }
        }
    }
    printf("%lld\n", din.flow());
}