#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    int MOD = 1000000007;
    cin >> n >> m;
    vector<vector<int>> transitions((1<<n));
    vector<vector<int>> dp(m+1, vector<int> ((1<<n), -1));
    auto buildT = [&] (int mask, int row, int nextMask, auto &&self) -> void {
        if (row == n) {
            transitions[mask].push_back(nextMask);
            return;
        }
        if (mask & (1 << row)) {
            self(mask, row + 1, nextMask, self);
        } else {
            if (row + 1 < n && !(mask & (1 << (row + 1)))) {
                self(mask, row + 2, nextMask, self);
            }
            self(mask, row + 1, nextMask | (1 << row), self);
        }
    };
    for (int mask = 0; mask < (1<<n); mask++) {
        buildT(mask, 0, 0, buildT);
    }
    auto f = [&] (int index, int mask, int m, vector<vector<int>>& dp, const vector<vector<int>>& transition, auto &&F) -> int {
        if (index == m) {
            return (mask==0 ? 1 : 0);
        }
        if (dp[index][mask]!=-1) {
            return dp[index][mask];
        }
        long long answer = 0;
        for (auto newMask : transitions[mask]) {
            answer = (answer+F(index+1, newMask, m, dp, transitions, F))%MOD;
        }
        return dp[index][mask] = answer;
    };
    cout << f(0, 0, m, dp, transitions, f) << "\n"; 
}