#include <bits/stdc++.h>
using namespace std;

int MOD = 1000000007;
long long factorial(int x) {
    long long result = 1;
    for (int i = 2; i<=x; i++) {
        result = (result*i)%MOD;
    }
    return result;
}

long long binary_exponentiation(long long base, int power) {
    long long result = 1;
    while(power>0) {
        if (power&1) {
            result = ((result%MOD)*(base%MOD))%MOD;
        }
        base = (base*base)%MOD;
        power>>=1;
    }
    return result;
}
int main() {
    long long n;
    cin >> n;
    long long F2 = factorial(2*n - 1);
    long long Fn = factorial(n);
    long long Fn1= factorial(n-1);
    long long invFn  = binary_exponentiation(Fn,  MOD-2);
    long long invFn1 = binary_exponentiation(Fn1, MOD-2);
    long long combination = ((F2 * invFn  % MOD) * invFn1)%MOD;
    cout << ((2*combination)%MOD-n+MOD)%MOD;
}