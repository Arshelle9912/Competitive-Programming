// (1+power) for all divisors multiplied, eg (1+power1)*(1+power2).....
#include <bits/stdc++.h>
using namespace std;
long long num_divisors(long long n) {
    long long ans = 1;
    for (long long p = 2; p*p<=n; p++) {
        if (n%p==0) {
            int cnt = 0;
            while (n%p==0) {
                n/=p;
                cnt++;
            }
            ans*=(cnt+1);
        }
    }
    if (n>1) ans*=2;
    return ans;
}
int main() {
    long long n;
    cin >> n;
    printf("%lld\n", num_divisors(n));
}