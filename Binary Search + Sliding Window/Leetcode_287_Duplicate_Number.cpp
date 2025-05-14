#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    vector<int> nums;
    int n;
    for (int i = 0; i<n; i++) {
        cin >> n; 
        nums[i] = n;
    }
    findDuplicate(nums);
}
int findDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    for (int i = 0; i<nums.size(); i++) {
        if(set.find(nums[i]) != set.end()) {
            return nums[i];
        } else {
            set.insert(nums[i]);
        }
    }
}