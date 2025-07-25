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
        if (arr[0]<=arr[1]) {
            cout << 2*arr[0] << "\n";
        } else {
            cout << (arr[0] + arr[1]) << "\n";
        }
    }
}