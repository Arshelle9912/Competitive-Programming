#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        string s;
        cin >> s;
        if (n<4) {
            cout << 0 << "\n";
            continue;
        }
        bool check = true;
        for (int i = 3; i<n; i++) {
            if (s[i-1]=='2' && s[i-2]=='0' && s[i-3]=='2') {
                if (s[i]=='5') {
                    check = false;
                } else if (s[i]=='6') {
                    check = true;
                    break;
                }
            }
        }
        if (check) cout << 0 << "\n";
        if (!check) cout << 1 << "\n";
    }
}