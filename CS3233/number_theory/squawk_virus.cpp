#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<long long>> adj(n);
    for (long long i = 0; i<m; i++) {
        long long num1, num2;
        cin >> num1 >> num2;
        adj[num1].push_back(num2);
        adj[num2].push_back(num1);
    }
    queue<pair<long long, long long>> q;
    q.push({s, 1});
    long long total = 0;
    while (t!=0) {
        long long sz = q.size();
        total = 0;
        vector<long long> arr(n);
        for (long long i = 0; i<sz; i++) {
            auto [u, w] = q.front();    
            q.pop();
            for (long long v : adj[u]) {
                arr[v]+=w;
                total+=w;
            }
        }
        for (long long i = 0; i<n; i++) {
            if (arr[i]>0) {
                q.push({i, arr[i]});
            }
        }
        t--;
    }
    printf("%lld\n", total);
}