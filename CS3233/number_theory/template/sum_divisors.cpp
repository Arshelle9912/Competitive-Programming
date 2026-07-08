#include <bits/stdc++.h>
using namespace std;
long long sum_of_divisors(long long n) {
    long long ans = 1;
    for (long long p = 2; p*p<=n; p++) {
        long long term = 1;
        long long curr = 1;
        if (n%p==0) {
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

}