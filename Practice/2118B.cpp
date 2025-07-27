#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << 2*n-2 << "\n";
        for (int i = 1; i<=n; i++) {
            if (i>1) cout << i << " " << 1 << " " << i << "\n";
            if (i<n) cout << i << " " << i+1 << " " << n << "\n";
        }
    }
}