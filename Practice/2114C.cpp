#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int last;
        cin >> last;
        int ans(1);
        for (int i = 1; i<n; i++) {
            int temp;
            cin >> temp;
            if (temp>last+1) {
                ans++;
                last = temp;
            }
        }
        cout << ans << "\n";
    }
}