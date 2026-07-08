#include <bits/stdc++.h>
using namespace std;
bool check (long long excess, vector<int>& ls, int mid) {
    int n = ls.size();
    for (int i = 0; i<n; i++) {
        if (ls[i]<mid) {
            excess-=(mid-ls[i]);
            if (excess<0) return false;
        }
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long excess = 0;
        int n;
        cin >> n;
        vector<int> nums(n);
        vector<int> ls(n);
        for (int i = 0; i<n; i++) {
            cin >> nums[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> ls[i];
            excess += (nums[i]-ls[i]);
        }
        int low = 0;
        int high = 1e9;
        int ans = 0;
        while (low<=high) {
            int mid = (low+high)/2;
            if (check(excess, ls, mid)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        printf("%d\n", ans);
    }
}