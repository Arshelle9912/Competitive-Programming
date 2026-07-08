#include <bits/stdc++.h>
using namespace std;

/*
    Edmonds' Blossom Algorithm
    ----------------------------------------
    Solves:
        Maximum Cardinality Matching
        in a general UNDIRECTED, UNWEIGHTED graph

    Works for:
        - non-bipartite graphs
        - graphs with odd cycles

    Does NOT solve:
        - weighted matching
        - assignment problem
        - min-cost matching

    Complexity:
        O(V^3)

    Vertex indexing:
        0-indexed
*/

struct Blossom {
    int n;                              // number of vertices
    vector<vector<int>> g;              // adjacency list

    vector<int> match;                  // match[v] = vertex matched with v, or -1
    vector<int> p;                      // parent array for alternating tree
    vector<int> base;                   // base vertex of blossom/component

    vector<bool> used;                  // whether vertex is in BFS queue/tree
    vector<bool> blossom;               // marks vertices currently inside found blossom

    queue<int> q;                       // BFS queue

    // Constructor
    Blossom(int n = 0) {
        init(n);
    }

    // Initialize graph with n vertices
    void init(int n_) {
        n = n_;
        g.assign(n, {});
        match.assign(n, -1);
        p.assign(n, -1);
        base.resize(n);
        used.assign(n, false);
        blossom.assign(n, false);
    }

    // Add undirected edge u-v
    void addEdge(int u, int v) {
        if (u == v) return;             // ignore self-loops
        g[u].push_back(v);
        g[v].push_back(u);
    }

    /*
        Find LCA (lowest common ancestor) of vertices a and b
        in the alternating forest, after considering blossom bases.

        Why needed?
        When we detect an odd cycle (blossom), we need to know
        the common base vertex where the two alternating paths meet.
    */
    int lca(int a, int b) {
        vector<bool> used_path(n, false);

        // Walk from a upwards through alternating tree
        while (true) {
            a = base[a];
            used_path[a] = true;

            // if a is unmatched, path ends
            if (match[a] == -1) break;

            // move: matched edge -> parent
            a = p[match[a]];
        }

        // Walk from b upwards until hitting a marked base
        while (true) {
            b = base[b];
            if (used_path[b]) return b;

            if (match[b] == -1) break;
            b = p[match[b]];
        }

        return -1; // should never happen in valid blossom detection
    }

    /*
        Marks all vertices on path from v to blossom base b.

        child = the vertex through which this path is connected.

        This is used during blossom contraction:
        every vertex/base on this path becomes part of the blossom.
    */
    void markPath(int v, int b, int child) {
        while (base[v] != b) {
            // mark current base and matched partner's base as inside blossom
            blossom[base[v]] = blossom[base[match[v]]] = true;

            // set parent for alternating tree reconstruction
            p[v] = child;

            // move upward by alternating matched/unmatched edges
            child = match[v];
            v = p[match[v]];
        }
    }

    /*
        BFS from one unmatched root to find an augmenting path.

        Returns true if augmenting path found and matching increased by 1.
        Returns false otherwise.
    */
    bool findPath(int root) {
        // reset BFS structures
        fill(used.begin(), used.end(), false);
        fill(p.begin(), p.end(), -1);
        iota(base.begin(), base.end(), 0); // initially each vertex is its own base

        while (!q.empty()) q.pop();

        // start BFS from root
        used[root] = true;
        q.push(root);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int u : g[v]) {
                // Ignore:
                // 1. same blossom/base
                // 2. matched edge back to partner
                if (base[v] == base[u] || match[v] == u) continue;

                /*
                    Case 1:
                    Found an edge that creates an odd cycle/blossom.

                    This happens if:
                    - u is the BFS root, or
                    - u is already in alternating tree in an "even level" sense
                      detected by p[match[u]] != -1
                */
                if (u == root || (match[u] != -1 && p[match[u]] != -1)) {
                    int curbase = lca(v, u);

                    fill(blossom.begin(), blossom.end(), false);

                    // Mark blossom path from both sides to common base
                    markPath(v, curbase, u);
                    markPath(u, curbase, v);

                    // After blossom identified, contract it:
                    // every vertex whose base is inside blossom gets new base = curbase
                    for (int i = 0; i < n; i++) {
                        if (blossom[base[i]]) {
                            base[i] = curbase;

                            // if not already in BFS tree, add it
                            if (!used[i]) {
                                used[i] = true;
                                q.push(i);
                            }
                        }
                    }
                }

                /*
                    Case 2:
                    u has not yet been visited in alternating tree.
                    So extend the tree with parent[u] = v.
                */
                else if (p[u] == -1) {
                    p[u] = v;

                    /*
                        If u is unmatched, we found an augmenting path.
                        Now flip matched/unmatched edges along this path.
                    */
                    if (match[u] == -1) {
                        int cur = u;

                        while (cur != -1) {
                            int pv = p[cur];                    // parent in alternating tree
                            int nv = (pv == -1 ? -1 : match[pv]); // next vertex to continue from

                            match[cur] = pv;
                            if (pv != -1) match[pv] = cur;

                            cur = nv;
                        }
                        return true;
                    }

                    /*
                        Otherwise u is matched, so continue BFS from its matched partner.
                        This preserves alternating structure.
                    */
                    else {
                        used[match[u]] = true;
                        q.push(match[u]);
                    }
                }
            }
        }

        // no augmenting path found from this root
        return false;
    }

    /*
        Runs blossom algorithm to compute maximum matching.

        Returns size of maximum matching.
    */
    int solve() {
        int matching = 0;

        // Try BFS from every currently unmatched vertex
        for (int i = 0; i < n; i++) {
            if (match[i] == -1 && findPath(i)) {
                matching++;
            }
        }

        return matching;
    }

    // ---------------- Helper Functions ----------------

    // Returns whether vertex v is matched
    bool isMatched(int v) const {
        return match[v] != -1;
    }

    // Returns mate/partner of vertex v, or -1 if unmatched
    int mate(int v) const {
        return match[v];
    }

    // Returns all matched edges as pairs (u, v) with u < v
    vector<pair<int,int>> getPairs() const {
        vector<pair<int,int>> res;
        for (int i = 0; i < n; i++) {
            if (match[i] != -1 && i < match[i]) {
                res.push_back({i, match[i]});
            }
        }
        return res;
    }

    // Returns full matching array
    vector<int> getMatchArray() const {
        return match;
    }

    // Returns number of matched vertices (twice matching size)
    int matchedVertexCount() const {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (match[i] != -1) cnt++;
        }
        return cnt;
    }

    // Clears only the matching, keeps graph
    void clearMatching() {
        fill(match.begin(), match.end(), -1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Blossom bm(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        bm.addEdge(u, v);   // assumes 0-indexed input
    }

    int maxMatching = bm.solve();
    cout << "Maximum matching size = " << maxMatching << "\n";

    auto pairs = bm.getPairs();
    cout << "Matched pairs:\n";
    for (auto [u, v] : pairs) {
        cout << u << " " << v << "\n";
    }

    return 0;
}