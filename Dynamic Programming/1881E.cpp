#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> arr(n);
        vector<int> dp(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        for (int i = n-1; i>=0; i--) {
            int pick = 0;
            if (i+arr[i]<=n-1) {
                pick = 1+arr[i];
                if (1+arr[i]+i <= n-1) {
                    pick += dp[1+arr[i]+i];
                }
            }
            int skip = 0;
            if (i+1<=n-1) {
                skip+=dp[i+1];
            }
            dp[i] = max(pick, skip);
        }
        cout << n-dp[0] << "\n";
    }
}