#include <bits/stdc++.h>
using namespace std;
long long euler_phi(long long n) {
    long long ans = n;
    for (long long p = 2; p*p<=n; p++) {
        if (n%p==0) {
            ans -= ans/p;
            while (n%p==0) {
                n/=p;
            }
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}
int main() {
    while (true) {
        long long n;
        cin >> n;
        if (n==0) break;
        printf("%lld\n", euler_phi(n));
    }
}