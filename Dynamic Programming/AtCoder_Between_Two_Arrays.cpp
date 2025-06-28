#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int MOD = 998244353;
    vector<int> ai(n);
    vector<int> bi(n);
    for (int i = 0; i<n; i++) {
        cin >> ai[i];
    }
    for (int i = 0; i<n; i++) {
        cin >> bi[i];
    }
    vector<vector<long long>> dp(n+1, vector<long long>(3001));
    for (int i = ai[0]; i<=bi[0]; i++) {
        dp[1][i] = 1;
    }
    vector<long long> pref(3001);
    for (int i = 2; i<=n; i++) {
        pref[0] = dp[i-1][0];
        for (int x = 1; x <= 3000; x++)
            pref[x] = (pref[x-1] + dp[i-1][x]) % MOD;
        for (int j = ai[i-1]; j<=bi[i-1]; j++) {
            dp[i][j] = pref[j];
        }
    }
    long long ans = 0;
    for (int i = 0; i<3001; i++) {
        ans = (ans+dp[n][i])%MOD;
    }
    cout << ans << "\n";
}