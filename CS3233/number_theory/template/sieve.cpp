#include <bits/stdc++.h>
using namespace std;
vector<bool> sieve(int n) {
    vector<bool> isPrime(n+1, true);
    if (n>=0) isPrime[0] = false;
    if (n>=1) isPrime[1] = false;
    for (int i = 2; 1LL*i*i<=n; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j<=n; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}