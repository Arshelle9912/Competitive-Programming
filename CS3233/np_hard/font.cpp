#include <bits/stdc++.h>
using namespace std;
int solve(vector<unordered_map<int, long long>>& dp, int index, int n, vector<int>& wordMasks, int mask) {
    if (index==n) return mask==((1<<26)-1) ? 1 : 0;
    if (dp[index].count(mask)) return dp[index][mask];
    dp[index][mask] = solve(dp, index+1, n, wordMasks, mask) 
    + solve(dp, index+1, n, wordMasks, mask|wordMasks[index]);
    return dp[index][mask];
}
int main() {
    int n;
    cin >> n;
    vector<int> wordMasks(n);
    for (int i = 0; i<n; i++) {
        string s;
        cin >> s;
        int mask = 0;
        for (char c : s) {
            mask|=(1<<(c-'a'));
        }
        wordMasks[i] = mask;
    }
    vector<unordered_map<int, long long>> dp(n);
    printf("%d\n", solve(dp, 0, n, wordMasks, 0));
}