#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i<n; i++) {
            c[i] = a[i]^b[i];
        }
        int check = 0;
        for (int i = 0; i<n; i++) {
            check = check^c[i];
        }
        if (check == 0) {
            cout << "Tie\n"; 
        } else {
            int k = 0;
            while (check >>k > 1) k++;
            int mask = 1<<k;
            for (int i = n-1; i>=0; i--) {
                if (c[i] & mask) {
                    if (i%2 != 0) {
                        cout << "Mai\n";
                    } else {
                        cout << "Ajisai\n";
                    }
                    break;
                }
            }
        }
    }
}