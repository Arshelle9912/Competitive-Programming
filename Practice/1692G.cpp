#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int len = 1;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        int ans = 0;
        for (int i = 1; i<n; i++) {
            if (arr[i-1]<arr[i]*2) {
                len++;
            } else {
                ans += max(0, len-k);
                len = 1;
            }
        }
        if (len>1) {
            ans += max(0, len-k);
        }
        cout << ans << "\n";
    }
}