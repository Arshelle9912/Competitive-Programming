#include <bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        long long maxi = 0;
        for (long long i = 0; i<n; i++) {
            cin >> arr[i];
            maxi = max(arr[i], maxi);
        }
        long long ans = -maxi;
        for (long long i = 1; i<n; i++) {
            ans += max(arr[i], arr[i-1]);
        }
        ans += max(arr[n-1], arr[0]);
        cout << ans << "\n";
    }
}