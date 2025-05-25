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
    int gifts, boxes;
    cin >> gifts >> boxes;
    cout << binary_exponentiation(binary_exponentiation(2,boxes)-1, gifts) << "\n";
}