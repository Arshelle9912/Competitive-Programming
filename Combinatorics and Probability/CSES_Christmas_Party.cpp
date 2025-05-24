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

vector<long long> factorial(long long x) {
    long long result = 1;
    vector<long long> ans(x+1);
    ans[0] = 1, ans[1]=1;
    for (int i = 2; i<=x; i++) {
        result = (result * i) % MOD;
        ans[i] = result;
    }
    return ans;
}
int main() {
    long long n;
    long long result(0);
    cin >> n;
    vector<long long> fact = factorial(n);
    for (int i = 2; i<=n; i++) {
        if (i%2==0) {
            result = (result+binary_exponentiation(fact[i], MOD-2))%MOD;
        } else {
            result = (result-binary_exponentiation(fact[i], MOD-2)+MOD)%MOD;
        }
    }
    cout << (result*fact[n])%MOD << "\n";
}