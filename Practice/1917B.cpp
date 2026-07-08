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
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 97; i<123; i++) {
            char c = (char) i;
            bool found = false;
            for (char cn : s) {
                if (cn==c) {
                    found = true;
                } else if (found) {
                    ans++;
                }
            }
        }
        cout << ans + n << "\n";
    }
}