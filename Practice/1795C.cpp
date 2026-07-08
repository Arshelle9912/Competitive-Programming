#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        vector<long long> b(n);
        for (long long i = 0; i<n; i++) {
            cin >> a[i];
        }
        for (long long i = 0; i<n; i++) {
            cin >> b[i];
        }
        vector<long long> pref(n);
        pref[0] = b[0];
        for (long long i = 1; i<n; i++) {
            pref[i] = b[i] + pref[i-1];
        }
        vector<long long> ans(n);
        vector<long long> count(n);
        for (long long i = 0; i<n; i++) {
            long long target = a[i] + (i>0 ? pref[i-1] : 0);
            auto it = upper_bound(pref.begin(), pref.end(), target);
            if (it==pref.end()) {
                count[i]++;
                continue;
            }
            long long idx = it - pref.begin();
            long long prev = (idx > 0 ? pref[idx - 1] : 0);
            ans[idx] += target - prev;
            count[i]++;
            count[idx]--;
        }
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            cur += count[i];
            ans[i] += cur * b[i];
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}