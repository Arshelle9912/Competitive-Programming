#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, w;
    cin >> n >> w;
    vector<int> weights(n);
    vector<int> values(n);
    vector<vector<long long>> dp(n+1, vector<long long> (100005, LLONG_MAX/100));
    int maxV(0);
    for (int i = 0; i<n; i++) {
        cin >> weights[i] >> values[i];
    }
    for (int i = 0; i<n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<100005; j++) {
            if (j>=values[i-1]) {
                dp[i][j] = min(weights[i-1] + dp[i-1][j-values[i-1]], dp[i-1][j]);
            }
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
        }
    }
    for (int i = 100004; i>=0; i--) {
        if (dp[n][i]<=w) {
            cout << i << "\n";
            return 0;
        }
    }
}