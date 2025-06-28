#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> cost(n);
    vector<int> pages(n);
    for (int i = 0; i<n; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i<n; i++) {
        cin >> pages[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (x+1));
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=x; j++) {
            if (j-cost[i-1]>=0) {
                dp[i][j] = max(dp[i-1][j], pages[i-1]+dp[i-1][j-cost[i-1]]);
            }
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
        }
    }
    cout << dp[n][x] << "\n";
}