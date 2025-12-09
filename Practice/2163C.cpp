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
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> b[i];
        }
        vector<pair<int, int>> pref(n);
        vector<pair<int, int>> suff(n);
        pref[0] = {a[0], a[0]};
        suff[n-1] = {b[n-1], b[n-1]};
        for (int i = 1; i<n; i++) {
            pref[i] = {min(pref[i-1].first, a[i]), max(pref[i-1].second, a[i])};
        }
        for (int i = n-2; i>=0; i--) {
            suff[i] = {min(suff[i+1].first, b[i]), max(suff[i+1].second, b[i])};
        }
        vector<pair<int, int>> mix(n);
        for (int i = 0; i<n; i++) {
            mix[i] = {min(suff[i].first, pref[i].first), max(suff[i].second, pref[i].second)};
        }
        vector<int> bucket(2*n+1, INT_MAX);
        for (int i = 0; i<n; i++) {
            bucket[mix[i].first] = min(bucket[mix[i].first], mix[i].second);
        }
        long long ans = 0;
        int cur = INT_MAX;
        for (int l = 2*n; l >= 1; l--) {
            cur = min(cur, bucket[l]);
            if (cur != INT_MAX) {
                ans += 2*n - cur + 1;
            }
        }
        cout << ans << "\n";
    }
}