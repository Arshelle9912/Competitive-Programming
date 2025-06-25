#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int MOD = 1000000007;
    vector<vector<long long>> dp(k+1, vector<long long>(n+1));
    for (int i = 1; i<=n; i++) {
        dp[k][i] = 1;
    }
    for (int i = k-1; i>=0; i--) {
        for (int j = 1; j<=n; j++) {
            for (int l = j; l<=n; l+=j) {
                dp[i][j] = (dp[i][j]+dp[i+1][l])%MOD;
            }
        }
    }
    cout << dp[0][1] << "\n";
}