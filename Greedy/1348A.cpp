#include <bits/stdc++.h>
using namespace std;

long long binary_exponentiation(long long base, long long pow) {
    long long result = 1;
    while (pow) {
        if (pow&1) {
            result = (result * base);
        }
        base = (base*base);
        pow>>=1;
    }
    return result;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n;
        cin >> n;
        cout << binary_exponentiation(2, n/2 + 1) - 2 << "\n";
    }
}