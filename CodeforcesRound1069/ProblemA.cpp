#include <bits/stdc++.h>
using namespace std;
int main() {
    long long L = 1000000000000000000;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        set<long long> s;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s.insert(arr[i]);
        }
        if (L <= n) {
            cout << arr[(int)L - 1] << "\n";
            continue;
        }
        long long d = (long long) s.size();
        long long k = L - n;
        long long max = *max_element(s.begin(), s.end());
        if (max<d) {
            long long ans = d + (k - 1);
            cout << ans << "\n";
        } else {
            auto it = s.lower_bound(d);
            long long dnew = *it;
            long long threshold = (dnew - d + 1);
            if (k >= threshold) {
                cout << dnew << "\n";
            } else {
                long long ans = d + (k - 1);
                cout << ans << "\n";
            }
        }
    }
}