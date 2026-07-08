#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> arr(n+1);
        for (int i = 0; i<=n; i++) {
            arr[i] = i;
        }
        arr[r] = l-1;
        for (int i = 1; i<=n; i++) {
            int a = arr[i-1] ^ arr[i];
            cout << a << (i==n ? '\n' : ' ');
        }
    }
}