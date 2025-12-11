#include <bits/stdc++.h>
using namespace std;
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
        vector<long long> pref(n);
        pref[0] = arr[0];
        for (long long i = 1; i<n; i++) {
            pref[i] = pref[i-1] + arr[i];
        }
        vector<long long> a(n), b(n);
        for (long long i = 0; i<n; i++) {
            a[i] = i*i + 3*i - pref[i] + 2;
        }
        b[0] = 0;
        for (long long i = 1; i<n; i++) {
            b[i] = min(b[i-1], i*i + i - pref[i-1]);
        }
        long long gain = 0;
        for (long long i = 0; i<n; i++) {
            gain = max(gain, a[i]-b[i]);
        }
        cout << pref[n-1] + gain << "\n";
    }
}