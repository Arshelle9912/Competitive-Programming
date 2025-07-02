#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, target;
    cin >> n >> k >> target;
    vector<int> pos(n);
    vector<int> keys(k);
    for (int i = 0; i<n; i++) {
        cin >> pos[i];
    }
    for (int i = 0; i<k; i++) {
        cin >> keys[i];
    }
    sort(pos.begin(), pos.end());
    sort(keys.begin(), keys.end());
    vector<vector<long long>> dp(n+1, vector<long long> (k+1, LLONG_MAX/100));
    for (int j = 1; j<=k; j++) {
        long long t = llabs(keys[j-1]-pos[0]) + llabs(keys[j-1]-target);
        dp[1][j] = min(dp[1][j-1],t);
    }
    for (int i = 2; i<=n; i++) {
        for (int j = i; j<=k; j++) {
            long long t = llabs(keys[j-1]-pos[i-1]) + llabs(keys[j-1]-target);
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
            dp[i][j] = min(dp[i][j], max(dp[i-1][j-1],t));
        }
    }
    cout << dp[n][k] << "\n";
}