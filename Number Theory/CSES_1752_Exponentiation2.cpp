#include <bits/stdc++.h>
using namespace std;

long long binary_exponentiation(long long a, long long b, long long m) {
    long long result = 1;
    a %= m;
    while (b>0) {
        if (b&1) {
            result = (result * a)%m;
        }
        a = (a*a)%m;
        b >>= 1;
    }
    return result;
}
int main() {
    long long a, b, c;
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> a >> b >> c;
        long long modulo = binary_exponentiation(b, c, 1e9+6);
        cout << binary_exponentiation(a, modulo, 1e9+7) << "\n";
    }
}