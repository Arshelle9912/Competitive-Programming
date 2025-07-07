#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (k+1));
    vector<int> length(n);
    sort(arr.begin(), arr.end());
    int j = 0;
    for (int i = 0; i<n; i++) {
        while (j<n && arr[j]-arr[i]<=5) {
            j++;
        }
        length[i] = j-1;
    }
    for (int i = n-1; i>=0; i--) {
        int len = length[i] - i + 1;
        for (int j = 0; j<=k; j++) {
            dp[i][j] = dp[i+1][j];
            if (j>0) {
                dp[i][j] = max(dp[i][j], len + dp[length[i]+1][j-1]);
            }
        }
    }
    cout << dp[0][k] << "\n";
}