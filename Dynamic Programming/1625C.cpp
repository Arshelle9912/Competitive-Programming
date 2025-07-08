#include <bits/stdc++.h>
using namespace std;
long long n, len, k;
vector<long long> a;
vector<long long> b;
vector<vector<long long>> dp;
long long f(long long index, long long j) {
    if (index==n) {
        return 0;
    }
    if (dp[index][j]!=-1) {
        return dp[index][j];
    }
    long long ans = LLONG_MAX;
    for (int i = index+1; i<=n; i++) {
        int need = i-index-1;
        if (need>j) break;
        long long segment = (b[i]-b[index])*a[index];
        ans = min(ans, segment + f(i, j - need));
    }
    return dp[index][j] = ans;
}
int main() {
    cin >> n >> len >> k;
    a.assign(n, 0);
    b.assign(n+1, 0);
    dp.assign(n+1, vector<long long> (k+1, -1));
    for (long long i = 0; i<n; i++) {
        cin >> b[i];
    }
    b[n] = len;
    for (long long i = 0; i<n; i++) {
        cin >> a[i];
    }
    cout << f(0, k) << "\n";
}