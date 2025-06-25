#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    int MOD = 1000000007;
    vector<vector<int>> dp(n+1, vector<int> (x+1));
    vector<int> denom(n);
    for (int i = 0; i<n; i++) {
        cin >> denom[i];
    }
    for (int i = 0; i<=n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=x; j++) {
            dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
            if (j>=denom[i-1]) {
                dp[i][j] = (dp[i][j] + dp[i][j-denom[i-1]])%MOD;
            }
        }
    }
    cout << dp[n][x] << "\n";
}