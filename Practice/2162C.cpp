#include <bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long numDigits = 64-__builtin_clzll(a);
        long long m = (1LL << numDigits) - 1;
        if (b > m) {                      
            cout << -1 << "\n";
            continue;
        }
        if (a==b) {
            cout << 0 << "\n";
            continue;
        }
        long long xor1 = (a^b);
        if (xor1<=a) {
            cout << 1 << "\n";
            cout << xor1 << "\n";
            continue;
        }
        cout << 2 << "\n";
        long long x1 = (a^m);
        long long x2 = (b^m);
        cout << x1 << " " << x2 << "\n";
    }
}