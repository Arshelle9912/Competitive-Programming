// n!/((r!)(n-r)!)
#include <bits/stdc++.h>
using namespace std;
long long ncr (long long n, long long r) {
    if (r<0 || r>n) return 0;
    r = min(r, n-r);
    long long ans = 1;
    for (long long i = 1; i<=r; i++) {
        ans = (ans*(n-r+i))/i;
    }
    return ans;
}