#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int maxm = 2e5+2;
    int MOD = 1000000007;
    int t;
    cin >> t;
    vector<vector<long long>> dp(maxm, vector<long long>(10, 0));
    for (int i = 0; i<=9; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i<maxm; i++) {
        for (int j = 0; j<=8; j++) {
            dp[i][j] = dp[i-1][j+1];
        }
        dp[i][9] = (dp[i-1][0]+dp[i-1][1])%MOD;
    }
    while (t--) {
        string s;
        int m;
        cin >> s >> m;
        long long ans = 0;
        for (auto i : s) {
            ans = (ans + dp[m][i-'0'])%MOD;
        }
        cout << ans << "\n";
    }
}