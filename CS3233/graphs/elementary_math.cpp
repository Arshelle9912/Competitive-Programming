#include<bits/stdc++.h>
using namespace std;
#define NIL 0
#define INF LLONG_MAX

// A class to represent Bipartite graph for Hopcroft
// Karp implementation
class BipGraph
{
    // m and n are number of vertices on left
    // and right sides of Bipartite Graph
    long long m, n;

    // adj[u] stores adjacents of left side
    // vertex 'u'. The value of u ranges from 1 to m.
    // 0 is used for dummy vertex
    list<long long> *adj;

    // These are basically polong longers to arrays needed
    // for hopcroftKarp()
    long long *pairU, *pairV, *dist;

public:
    BipGraph(long long m, long long n); // Constructor
    void addEdge(long long u, long long v); // To add edge

    // Returns true if there is an augmenting path
    bool bfs();

    // Adds augmenting path if there is one beginning
    // with u
    bool dfs(long long u);

    // Returns size of maximum matching
    long long hopcroftKarp();

    vector<pair<long long,long long>> getMatchingEdges() {
        vector<pair<long long,long long>> res;
        for (long long u = 1; u <= m; u++) {
            if (pairU[u] != NIL) res.push_back({u, pairU[u]});
        }
        return res;
    }

    long long mateLeft(long long u) {
        return pairU[u];
    }

    long long mateRight(long long v) {
        return pairV[v];
    }

    bool isMatchedLeft(long long u) {
        return pairU[u] != NIL;
    }

    bool isMatchedRight(long long v) {
        return pairV[v] != NIL;
    }
};

// Returns size of maximum matching
long long BipGraph::hopcroftKarp()
{
    // pairU[u] stores pair of u in matching where u
    // is a vertex on left side of Bipartite Graph.
    // If u doesn't have any pair, then pairU[u] is NIL
    pairU = new long long[m+1];

    // pairV[v] stores pair of v in matching. If v
    // doesn't have any pair, then pairU[v] is NIL
    pairV = new long long[n+1];

    // dist[u] stores distance of left side vertices
    // dist[u] is one more than dist[u'] if u is next
    // to u'in augmenting path
    dist = new long long[m+1];

    // Initialize NIL as pair of all vertices
    for (long long u=0; u<=m; u++)
        pairU[u] = NIL;
    for (long long v=0; v<=n; v++)
        pairV[v] = NIL;

    // Initialize result
    long long result = 0;

    // Keep updating the result while there is an
    // augmenting path.
    while (bfs())
    {
        // Find a free vertex
        for (long long u=1; u<=m; u++)

            // If current vertex is free and there is
            // an augmenting path from current vertex
            if (pairU[u]==NIL && dfs(u))
                result++;
    }
    return result;
}

// Returns true if there is an augmenting path, else returns
// false
bool BipGraph::bfs()
{
    queue<long long> Q; //an long longeger queue

    // First layer of vertices (set distance as 0)
    for (long long u=1; u<=m; u++)
    {
        // If this is a free vertex, add it to queue
        if (pairU[u]==NIL)
        {
            // u is not matched
            dist[u] = 0;
            Q.push(u);
        }

        // Else set distance as infinite so that this vertex
        // is considered next time
        else dist[u] = INF;
    }

    // Initialize distance to NIL as infinite
    dist[NIL] = INF;

    // Q is going to contain vertices of left side only. 
    while (!Q.empty())
    {
        // Dequeue a vertex
        long long u = Q.front();
        Q.pop();

        // If this node is not NIL and can provide a shorter path to NIL
        if (dist[u] < dist[NIL])
        {
            // Get all adjacent vertices of the dequeued vertex u
            list<long long>::iterator i;
            for (i=adj[u].begin(); i!=adj[u].end(); ++i)
            {
                long long v = *i;

                // If pair of v is not considered so far
                // (v, pairV[V]) is not yet explored edge.
                if (dist[pairV[v]] == INF)
                {
                    // Consider the pair and add it to queue
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }

    // If we could come back to NIL using alternating path of distinct
    // vertices then there is an augmenting path
    return (dist[NIL] != INF);
}

// Returns true if there is an augmenting path beginning with free vertex u
bool BipGraph::dfs(long long u)
{
    if (u != NIL)
    {
        list<long long>::iterator i;
        for (i=adj[u].begin(); i!=adj[u].end(); ++i)
        {
            // Adjacent to u
            long long v = *i;

            // Follow the distances set by BFS
            if (dist[pairV[v]] == dist[u]+1)
            {
                // If dfs for pair of v also returns
                // true
                if (dfs(pairV[v]) == true)
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }

        // If there is no augmenting path beginning with u.
        dist[u] = INF;
        return false;
    }
    return true;
}

// Constructor
BipGraph::BipGraph(long long m, long long n)
{
    this->m = m;
    this->n = n;
    adj = new list<long long>[m+1];
}

// To add edge from u to v and v to u
void BipGraph::addEdge(long long u, long long v)
{
    adj[u].push_back(v); // Add u to v’s list.
}



// Driver Program
int main()
{
    long long node = 1;
    map<long long, long long> mp;
    map<long long, long long> mp2;
    long long n;
    cin >> n;
    vector<pair<long long, long long>> pairs(n);
    for (long long i = 0; i<n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
        long long sum = pairs[i].first + pairs[i].second;
        long long sub = pairs[i].first - pairs[i].second;
        long long mul = pairs[i].first * pairs[i].second;
        if (!mp.count(sum)) {
            mp[sum] = node;
            node++;
        }
        if (!mp.count(sub)) {
            mp[sub] = node;
            node++;
        }
        if (!mp.count(mul)) {
            mp[mul] = node;
            node++;
        }
    }
    BipGraph g = BipGraph(n, mp.size());
    for (long long i = 0; i<n; i++) {
        long long sum = pairs[i].first + pairs[i].second;
        long long sub = pairs[i].first - pairs[i].second;
        long long mul = pairs[i].first * pairs[i].second;
        mp2[mp[sum]] = sum;
        mp2[mp[mul]] = mul;
        mp2[mp[sub]] = sub;
        g.addEdge(i+1, mp[sum]);
        g.addEdge(i+1, mp[sub]);
        g.addEdge(i+1, mp[mul]);
    }
    if (g.hopcroftKarp()!=n) {
        printf("impossible\n");
        return 0;
    }
    for (long long i = 1; i<=n; i++) {
        long long num = g.mateLeft(i);
        long long sum = pairs[i-1].first + pairs[i-1].second;
        long long sub = pairs[i-1].first - pairs[i-1].second;
        long long mul = pairs[i-1].first * pairs[i-1].second;
        // printf("Test %d\n", mp2[num]);
        if (mp2[num]==sum) printf("%lld + %lld = %lld\n", pairs[i-1].first, pairs[i-1].second, mp2[num]);
        else if (mp2[num]==mul) printf("%lld * %lld = %lld\n", pairs[i-1].first, pairs[i-1].second, mp2[num]);
        else if (mp2[num]==sub) printf("%lld - %lld = %lld\n", pairs[i-1].first, pairs[i-1].second, mp2[num]);
    }
}