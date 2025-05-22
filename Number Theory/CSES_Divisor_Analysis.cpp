#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
long long binary_exponentiation(long long base, long long pow) {
    long long result = 1;
    while (pow) {
        if (pow&1) {
            result = (result * base) % MOD;
        }
        base = (base*base) % MOD;
        pow>>=1;
    }
    return result;
}
int main() {
    long long prime[100001], exponent[100001];
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> prime[i] >> exponent[i];
    }
    long long no_of_divisors = 1, sum_of_divisors = 1, product_of_divisors = 1;
    for (int i = 0; i<n; i++) {
        no_of_divisors = (no_of_divisors *(exponent[i] + 1)) % MOD;
        sum_of_divisors = sum_of_divisors*(binary_exponentiation(prime[i], exponent[i]+1)-1)%MOD * binary_exponentiation(prime[i]-1, MOD-2) % MOD;
    }
    int flag = 0;
    int position;
    for (int i = 0; i<n; i++) {
        if (exponent[i]%2==1) {
            flag = 1;
            position = i;
        }
    }
    if (flag) {
        long long outer = 1;
        for (int i = 0; i<n; i++) {
            if (i == position) {
                outer = (outer * (exponent[i]+1)/2)%(MOD-1);
            } else {
                outer = (outer * (exponent[i]+1))%(MOD-1);
            }
        }
        for (int i = 0; i<n; i++) {
            product_of_divisors = (product_of_divisors * binary_exponentiation(prime[i], (exponent[i]*outer)%(MOD-1)))%MOD;
        }
    } else {
        long long outer = 1;
        for (int i = 0; i<n; i++) {
            outer = (outer * (exponent[i]+1)%(MOD-1));
        }
        for (int i = 0; i<n; i++) {
            product_of_divisors = (product_of_divisors * binary_exponentiation(prime[i], ((exponent[i]/2)*outer)%(MOD-1)))%MOD;
        }
    }
    cout << no_of_divisors << " " << sum_of_divisors << " " << product_of_divisors;
}