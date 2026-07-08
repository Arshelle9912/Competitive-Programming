#include <bits/stdc++.h>
using namespace std;
long long calc(vector<int>& v) {
    sort(v.begin(), v.end());
    long long ans = 0;
    long long pref = 0;
    for (int i = 0; i < v.size(); i++) {
        ans += 1LL * v[i] * i - pref;
        pref += v[i];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rows(100001), cols(100001);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int color;
            cin >> color;
            rows[color].push_back(i);
            cols[color].push_back(j);
        }
    }
    long long ans = 0;
    for (int color = 1; color <= 100000; color++) {
        ans += calc(rows[color]);
        ans += calc(cols[color]);
    }
    cout << ans << "\n";
}