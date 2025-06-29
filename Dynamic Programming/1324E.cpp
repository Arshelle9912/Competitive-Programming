#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int> dp(h, INT_MIN);
    dp[0] = 0;
    for (int i = 0; i<n; i++) {
        vector<int> dptemp(h, INT_MIN);
        for (int t = 0; t<h; t++) {
            if (dp[t]<0) {
                continue;
            }
            int t1 = (t+arr[i]-1)%h;
            int gain1(0);
            if (l<=t1 && t1<=r) {
                gain1 = 1;
            }
            dptemp[t1] = max(dptemp[t1], dp[t]+gain1);
            int t2 = (t+arr[i])%h;
            int gain2(0);
            if (l<=t2 && t2<=r) {
                gain2 = 1;
            }
            dptemp[t2] = max(dptemp[t2], dp[t]+gain2);
        }
        dp.swap(dptemp);
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}