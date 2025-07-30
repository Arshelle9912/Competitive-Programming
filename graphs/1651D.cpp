#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    vector<long long> dx = {1, -1, 0, 0};
    vector<long long> dy = {0, 0, 1, -1};
    map<pair<long long, long long>, int> mp;
    const long long W = 200000+5;
    auto encode = [&](long long x,long long y){ return (long long)x*W + y; };
    set<long long> visited;
    queue<tuple<long long, long long, long long>> q; 
    vector<pair<long long, long long>> adj(n);
    for (long long i = 0; i<n; i++) {
        long long temp1, temp2;
        cin >> temp1 >> temp2;
        adj[i] = {temp1, temp2};
        mp[adj[i]] = i;
    }
    vector<pair<long long, long long>> ans(n);
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<4; j++) {
            int x = adj[i].first;
            int y = adj[i].second;
            int nx = x + dx[j];
            int ny = y + dy[j];
            pair<int, int> temp = {nx, ny};
            if (mp.find(temp)==mp.end()) {
                ans[i] = {nx, ny};
                q.emplace(x, y, i);
                visited.insert(encode(x,y));
                break;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y, id] = q.front();
        q.pop();
        for (long long i = 0; i<4; i++) {
            long long nx = x + dx[i];
            long long ny = y + dy[i];
            pair<int, int> p = {nx, ny};
            if (!visited.count(encode(nx,ny)) && mp.find(p)!=mp.end()) {
                visited.insert(encode(nx,ny));
                ans[mp[p]] = ans[id];
                q.emplace(nx, ny, mp[p]);
            }
        }
    }
    for (pair<long long, long long> p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
}