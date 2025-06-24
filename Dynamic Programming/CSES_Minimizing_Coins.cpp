#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, sum;
    cin >> n >> sum;
    vector<long long> denom(n);
    for (long long i = 0; i<n; i++) {
        cin >> denom[i];
    }
    vector<long long> dp(sum+1, INT_MAX);
    dp[0]=0;
    for (long long i = 1; i<=sum; i++) {
        for (long long j : denom) {
            if (j<=i) {
                dp[i] = min(dp[i], 1+dp[i-j]);
            }
        }
    }
    dp[sum]==INT_MAX ? cout << -1 << "\n" : cout << dp[sum] << "\n";
}