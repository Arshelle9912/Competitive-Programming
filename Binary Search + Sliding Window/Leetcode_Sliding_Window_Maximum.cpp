#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    long long sum(0);
    long long maximum(-LLONG_MAX);
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i<n; i++) {
        while (!dq.empty() && dq.front()<=i-k) {
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()]<=nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }   
}