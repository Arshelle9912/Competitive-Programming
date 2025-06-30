#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
long long n;
vector<long long> arr;
bool chance = true;
long long solve(long long left, long long right) {
    if (left>right) {
        return 0;
    }
    if (left==right) {
        return arr[left];
    }
    if (dp[left][right]!=LLONG_MIN) {
        return dp[left][right];
    }
    long long option1 = arr[left] - solve(left+1, right);
    long long option2 = arr[right] - solve(left, right-1);
    dp[left][right] = max(option1, option2);
    return dp[left][right];
}
int main() {
    cin >> n;
    arr.assign(n, 0);
    for (long long i = 0; i<n; i++) {
        cin >> arr[i];
    }
    dp.assign(n, vector<long long>(n, LLONG_MIN));
    long long diff = solve(0, n-1);
    long long total = accumulate(arr.begin(), arr.end(), 0LL);
    long long ans = (diff+total)/2;
    cout << ans << "\n";
}