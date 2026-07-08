#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<long long, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        vector<long long> pref(n);
        pref[0] = a[0].first;
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + a[i].first;
        }
        vector<int> ans(n);
        int reach = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (pref[i] < a[i + 1].first) {
                reach = i;
            }
            ans[a[i].second] = reach;
        }
        ans[a[n - 1].second] = n - 1;
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}