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
        int minimum = arr[0];
        bool check = true;
        for (int i = 1; i<n; i++) {
            if (arr[i]>=2*minimum) {
                check = false;
            }
            minimum = min(minimum, arr[i]);
        }
        if (check) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}