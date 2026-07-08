#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
void sieve(int n) {
    vector<bool> isPrime(n+1, true);
    if (n>=0) isPrime[0] = false;
    if (n>=1) isPrime[1] = false;
    for (int i = 2; i<=n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            if (1LL*i*i<=n) {
                for (int j = i*i; j<=n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
    }
}
void factorize(long long n) {
    if (n<0) {
        cout << "-1 ";
        n = -n;
    }
    for (int p : primes) {
        if (1LL*p*p>n) break;
        if (n%p==0) {
            int cnt = 0;
            while (n%p==0) {
                n/=p;
                cnt++;
            }
            if (cnt>1) printf("%d^%d ", p, cnt);
            else printf("%d ", p);
        }
    }
    if (n>1) printf("%lld ", n);
    printf("\n");
}
int main() {
    sieve(50000);
    long long n;
    while (scanf("%lld", &n) == 1) {
        factorize(n);
    }
}