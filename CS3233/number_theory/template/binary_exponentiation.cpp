#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
long long binary_exponentiation(long long a, long long b) {
    a%=MOD;
    long long ans = 1;
    while (b>0) {
        if (b&1) {
            ans = (ans*a)%MOD;
        }
        a = (a*a)%MOD;
        b>>=1;
    }
    return ans;
}