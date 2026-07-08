#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d\n", &n);
        int arr[n];
        int sum = 0;
        for (int i = 0; i<n; i++) {
            scanf("%d", &arr[i]);
            sum+=arr[i];
        }
        vector<vector<bool>> dp(n+1, vector<bool> (sum/2+1));
        dp[0][0] = true;
        for (int i = 1; i<=n; i++) {
            for (int j = 0; j<=sum/2; j++) {
                dp[i][j] = dp[i][j] || dp[i-1][j];
                if (j-arr[i-1]>=0) (dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]]);
            }
        }
        int maxi = 0;
        for (int i = sum/2; i>=0; i--) {
            if (dp[n][i]) {maxi = i;break;}
        }
        printf("%d %d\n", maxi, sum-maxi);
    }
}