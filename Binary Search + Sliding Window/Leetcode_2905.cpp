#include <bits/stdc++.h>
using namespace std;

vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
    int n = nums.size();
    multiset<pair<int, int>> ms;
    for (int i = indexDifference; i<n; i++) {
        ms.insert({nums[i], i});
    }
    for (int i = 0; i<n; i++) {
        if (!ms.empty()) {
            auto it1 = (*ms.begin());
            auto it2 = *ms.rbegin();
            if (it1.first<=nums[i]-valueDifference) {
                return {i, it1.second};
            } else if (it2.first>=valueDifference+nums[i]) {
                return {i, it2.second};
            }
            pair<int, int> rem = {nums[i+indexDifference], i+indexDifference};
            ms.erase(rem);
        }
    }
    return {-1, -1};
}

int main() {
    int n, indexDifference, valueDifference;
    cin >> n >> indexDifference >> valueDifference;
    vector<int> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    vector<int> result = findIndices(nums, indexDifference, valueDifference);
    for (int x : result) {
        cout << x << endl;
    }
}