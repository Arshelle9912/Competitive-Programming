#include <bits/stdc++.h>
using namespace std;

int MOD = 998244353;
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
    int n;
    cin >> n;
    vector<long long> fact = factorial(n/3);
    vector<long long> ifact = inverse_factorial(fact);
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    long long result = 1;
    for (int i = 0; i<n; i+=3) {
        vector<int> temp = { arr[i], arr[i+1], arr[i+2] };
        sort(temp.begin(), temp.end(), greater<int>());
        if (temp[0]==temp[1] && temp[1]==temp[2]) {
            result = (result*3)%MOD;
        } else if (temp[1]==temp[2]) {
            result = (result*2)%MOD;
        }
    }
    int combinations = ncr(n/3, n/6, fact, ifact);
    cout << (result*combinations)%MOD << "\n";
}