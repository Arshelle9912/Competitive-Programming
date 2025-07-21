#include <bits/stdc++.h>
using namespace std;
int MOD = 998244353;
int exponentiation(long long base, int power) {
    long long result = 1;
    while (power>0) {
        if (power&1) {
            result = (result*base)%MOD;
        }
        base = (base*base)%MOD;
        power>>=1;
    }
    return result;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        for (int i = 0; i<m; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            adj[temp1].push_back(temp2);
            adj[temp2].push_back(temp1);
        }
        long long ans(1);
        bool isBipartite = true;
        vector<int> colors(n+1, -1);
        for (int start = 1; start <= n && isBipartite; ++start) {
            if (colors[start]!=-1) continue;
            int count[2] = {1, 0};
            queue<int> q;
            q.push(start);
            colors[start] = 0;
            while (!q.empty() && isBipartite) {
                int node = q.front();
                q.pop();
                for (int i : adj[node]) {
                    if (colors[i]==-1) {
                        colors[i] = 1 - colors[node];
                        ++count[colors[i]];
                        q.push(i);
                    } else if (colors[i]==colors[node]) {
                        isBipartite = false;
                        break;
                    }
                }
            }
        
            if (!isBipartite) {
                break;
            }
            long long ways = (exponentiation(2, count[0]) + exponentiation(2, count[1]))%MOD;
            ans = (ans*ways)%MOD;
        }
        cout << (isBipartite ? ans : 0) << "\n";
    }
}