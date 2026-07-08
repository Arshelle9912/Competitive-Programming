#include <bits/stdc++.h>
#include <numeric>
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
    int n;
    cin >> n;
    vector<int> nums(n);
    int maxI = 0;
    int maxNum = 0;
    int minI = 0;
    int minNum = INT_MAX;
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
        if (nums[i]>maxNum) {
            maxNum = nums[i];
            maxI = i;
        }
        if (nums[i]<minNum) {
            minI = i;
            minNum = nums[i];
        }
    }
    Dinic din = Dinic(n+2, 0, n+1);
    for (int i = 0; i<n; i++) {
        for (int j = i+1; j<n; j++) {
            int val = gcd(nums[i], nums[j]);
            // printf("%d %d %d\n", val, nums[i], nums[j]);
            if (val>1) {
                din.add_edge(i+1, j+1, val);
                din.add_edge(j+1, i+1, val);
            }
        }
    }
    int INF = 1e9;
    din.add_edge(0, minI+1, INF);
    din.add_edge(maxI+1, n+1, INF);
    printf("%lld\n", din.flow());
}