#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<long long>>& adj, vector<long long>& ai, vector<long long>& bi, long long parent, long long node, vector<long long>& v, long long sum, vector<long long>& ans) {
    sum+=ai[node];
    for (long long i : adj[node]) {
        if (i!=parent) {
            v.push_back(v[v.size()-1] + bi[i]);
            dfs(adj, ai, bi, node, i, v, sum, ans);   
            v.pop_back(); 
        }
    }
    long long low = 0, high = v.size()-1;
    long long temp = -1;
    while (low<=high) {
        long long mid = (low+high)/2;
        if (v[mid]<=sum) {
            temp = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    ans[node] = temp;
    sum-=ai[node];
}
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> ai(n+1);
        vector<long long> bi(n+1);
        vector<vector<long long>> adj(n+1);
        for (long long i = 2; i<=n; i++) {
            long long temp, a, b;
            cin >> temp >> a >> b;
            adj[temp].push_back(i);
            ai[i] = a;
            bi[i] = b;
        }
        vector<long long> v;
        v.push_back(0);
        vector<long long> ans(n+1);
        dfs(adj, ai, bi, -1, 1, v, 0, ans);
        for (long long i = 2; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}