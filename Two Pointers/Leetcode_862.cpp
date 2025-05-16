#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> nums(n);
    vector<long long> prefix(n+1,0);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
        prefix[i+1] = prefix[i] + nums[i];
    }
    int result(n+1);
    deque<int> dq;
    dq.push_back(0);
    for (int i = 1; i<=n; i++) {
        while(!dq.empty() && (prefix[i] - prefix[dq.front()]) >= k) {
            result = min(result, i - dq.front());
            dq.pop_front();
        }
        while(!dq.empty() && prefix[i] <= prefix[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    result = result == n+1 ? -1 : result;
    cout << result;
}