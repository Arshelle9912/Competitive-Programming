#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
vector<int> primes;
void sieve() {
    const int N = 2000000;
    vector<bool> isPrime(N+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}
ull mulmod(ull a, ull b, ull m) {
    return (__uint128_t)a * b % m;
}
ull powmod(ull a, ull b, ull m) {
    ull res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = mulmod(res, a, m);
        a = mulmod(a, a, m);
        b >>= 1;
    }
    return res;
}
bool miller_rabin(ull n, ull a) {
    if (n % a == 0) return n == a;
    ull d = n - 1;
    int r = 0;
    while (d % 2 == 0) { d /= 2; r++; }
    ull x = powmod(a, d, n);
    if (x == 1 || x == n - 1) return true;
    for (int i = 0; i < r - 1; i++) {
        x = mulmod(x, x, n);
        if (x == n - 1) return true;
    }
    return false;
}
bool isPrime(ull n) {
    if (n < 2) return false;
    for (ull p : primes) {
        if (p * p > n) break;
        if (n % p == 0) return n == p;
    }
    for (ull a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (!miller_rabin(n, a)) return false;
    }
    return true;
}
ull isqrt(ull n) {
    ull r = sqrtl(n);
    while (r*r > n) r--;
    while ((r+1)*(r+1) <= n) r++;
    return r;
}
ull divisorCount(ull n) {
    ull ans = 1;
    for (ull p : primes) {
        if (p*p*p > n) break;
        if (n % p == 0) {
            int c = 0;
            while (n % p == 0) { n /= p; c++; }
            ans *= c + 1;
        }
    }
    if (n == 1) return ans;
    if (isPrime(n)) return ans * 2;
    ull r = isqrt(n);
    if (r*r == n) return ans * 3;
    return ans * 4;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        ull n;
        cin >> n;
        cout << divisorCount(n) << "\n";
    }
}