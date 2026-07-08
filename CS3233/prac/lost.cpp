#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, r;
    cin >> n >> r;
    vector<long long> dist(n+1, -1);
    map<string, long long> mp;
    mp["English"] = 0;
    for (long long i = 1; i<=n; i++) {
        string s;
        cin >> s;
        mp[s] = i;
    } 
    vector<vector<pair<long long, long long>>> adj(n+1);
    for (long long i = 0; i<r; i++) {
        string s1, s2;
        int cost;
        cin >> s1 >> s2 >> cost;
        adj[mp[s1]].push_back({mp[s2], cost});
        adj[mp[s2]].push_back({mp[s1], cost});
    }
    vector<long long> costs(n+1, LLONG_MAX);
    costs[0] = 0;
    queue<long long> q;
    q.push(0);
    dist[0] = 0;
    long long cost = 0;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (auto p : adj[front]) {
            if (dist[p.first]==-1 || dist[p.first]==dist[front]+1) {
                costs[p.first] = min(costs[p.first], p.second);
                if (dist[p.first]==-1) q.push(p.first);
                dist[p.first]=dist[front]+1;
            }
        }
    }
    for (int i = 0; i<=n; i++) {
        if (dist[i]==-1) {
            cout << "Impossible\n";
            return 0;
        }
    }
    for (int i = 0; i<=n; i++) {
        cost += costs[i];
    }
    cout << cost << "\n";
}