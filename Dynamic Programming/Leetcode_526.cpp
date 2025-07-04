#include <bits/stdc++.h>
using namespace std;
int countArrangement(int n) {
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    vector<vector<int>> dp(n+1, vector<int> ((1<<n), -1));
    auto f = [&] (int index, int mask, auto &&F) -> int {
        int ans(0);
        if (index==n) {
            return 1;
        }
        if (dp[index][mask]!=-1) {
            return dp[index][mask];
        }
        for (int i = 0; i<n; i++) {
            if (!(mask&(1<<i)) && (((index+1)%arr[i])==0 || (arr[i]%(index+1))==0)) {
                ans += F(index+1, mask | (1<<i), F);
            }
        }
        return dp[index][mask] = ans;
    };
    return f(0, 0, f);
}
int main() {
    int n;
    cin >> n;
    cout << countArrangement(n);
}