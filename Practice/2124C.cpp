#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a%b);
}
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (long long i = 0; i<n; i++) {
            cin >> arr[i];
        }
        vector<long long> lcms;
        for (long long i = 1; i<n; i++) {
            if (arr[i]%arr[i-1]!=0) {
                lcms.push_back(arr[i-1]/gcd(arr[i], arr[i-1]));
            }
        }
        long long ans = 1;
        for (long long i : lcms) {
            ans = (ans*i)/gcd(ans, i);
        }
        cout << ans << "\n";
    }
}