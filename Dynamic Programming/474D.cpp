#include <bits/stdc++.h>
using namespace std;
int main() {
    long long t, k;
    cin >> t >> k;
    long long MOD = 1000000007;
    vector<long long> dp(100005);
    dp[0] = 1;
    long long sum = 1;
    for (long long i = 1; i<100005; i++) {
        dp[i] = dp[i-1];
        if (i>=k) {
            dp[i] = (dp[i]+dp[i-k])%MOD;
        }
    }
    vector<long long> pref(100005);
    pref[0] = dp[0];
    for (long long i = 1; i<100005; i++) {
        pref[i] = (pref[i-1]+dp[i])%MOD;
    }
    while (t--) {
        long long start, end;
        cin >> start >> end;
        cout << (pref[end] - pref[start-1] + MOD) % MOD << "\n";
    }
}