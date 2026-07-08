#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    int MOD;
    cin >> t >> MOD;
    vector<int> fact(1000001);
    fact[0] = fact[1] = 1;
    for (int i = 2; i<=1000000; i++) {
        fact[i] = (1LL*fact[i-1]*i)%MOD;
    }
    vector<int> dp(1000001);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i<=1000000; i++) {
        dp[i] = (dp[i-1] + 1LL*(i-1)*dp[i-2])%MOD;
    }
    while (t--) {
        int n;
        cin >> n;
        printf("%d\n", (fact[n]-dp[n]+MOD)%MOD);
    }
}