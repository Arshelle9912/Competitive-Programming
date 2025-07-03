#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
vector<long long> factorial(int n) {
    vector<long long> result(n+1,1);
    long long temp(1);
    for (int i = 1; i<=n; i++) {
        temp = (temp * i) % MOD;
        result[i] = temp;
    }
    return result;
}

long long binary_exponentiation(long long base, long long power) {
    long long result = 1;
    while (power>0) {
        if (power&1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        power >>= 1;
    }
    return result;
}

vector<long long> inverse_factorial(const vector<long long>& fact) {
    int N = fact.size() - 1;
    vector<long long> ifact(N+1);
    ifact[N] = binary_exponentiation(fact[N], MOD-2);
    for (int i = N; i > 0; i--)
        ifact[i-1] = ifact[i] * i % MOD;
    return ifact;
}

long long ncr(long long up, long long down, const vector<long long>& fact, const vector<long long>& ifact) {
    if (down < 0 || down > up) return 0;
    return fact[up] * ifact[down] % MOD * ifact[up-down] % MOD;
}
int main() {
    vector<long long> fact = factorial(1001);
    vector<long long> ifact = inverse_factorial(fact);
    int n;
    cin >> n;
    long long ans(0);
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    vector<long long> dp(n+2);
    dp[n+1] = 1;
    for (int i = n; i>0; i--) {
        int a = arr[i-1];
        if (a <= 0) {
            dp[i] = 0;
            continue;
        }
        for (int j = arr[i-1]+i+1; j<=n+1; j++) {
            dp[i] = (dp[i] + ncr(j-i-1, arr[i-1], fact, ifact)*dp[j])%MOD;
        }
    }
    for (int i = 1; i<=n; i++) {
        ans = (ans+dp[i])%MOD;
    }
    cout << ans << "\n";
}