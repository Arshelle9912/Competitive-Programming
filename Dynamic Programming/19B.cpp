#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    vector<vector<long long>> dp(n+1, vector<long long> (n+1, LLONG_MAX/100));
    for (int i = 0; i<=n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i<=n; i++) {
        int w = arr[i-1].first + 1; 
        long long cost = arr[i-1].second;
        for (int t = 0; t <= n; ++t) {
            dp[i][t] = dp[i-1][t];
        }
        for (int t = 0; t <= n; ++t) {
            if (dp[i-1][t] == LLONG_MAX/100) continue;
            int nt = min(n, t + w);
            dp[i][nt] = min(dp[i][nt], dp[i-1][t] + cost);
        }
    }
    cout << dp[n][n] << "\n";
}