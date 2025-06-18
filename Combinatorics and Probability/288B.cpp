#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;
long long binary_exponentiation(long long base, long long power) {
    long long result = 1;
    while (power>0) {
        if (power&1) {
            result = (result * base)%MOD;
        }
        base = (base * base) % MOD;
        power>>=1;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << (1LL * binary_exponentiation(k, k-1) * binary_exponentiation(n-k, n-k)) % MOD << "\n";
}