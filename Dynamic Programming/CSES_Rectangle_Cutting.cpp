#include <bits/stdc++.h>
using namespace std;
int main() {
    int l, b;
    cin >> l >> b;
    vector<vector<int>> dp(l+1, vector<int> (b+1, INT_MAX));
    for (int i = 2; i<=l; i++) {
        dp[i][1] = i-1;
    }
    for (int i = 2; i<=b; i++) {
        dp[1][i] = i-1;
    }
    for (int i = 1; i<=min(l,b); i++) {
        dp[i][i] = 0;
    }
    for (int i = 1; i<=l; i++) {
        for (int j = 1; j<=b; j++) {
            for (int k = 1; k<=i/2; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[i-k][j] + dp[k][j]);
            }
            for (int k = 1; k<=j/2; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
            }
        }
    }
    cout << dp[l][b] << "\n";
}