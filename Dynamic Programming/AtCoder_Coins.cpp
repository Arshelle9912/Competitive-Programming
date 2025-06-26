#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<double> prob(n);
    vector<vector<double>> dp(n+1, vector<double>(n+1));
    for (int i = 0; i<n; i++) {
        cin >> prob[i];
    }
    dp[1][0] = 1-prob[0];
    dp[1][1] = prob[0];
    for (int i = 2; i<=n; i++) {
        dp[i][0] = (1-prob[i-1])*dp[i-1][0];
        dp[i][i] = (prob[i-1]) * dp[i-1][i-1];
    }
    for (int i = 2; i<=n; i++) {
        for (int j = 1; j<i; j++) {
            dp[i][j] = prob[i-1]*dp[i-1][j-1] + (1-prob[i-1])*dp[i-1][j];
        }
    }
    double ans(0);
    for (int j = n/2+1; j<=n; j++) {
        ans += dp[n][j];
    }
    cout << fixed << setprecision(10) << ans << "\n";
}