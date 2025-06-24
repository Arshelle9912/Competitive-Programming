#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    int MOD = 1000000007;
    vector<int> denom(n);
    for (int i = 0; i<n; i++) {
        cin >> denom[i];
    }
    vector<int> dp(x+1);
    dp[0]=1;
    for (int i = 1; i<=x; i++) {
        for (int j : denom) {
            if (j<=i) {
                dp[i] = (dp[i]+dp[i-j])%MOD;
            }
        }
    }
    cout << dp[x] << "\n";
}