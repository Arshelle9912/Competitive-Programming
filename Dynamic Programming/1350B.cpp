#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n+1);
        vector<int> dp(n+1, 1);
        for (int i = 1; i<=n; i++) {
            cin >> arr[i];
        }
        int ans(0);
        for (int i = n; i>0; i--) {
            int temp = i;
            while (temp<=n) {
                if (arr[temp]>arr[i]) {
                    dp[i] = max(1+dp[temp], dp[i]);
                }
                ans = max(ans, dp[i]);
                temp+=i;
            }
        }
        cout << ans << "\n";
    }
}