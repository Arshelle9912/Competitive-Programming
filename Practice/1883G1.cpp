#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> c(n);
        vector<int> b(n);
        c[0] = 1;
        for (int i = 1; i<n; i++) {
            cin >> c[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> b[i];
        }
        int numMatches = 0;
        int j = 0;
        int i = 0;
        sort(c.begin(), c.end());
        sort(b.begin(), b.end());
        while (j<n) {
            if (c[i]<b[j]) {
                numMatches++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        cout << n - numMatches << "\n";
    }
}