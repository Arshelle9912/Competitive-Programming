#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <climits>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> mergeKLists(const vector<vector<pair<int,int>>>& new_nums, int n) {
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<>> pq;
        int k = new_nums.size();
        for (int i = 0; i < k; ++i) {
            if (!new_nums[i].empty()) {
                pq.emplace(new_nums[i][0].first, i, 0);
            }
        }
        vector<pair<int,int>> merged;
        merged.reserve(n);
        while (!pq.empty()) {
            auto [val, list_id, idx] = pq.top();
            pq.pop();
            int origin = new_nums[list_id][idx].second;
            merged.emplace_back(val, origin);

            int next_idx = idx + 1;
            if (next_idx < (int)new_nums[list_id].size()) {
                pq.emplace(new_nums[list_id][next_idx].first,
                        list_id,
                        next_idx);
            }
        }
        return merged;
    }
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n(0);
        vector<vector<pair<int, int>>> new_nums(nums.size());
        for (int i = 0; i<(int)nums.size(); i++) {
            for (int j = 0; j<(int)nums[i].size(); j++) {
                new_nums[i].push_back({nums[i][j], i});
                n++;
            }
        }
        vector<pair<int, int>> merged = mergeKLists(new_nums, n);
        map<int, int> mp;
        int low(0);
        vector<int> result(2);
        int range(INT_MAX);
        for (int i = 0; i<n; i++) {
            mp[merged[i].second]++;
            while (mp.size()==nums.size()) {
                if (range>merged[i].first - merged[low].first) {
                    result[0] = merged[low].first;
                    result[1] = merged[i].first;
                    range = merged[i].first - merged[low].first;
                }
                mp[merged[low].second]--;
                if (mp[merged[low].second]<=0) {
                    mp.erase(merged[low].second);
                }
                low++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<int> result = sol.smallestRange(nums);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
