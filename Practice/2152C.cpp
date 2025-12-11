#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        vector<int> pref(n);
        pref[0] = arr[0];
        for (int i = 1; i<n; i++) {
            pref[i] = pref[i-1] + arr[i];
        }
        vector<int> diff(n);
        for (int i = 0; i<n-1; i++) {
            if (arr[i]!=arr[i+1]) {
                diff[i+1] = diff[i] + 1;
            } else {
                diff[i+1] = diff[i];
            }
        }
        for (int i = 0; i<q; i++) {
            int left, right;
            cin >> left >> right;
            int len = right-left+1;
            int ones = pref[right-1] - (left-1>0 ? pref[left-2] : 0);
            if (ones % 3 != 0 || (len-ones)%3!=0) {
                cout << -1 << "\n";
                continue;
            }
            if (diff[right-1] - diff[left-1] == right-left) {
                cout << (len)/3 + 1 << "\n";
            } else {
                cout << (len)/3 << "\n";
            }
        }
    }
}