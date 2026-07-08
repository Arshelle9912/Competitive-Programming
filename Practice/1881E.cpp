#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int INF = 1e9;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        vector<pair<int, int>> dp(n+1, {INF, INF});
        dp[n-1].first = 1;
        dp[n].second = 0;
        for (int i = n-2; i>=0; i--) {
            int val = i+arr[i]+1;
            if (val<=n) dp[i].second = min(dp[i].second, min(dp[val].first, dp[val].second));
            dp[i].first = 1+min(dp[i+1].first, dp[i+1].second);
        }
        cout << min(dp[0].first, dp[0].second) << "\n";
    }
}