#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ai(n);
        vector<int> bi(n);
        for (int i = 0; i<n; i++) {
            cin >> ai[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> bi[i];
        }
        vector<int> prefa(n);
        prefa[0] = ai[0];
        for (int i = 1; i<n; i++) {
            prefa[i] = ai[i] + prefa[i-1];
        }
        int ans = 0;
        int maxb = 0;
        for (int i = 0; i<min(n, k); i++) {
            maxb = max(maxb, bi[i]);
            ans = max(ans, prefa[i] + (k-i-1)*maxb);
        }
        cout << ans << "\n";
    }
}