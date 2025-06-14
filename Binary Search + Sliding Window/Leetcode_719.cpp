#include <bits/stdc++.h>
using namespace std;

int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int low = 0, high = 1e6;
    while (low<high) {
        int left = 0;
        int mid = low + (high - low) / 2;;
        int count = 0;
        for (int i = 0; i<n; i++) {
            while (nums[i]-nums[left]>mid) {
                left++;
            }
            count += i-left;
        }
        if (count>=k) {
            high = mid;
        } else {
            low = mid+1;
        }
    }
    return low;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    cout << smallestDistancePair(nums, k);
}