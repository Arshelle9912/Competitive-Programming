#include <bits/stdc++.h>
using namespace std;

int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
    int maximum1(INT_MIN), sum(0);
    int ans(0);
    for (int i = 0; i<n; i++) {
        sum+=nums2[i]-nums1[i];
        maximum1 = max(sum, maximum1);
        if (sum<0) {
            sum = 0;
        }
    }
    sum = 0;
    int maximum2 = INT_MIN;
    for (int i = 0; i<n; i++) {
        sum+=nums1[i]-nums2[i];
        maximum2 = max(sum, maximum2);
        if (sum<0) {
            sum = 0;
        }
    }
    return max({sum1, sum2, sum1 + maximum1, sum2 + maximum2});
}
int main() {
    int n;
    cin >> n;
    vector<int> nums1(n), nums2(n);
    for (int i = 0; i<n; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i<n; i++) {
        cin >> nums2[i];
    }
    cout << maximumsSplicedArray(nums1, nums2);
}