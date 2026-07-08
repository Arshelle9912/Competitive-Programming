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
        map<int, pair<int, int>> mp;
        for (int i = 0; i<n; i++) {
            int num;
            cin >> num;
            int len = mp.count(num) != 0 ? i-mp[num].second : i+1;
            if (mp.count(num)!=0) {
                mp[num] = {max(len, mp[num].first), i};
            } else {
                mp[num] = {len, i};
            }
        }
        int smallest = INT_MAX;
        vector<int> ans(n, INT_MAX);
        for (auto [key, p] : mp) {
            int len = max(p.first, n-p.second)-1;
            ans[len] = min(ans[len], key);
        }
        for (int i = 0; i<n; i++) {
            if (ans[i]==INT_MAX && smallest==INT_MAX) cout << -1 << " ";
            else if (ans[i]<smallest) {
                cout << ans[i] << " ";
                smallest = ans[i];
            } else cout << smallest << " ";
        }
        cout << "\n";
    }
}