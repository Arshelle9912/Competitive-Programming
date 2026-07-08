#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        vector<vector<int>> dp(n+1, vector<int> (2));
        int INF = 1e9;
        dp[0] = {INF, 0};
        for (int i = 1; i<=n; i++) {
            for (int j = 0; j<2; j++) {
                int val = (j==0 && arr[i-1]==1);
                dp[i][j] = val + dp[i-1][1-j];
                if (i>1) dp[i][j] = min(dp[i][j], val + (arr[i-2]==1 && j==0) + dp[i-2][1-j]);
            }
        } 
        cout << min(dp[n][0], dp[n][1]) << "\n";
    }
}