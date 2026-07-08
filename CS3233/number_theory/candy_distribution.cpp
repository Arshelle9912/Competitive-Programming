#include <bits/stdc++.h>
using namespace std;
long long extended_euclidean(long long a, long long b, long long &x, long long &y) {
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extended_euclidean(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long k, c;
        cin >> k >> c;
        if (k == 1) {
            if (c == 1) printf("2\n");
            else printf("1\n");
            continue;
        }
        long long x, y;
        long long gcd = extended_euclidean(c, k, x, y);
        if (gcd!=1) printf("IMPOSSIBLE\n");
        else {
            if (c==1) {k+1<=1e9 ? printf("%lld\n", k+1) : printf("IMPOSSIBLE\n"); continue;}
            long long ans = (x%k+k)%k;
            if (ans>1e9) printf("IMPOSSIBLE\n");
            else printf("%lld\n", ans);
        }
    }
}