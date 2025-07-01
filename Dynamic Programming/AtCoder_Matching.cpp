#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int MOD = 1000000007;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    vector<vector<long long>> dp(n, vector<long long> ((1<<n), -1));
    auto f = [&] (int index, int mask, auto &&F) -> long long {
        long long ways = 0;
        for (int i = 0; i<n; i++) {
            if (index == n) {
                return 1;
            }
            if (dp[index][mask]!=-1) {
                return dp[index][mask];
            }
            if (((1<<i)&mask)==0 && arr[index][i]) {
                ways = (ways + F(index+1, mask | (1<<i), F))%MOD;
            }
        }
        return dp[index][mask] = ways;;
    };
    cout << f(0, 0, f);
}