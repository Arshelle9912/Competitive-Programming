#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maximum = INT_MIN;
    for (int i = 0; i<n; i++) {
        maximum = max(maximum, nums[i]+i);
        if (maximum>=nums.size()-1) {
            return true;
        }
        if (nums[i]==0 && maximum <= i) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    canJump(nums);
}