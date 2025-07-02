#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> colors(n);
    vector<vector<int>> cost(n, vector<int> (m));
    for (int i = 0; i<n; i++) {
        cin >> colors[i];
    }
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cin >> cost[i][j];
        }
    }
    vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>> (m+1, vector<long long> (k+1, LLONG_MAX/100)));
    if (colors[0]!=0) {
        dp[1][colors[0]][1] = 0;
    } else {
        for (int i = 1; i<=m; i++) {
            dp[1][i][1] = cost[0][i-1];
        }
    }
    for (int i = 2; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            for (int g = 1; g<=k; g++) {
                if (dp[i-1][j][g]>=LLONG_MAX/100) {
                    continue;
                }
                for (int c = 1; c<=m; c++) {
                    if (colors[i-1]!=0 && colors[i-1]!=c) {
                        continue;
                    }
                    long long paintCost = colors[i-1]==0 ? cost[i-1][c-1] : 0;
                    int newG = g + (c!=j);
                    if (newG>k) {
                        continue;
                    }
                    dp[i][c][newG] = min(dp[i][c][newG], dp[i-1][j][g]+paintCost);
                }
            }
        }
    }
    long long ans = LLONG_MAX;
    for (int i = 1; i<=m; i++) {
        ans = min(dp[n][i][k], ans);
    }
    if (ans>=LLONG_MAX/100) {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans << "\n";
}