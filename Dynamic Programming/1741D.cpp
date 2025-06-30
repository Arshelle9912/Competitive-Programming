#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        vector<bool> dp(n+1);
        dp[0] = true;
        for (int i = 1; i<=n; i++) {
            if (i+arr[i-1]<=n && dp[i-1]) {
                dp[i+arr[i-1]] = true;
            }
            if (i-arr[i-1]-1>=0 && dp[i-arr[i-1]-1]) {
                dp[i] = true;
            }
        }
        dp[n] ? cout << "YES" << "\n" : cout << "NO" << "\n";
    }
}