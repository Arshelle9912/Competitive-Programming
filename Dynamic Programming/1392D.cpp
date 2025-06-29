#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool all_same = true;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[0]) { 
                all_same = false; 
                break; 
            }
        }
        if (all_same) {
            cout << (n + 2) / 3 << "\n";
            continue;
        }
        vector<int> runLen;
        int len = 1;
        for (int i = 1; i<n; i++) {
            if (s[i]==s[i-1]) {
                len++;
            } else {
                runLen.push_back(len);
                len = 1;
            }
        }
        runLen.push_back(len);
        if (s[0]==s[n-1]) {
            runLen[0] += runLen.back();
            runLen.pop_back();
        }
        int ans = 0;
        for (int i : runLen) {
            ans += i/3;
        }
        cout << ans << "\n";
    }
}