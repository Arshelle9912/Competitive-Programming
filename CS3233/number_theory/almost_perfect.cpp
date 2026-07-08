#include <bits/stdc++.h>
using namespace std;
long long sum_divisors(long long n) {
    long long ans = 1;
    for (int p = 2; p*p<=n; p++) {
        if (n%p==0) {
            long long curr = 1;
            long long term = 1;
            while (n%p==0) {
                n/=p;
                curr*=p;
                term+=curr;
            }
            ans*=term;
        }
    }
    if (n>1) ans*=(1+n);
    return ans;
}
int main() {
    long long n;
    while (scanf("%lld", &n)==1) {
        long long num = sum_divisors(n) - n;
        if (n==num) printf("%d perfect\n", n);
        else if (abs(n-num)<=2) printf("%d almost perfect\n", n);
        else printf("%d not perfect\n", n);
    }
}