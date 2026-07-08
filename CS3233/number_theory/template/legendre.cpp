// counts the power of p the prime factor p has in n!
#include <bits/stdc++.h>
using namespace std;
long long legendre(long long n, long long p) {
    long long ans = 0;
    while (n>0) {
        n/=p;
        ans+=n;
    }
    return ans;
}
int main() {

}