#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> freqAns(26);
    vector<vector<int>> freqIndex(26);
    int n = s.length();
    for (int i = 0; i<n; i++) {
        int num = s[i]-'a';
        freqIndex[num].push_back(i);
    }
    for (int i = 0; i<26; i++) {
        int best = 0;
        int size = freqIndex[i].size();
        for (int j = 1; j<n; j++) {
            array<int,26> cnt{}; 
            for (int x : freqIndex[i]) {
                cnt[s[(x + j)%n]-'a']++;
            }
            int unique = 0;
            for (int x : freqIndex[i]) {
                if (cnt[s[(x+j)%n]-'a'] == 1) {
                    unique++;
                }
            }
            best = max(best, unique);
            if (best == size) {
                break;
            }
        }
        freqAns[i] = best;
    }
    double ans(0);
    for (int i = 0; i<26; i++) {
        ans+=freqAns[i];
    }
    cout << setprecision(7) << fixed << ans/n << "\n";
}