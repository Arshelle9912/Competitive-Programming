#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 5;
    vector<vector<int>> dp(n, vector<int> ((1<<n), -1));
    auto f = [&] (int index, int mask, vector<int> v, auto &&F) -> int {
        // if (index == n) {
        //     for (auto &i : v) {
        //         cout << i << " ";
        //     }
        //     cout << "\n";
        //     return;
        // }
        if (index==n) {
            return 1;
        }
        if (dp[index][mask]!=-1) {
            return dp[index][mask];
        }
        int ways = 0;
        for (int i = 0; i<n; i++) {
            if (((1<<i)&mask)==0) {
                // v.push_back(i+1);
                ways += F(index+1, mask | (1<<i), v , F);
                // v.pop_back();
            }
        }
        return dp[index][mask] = ways;
    };
    cout << f(0, 0, {}, f);
}