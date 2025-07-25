#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        vector<int> a = arr;
        sort(arr.begin(), arr.end());
        bool check = false;
        int ans1;
        int ans2;
        for (int i = 0; i<n; i++) {
            if (a[i]!=arr[i]) {
                check = true;
                ans1 = a[i];
                ans2 = arr[i];
                break;
            }
        }
        if (check) {
            cout << "Yes" << "\n";
            cout << 2 << "\n";
            cout << ans1 << " " << ans2 << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
}