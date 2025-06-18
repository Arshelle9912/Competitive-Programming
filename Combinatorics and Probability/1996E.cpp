#include <bits/stdc++.h>
using namespace std;

int MOD = 1000000007;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        map<int, vector<int>> groups;
        int count(0);
        groups[0].push_back(0);
        for (int i = 0; i<n; i++) {
            if (s[i]=='0') {
                count--;
            } else {
                count++;
            }
            groups[count].push_back(i+1);
        }
        long long sum(0);
        for (auto const& [balance, group] : groups) {
            int m = group.size();
            vector<long long> pref(m);
            vector<long long> B(m);
            int c = 0;
            for(int i = 0; i < m; i++){
                B[i] = (n - group[i] + 1);
            }
            pref[0] = B[0];
            for (int i = 1; i<m; i++) {
                pref[i] = (pref[i-1]+B[i])%MOD;
            }
            for (int i = 0; i<m-1; i++) {
                sum = (sum+(group[i]+1)*(pref[m-1]-pref[i]+MOD)%MOD*1LL)%MOD;
            }
        }
        cout << sum << "\n";
    }
}