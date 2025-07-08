#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, c;
    cin >> n >> c;
    vector<long long> arr(n);
    for (long long i = 0; i<n; i++) {
        cin >> arr[i];
    }
    vector<long long> dp(n+1, 0);
    multiset<long long> ms;   
    dp[0] = 0;
    for (long long i = 1; i<=n; i++) {
        ms.insert(arr[i-1]);
        if (i==c) {
            dp[i] = max(dp[i-1], *ms.begin());
            break;
        }
        dp[i] = dp[i-1];
    }
    for (long long i = c+1; i<=n; i++) {
        auto it = ms.find(arr[i-c-1]);
        if (it!=ms.end()) {
            ms.erase(it);
        }
        ms.insert(arr[i-1]);
        dp[i] = max(dp[i-1], *ms.begin()+dp[i-c]);
    }
    long long ans(0);
    for (long long i = 0; i<n; i++) {
        ans += arr[i];
    }
    cout << ans - dp[n] << "\n";
}