#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
int solve (vector<vector<int>>& dp, int index, int mask, int n, vector<int>& friendMask) {
    if (mask==((1<<n)-1)) return 0;
    if (index == n) return INF;
    if (dp[index][mask]!=INF) return dp[index][mask];
    dp[index][mask] = min(1+solve(dp, index+1, mask|friendMask[index], n, friendMask)
    , solve(dp, index+1, mask, n, friendMask));
    return dp[index][mask];
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> friendMask(n);
        for (int i = 0; i<n; i++) {
            int num;
            cin >> num;
            int mask = 0;
            mask |= (1<<i);
            for (int j = 0; j<num; j++) {
                int fr;
                cin >> fr;
                fr--;
                mask |= (1<<fr);
            }
            friendMask[i] = mask;
        }
        int INF = 1e9;
        vector<vector<int>> dp(n, vector<int> (1<<n, INF));
        int ans = solve(dp, 0, 0, n, friendMask);;
        printf("%d\n", ans);
    }
}