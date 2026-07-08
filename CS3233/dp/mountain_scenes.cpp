#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
int main() {
    int l, h, w;
    cin >> l >> w >> h;
    vector<vector<long long>> dp(w+1, vector<long long> (l+1));
    dp[0][0] = 1;
    for (int i = 1; i<=w; i++) {
        for (int j = 0; j<=h; j++) {
            for (int k = 0; k<=l; k++) {
                if (j+k<=l) {
                    dp[i][j+k] = (dp[i-1][k]+dp[i][j+k])%MOD;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i<=l; i++) {
        ans = (ans + dp[w][i])%MOD;
    }
    int num = 0;
    for (int i = 0; i<=h; i++) {
        if (w*i>l) break;
        num++;
    }
    cout << (ans - num + MOD) % MOD << "\n";
}