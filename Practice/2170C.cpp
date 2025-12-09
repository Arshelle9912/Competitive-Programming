#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> p(n);
        vector<long long> q(n);
        for (int i = 0; i<n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> q[i];
        }
        sort(p.begin(), p.end());
        sort(q.begin(), q.end());
        long long ans = 0;
        long long pointer1(0), pointer2(n-1);
        while (pointer1<n && pointer2>=0) {
            if (q[pointer2]+((q[pointer2]+1)*p[pointer1])<=k) {
                ans++;
                pointer1++;
                pointer2--;
            } else {
                pointer2--;
            }
        }
        cout << ans << "\n";
    }
}