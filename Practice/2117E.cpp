#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        int index(-1);
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> b[i];
        }
        if (a.back() == b.back()) {
            cout << n << '\n';
            continue;
        }
        vector<char> seen(n + 1, 0);
        int ans = -1;

        for (int i = n - 2; i >= 0; --i) {
            bool good = (a[i] == b[i]) || (a[i] == a[i + 1]) || (b[i] == b[i + 1]) || seen[a[i]] || seen[b[i]];
            if (good) { 
                ans = i; 
                break; 
            }
            seen[a[i + 1]] = 1;
            seen[b[i + 1]] = 1;
        }
        cout << ans + 1 << '\n';        
    }
}