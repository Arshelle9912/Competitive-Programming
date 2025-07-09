#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int f(int index, int n, long long mask, vector<int>& nums1, vector<int>& nums2) {
    if (index==n) {
        return 0;
    }
    if (dp[index][mask]!=-1) {
        return dp[index][mask];
    }
    int ans(INT_MAX);
    for (int i=0; i<n; i++) {
        if ((mask & (1<<i))==0) {
            int cost = nums1[index] ^ nums2[i];
            ans = min(ans, cost + f(index+1, n, mask | (1<<i), nums1, nums2));
        }
    }
    return dp[index][mask] = ans;
}
int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    dp.assign(nums1.size()+1, vector<int> (1<<nums1.size(), -1));
    return f(0, nums1.size(), 0, nums1, nums2);
}
int main() {
    int n;
    cin >> n;
    vector<int> nums1(n);
    vector<int> nums2(n);
    for (int i = 0; i<n; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i<n; i++) {
        cin >> nums2[i];
    }
    cout << minimumXORSum(nums1, nums2) << "\n";
}