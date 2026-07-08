#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> arr(n+1);
        for (int i = 1; i<=n; i++) {
            cin >> arr[i];
        }
        long long ans = LLONG_MAX;
        vector<long long> suffix(n+1);
        for (int i = n-1; i>=0; i--) {
            long long diff = arr[i+1] - arr[i];
            suffix[i] = diff*(n-i) + suffix[i+1];
        }
        long long curr = 0;
        for (int i = 0; i<=n; i++) {
            ans = min(ans, curr + b*suffix[i]);
            if (i<n) {
                long long dist = arr[i+1] - arr[i];
                curr += (a+b)*dist;
            }
        }
        cout << ans << "\n";
    }
}