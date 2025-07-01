#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
vector<long long> arr;
long long n;
long long solve(long long left, long long right) {
    if (left>=right) {
        return 0;
    }
    if (dp[left][right]!=LLONG_MAX) {
        return dp[left][right];
    }
    long long option1 = solve(left, right-1);
    if (left+1 <= n) {
        long long option2 = solve(left+1, right);
        dp[left][right] = arr[right-1] - arr[left-1] + min(option1, option2);
        return dp[left][right];
    }
    dp[left][right] = option1 + arr[right-1] - arr[left-1];
    return dp[left][right];
}
int main() {
    cin >> n;
    arr.assign(n, 0);
    dp.assign(n+1, vector<long long> (n+1, LLONG_MAX));
    for (long long i = 0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    dp[0][0] = 0;
    cout << solve(1, n) << "\n";
}