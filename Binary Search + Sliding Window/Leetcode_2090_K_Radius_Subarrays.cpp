#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    vector<int> result(n, -1);
    long long sum(0);
    int window = 2LL*k + 1;
    if (window > n) {
        for (int i = 0; i < n; i++) {
            cout << -1 << (i+1<n ? ' ' : '\n');
        }
        return 0;
    }
    for (int i = 0; i<window; i++) {
        sum += nums[i];
    }
    result[k] = sum / window;
    for (int i = k+1; i<n-k; i++) {
        sum+=nums[i+k];
        sum-=nums[i-k-1];
        result[i] = sum / window;
    }
    for (int i = 0; i<n; i++) {
        cout << result[i] << " ";
    }
}