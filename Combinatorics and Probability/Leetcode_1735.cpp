#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

vector<int> spf(int x) {
    vector<int> spf(x+1);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i*i<=x; i++) {
        if (spf[i]==i) {
            for (int j = i*i; j<=x; j+=i) {
                if (spf[j]==j) {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

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
vector<int> waysToFillArray(vector<vector<int> >& queries) {
    int number = queries.size();
    vector<int> result(number, 1);
    vector<long long> fact = factorial(11000);
    vector<long long> ifact = inverse_factorial(fact);
    for (int i = 0; i<number; i++) {
        int n = queries[i][0];
        int k = queries[i][1];
        vector<int> smallest_primes = spf(k);
        while(k>1) {
            int prime = smallest_primes[k];
            int power = 0;
            while (k%prime==0) {
                k/=prime;
                power++;
            }
            result[i] = (result[i] * ncr(n+power-1, n-1, fact, ifact)) % MOD;
        }
    }
    return result;
}
int main() {
    int number;
    cin >> number;
    vector<vector<int> > queries(number, vector<int> (2));
    for (int i = 0; i<number; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    auto ans = waysToFillArray(queries);
    for (int x : ans) {
        cout << x << '\n';
    }
}