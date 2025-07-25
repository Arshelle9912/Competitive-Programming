#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        int start = arr[0];
        int end = arr[n-1];
        if (p<=start) {
            cout << end - p << "\n";
        } else if (p>=end) {
            cout << p-start << "\n";
        } else {
            int diff = min(p-start, end-p);
            cout << diff*2 + max(p-start, end-p) << "\n";
        }
    }
}