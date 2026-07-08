// This theorem calculates the mod inverse but it only works for prime numbers
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
long long binary_exponentiation(long long a, long long b) {
    a %= MOD;
    long long ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
long long mod_inverse(long long a) {
    return binary_exponentiation(a, MOD - 2);
}
int main() {

}