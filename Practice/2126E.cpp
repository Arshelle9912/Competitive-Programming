#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    return b==0 ? a : gcd(b, a%b);
}
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> pref(n);
        vector<long long> suff(n);
        for (long long i = 0; i<n; i++) {
            cin >> pref[i];
        }
        for (long long i = 0; i<n; i++) {
            cin >> suff[i];
        }
        bool check = true;
        vector<long long> arr(n);
        for (long long i = 0; i<n; i++) {
            arr[i] = pref[i]*suff[i]/gcd(pref[i], suff[i]);
        }
        if (n==1) {
            cout << (pref[0]==suff[0] ? "YES\n" : "NO\n");
            continue;
        }
        if (arr[0] != pref[0]) check = false;
        if (arr[n-1] != suff[n-1]) check = false;

        long long ans = arr[0];
        for (long long i = 1; i<n; i++) {
            ans = gcd(ans, arr[i]);
            if (ans!=pref[i]) {
                check = false;
            }
        }
        ans = arr[n-1];
        for (long long i = n-2; i>=0; i--) {
            ans = gcd(ans, arr[i]);
            if (ans!=suff[i]) {
                check = false;
            }
        }
        if (check) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}