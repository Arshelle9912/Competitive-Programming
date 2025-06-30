#include <bits/stdc++.h>
using namespace std;
const long long N = 5005;
long long a[N], hot[N], cold[N], n, k;
long long solve(long long index, long long lastCol, vector<vector<long long>>& dp) {
    if (index == n) {
        return 0;
    }
    if (dp[index][lastCol]!=-1) {
        return dp[index][lastCol];
    }
    long long optionA = solve(index+1, a[index-1], dp) + (lastCol == a[index] ? hot[a[index]] : cold[a[index]]);
    long long optionB = solve(index+1, lastCol, dp) + (a[index-1] == a[index] ? hot[a[index]] : cold[a[index]]);
    return dp[index][lastCol] = min(optionA, optionB);
}
int main() {
    long long t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (long long i = 0; i<n; i++) {
            cin >> a[i];
        }
        for (long long i = 1; i<=k; i++) {
            cin >> cold[i];
        }
        for (long long i = 1; i<=k; i++) {
            cin >> hot[i];
        }
        vector<vector<long long>> dp(n, vector<long long> (k+1, -1));
        cout << cold[a[0]] + solve(1,0,dp) << "\n";
    }
}