#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int l, s;
        cin >> l >> s;
        vector<pair<int, string>> arr(s);
        for (int i = 0; i<s; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        vector<char> ans(l, '*');
        sort(arr.begin(), arr.end(), greater<pair<int, string>>());
        bool breaker = false;
        for (int i = 0; i<s; i++) {
            string pref = "";
            string suff = "";
            bool check = true;
            for (char c : arr[i].second) {
                if (c=='*') {check = false; continue;}
                if (check) pref+=c;
                else suff+=c;
            }
            int numMissing = arr[i].first-1;
            for (int i = 0; i<pref.size(); i++) {
                if (ans[i+numMissing]=='*') ans[i+numMissing] = pref[i];
                else if (ans[i+numMissing]!=pref[i]) {breaker=true; break;};
            }
            if (breaker) break;
            for (int i = 0; i<suff.size(); i++) {
                if (ans[l-suff.size()+i]=='*') ans[l-suff.size()+i] = suff[i];
                else if (ans[l-suff.size()+i]!=suff[i]) {breaker=true; break;};
            }
            if (breaker) break;
        }
        for (int i = 0; i<l; i++) {
            if (ans[i]=='*') {
                breaker = true;
                break;
            }
        }
        if (breaker) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for (int i = 0; i<l; i++) {
            printf("%c", ans[i]);
        }
        printf("\n");
    }
}