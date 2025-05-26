#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;
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
    int t;
    cin >> t;
    vector<long long> fact = factorial(1001);
    vector<long long> ifact = inverse_factorial(fact);
    for (int i = 0; i<t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int j = 0; j<n; j++) {
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end(), greater<int>());
        int num = arr[0];
        int count(1);
        for (int i = 1; i<k; i++) {
            if (num!=arr[i]) {
                num = arr[i];
                count = 1;
            } else {
                count++;
            }
        }
        int j = k;
        while (j < n && arr[j]==num) {
            count++;
            j++;
        }
        int top_k = k - (j-count);
        cout << ncr(count, top_k, fact, ifact) << "\n";
    }
}