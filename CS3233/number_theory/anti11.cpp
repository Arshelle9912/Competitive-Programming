#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i<=n; i++) {
            dp[i] = (dp[i-1] + dp[i-2])%MOD;
        }
        printf("%d\n", (dp[n] + MOD)%MOD);
    }
}