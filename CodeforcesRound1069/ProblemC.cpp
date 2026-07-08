#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        int n = (int)s.size();
        int m = (int)t.size();
        vector<int> rem(26, 0), needAll(26, 0);
        for (char ch : t) {
            rem[ch - 'a']++;
        }
        for (char ch : s) {
            needAll[ch - 'a']++;
        }
        bool possible = true;
        for (int c = 0; c < 26; c++) {
            if (rem[c] < needAll[c]) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            cout << "Impossible\n";
            continue;
        }
        vector<array<int, 26>> suffix(n + 1);
        suffix[n].fill(0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1];
            suffix[i][s[i] - 'a']++;
        }
        auto canFinish = [&](int j) {
            for (int c = 0; c < 26; c++) {
                if (rem[c] < suffix[j][c]) return false;
            }
            return true;
        };
        string ans;
        ans.reserve(m);
        int j = 0;
        for (int pos = 0; pos < m; pos++) {
            for (int c = 0; c < 26; c++) {
                if (rem[c] == 0) continue;
                rem[c]--;
                int j2 = j;
                if (j < n && c == (s[j] - 'a')) {
                    j2++;
                }
                if (canFinish(j2)) {
                    ans.push_back(char('a' + c));
                    j = j2;
                    break;
                }
                rem[c]++;
            }
        }
        cout << ans << "\n";
    }
}
