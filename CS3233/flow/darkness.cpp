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
    int minLight, height, r, c;
    cin >> minLight;
    cin >> height;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int> (c));
    vector<string> sr(r);
    for (int i = 0; i<r; i++) {
        cin >> sr[i];
    }
    for (int i = 0; i<r; i++) {
        for (int j = 0; j<c; j++) {
            grid[i][j] = sr[i][j]-'0';
        }
    }
    vector<vector<double>> light(r, vector<double> (c));
    for (int i = 0; i<r; i++) {
        for (int j = 0; j<c; j++) {
            int power = grid[i][j];
            if (power==0) continue;
            for (int a = 0; a<r; a++) {
                for (int b = 0; b<c; b++) {
                    int dx = i-a;
                    int dy = j-b;
                    long long dist = dx*dx+dy*dy+1LL*height*height;
                    light[a][b]+=((double)power/dist);
                }
            }
        }
    }
    long long INF = 4e15;
    Dinic din = Dinic(r*c+2, 0, r*c+1);
    vector<vector<char>> isLit(r, vector<char>(c, 0));
    auto id = [&](int i, int j) { 
        return 1 + i*c + j; 
    };
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            isLit[i][j] = (light[i][j] >= minLight);
        }
    }
    auto add_undirected = [&](int u, int v, long long w) {
        din.add_edge(u, v, w);
        din.add_edge(v, u, w);
    };
    int S = 0;
    int T = r*c + 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 || i == r-1 || j == 0 || j == c-1) {
                din.add_edge(S, id(i, j), INF);
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!isLit[i][j]) {
                din.add_edge(id(i, j), T, INF);
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int u = id(i, j);
            if (j + 1 < c) {
                int v = id(i, j + 1);
                long long w = (isLit[i][j] && isLit[i][j+1]) ? 43 : 11;
                add_undirected(u, v, w);
            }
            if (i + 1 < r) {
                int v = id(i + 1, j);
                long long w = (isLit[i][j] && isLit[i+1][j]) ? 43 : 11;
                add_undirected(u, v, w);
            }
        }
    }
    cout << din.flow() << "\n";
}