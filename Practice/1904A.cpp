#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int kn1, kn2, k1, k2, q1, q2;
        cin >> kn1 >> kn2 >> k1 >> k2 >> q1 >> q2;
        auto newpos = [] (pair<int, int> p, int kn1, int kn2) -> vector<pair<int, int>> {
            vector<pair<int, int>> result(8);
            result[0] = {p.first+kn1, p.second+kn2};
            result[1] = {p.first-kn1, p.second+kn2};
            result[2] = {p.first+kn1, p.second-kn2};
            result[3] = {p.first-kn1, p.second-kn2};
            result[4] = {p.first+kn2, p.second+kn1};
            result[5] = {p.first-kn2, p.second+kn1};
            result[6] = {p.first+kn2, p.second-kn1};
            result[7] = {p.first-kn2, p.second-kn1};
            return result;
        };
        vector<pair<int, int>> res1 = newpos({q1, q2}, kn1, kn2);
        vector<pair<int, int>> res2 = newpos({k1, k2}, kn1, kn2);
        set<pair<int,int>> s1(res1.begin(), res1.end());
        set<pair<int,int>> s2(res2.begin(), res2.end());
        int ans = 0;
        for (auto p : s1) {
            if (s2.count(p)) ans++;
        }
        cout << ans << "\n";
    }
}