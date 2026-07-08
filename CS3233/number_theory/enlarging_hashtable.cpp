#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
    if (n<2) return false;
    if (n==2) return true;
    if (n%2==0) return false;
    for (int i = 3; 1LL*i*i<=n; i+=2) {
        if (n%i==0) return false;
    }
    return true;
}
int main() {
    while (true) {
        long long n;
        cin >> n;
        if (n==0) break;
        long long i = 2*n+1;
        while (!isPrime(i)) {
            i+=2;
        }
        if (!isPrime(n)) printf("%lld (%lld is not prime)\n", i, n);
        else printf("%lld\n", i);
    }
}