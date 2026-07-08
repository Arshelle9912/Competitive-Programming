#include <bits/stdc++.h>
using namespace std;
int MOD = 1001113;
int main() {
    vector<vector<long long>> dp(101, vector<long long> (101));
    dp[1][0] = 1;
    for (int i = 2; i<=100; i++) {
        for (int curr = 0; curr<=100; curr++) {
            dp[i][curr] = ((curr+1)*dp[i-1][curr])%MOD;
            if (curr>0 && i>=curr) dp[i][curr] = (dp[i][curr] + (i-curr)*dp[i-1][curr-1])%MOD;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, num, val;
        cin >> n >> num >> val;
        cout << n << " " << dp[num][val] << "\n";
    }
}