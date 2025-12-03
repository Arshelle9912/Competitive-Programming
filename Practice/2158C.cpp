#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n), b(n);
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> b[i];
        }
        vector<long long> left(n), right(n);
        long long curr = a[0];
        left[0] = curr;
        long long best = curr;
        for (int i = 1; i<n; i++) {
            curr = max(a[i], curr+a[i]);
            left[i] = curr;
            best = max(curr, best);
        }
        curr = a[n - 1];
        right[n - 1] = curr;
        for (int i = n - 2; i >= 0; i--) {
            curr = max(a[i], curr + a[i]);
            right[i] = curr;
        }
        long long ans = best;
        if (k%2==1) {
            for (int i=0; i<n; i++) {
                long long through = left[i] + right[i] - a[i];
                ans = max(ans, through+b[i]);
            }
        }
        cout << ans << "\n";
    }
}