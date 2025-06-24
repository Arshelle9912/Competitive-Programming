#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int MOD = 1000000007;
    vector<string> grid(n);
    for (int i = 0; i<n; i++) {
        cin >> grid[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n));
    bool check = false;
    for (int i = 0; i<n; i++) {
        if (grid[0][i]=='*') {
            check = true;
        }
        if (check) {
            dp[0][i] = 0;
        } else {
            dp[0][i] = 1;
        }
    }
    check = false;
    for (int i = 0; i<n; i++) {
        if (grid[i][0]=='*') {
            check = true;
        }
        if (check) {
            dp[i][0] = 0;
        } else {
            dp[i][0] = 1;
        }
    }
    for (int i = 1; i<n; i++) {
        for (int j = 1; j<n; j++) {
            if (grid[i][j]=='*') {
                dp[i][j]=0;
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
            }
        }
    }
    cout << dp[n-1][n-1] << "\n";
}