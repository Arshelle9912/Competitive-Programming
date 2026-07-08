#include <bits/stdc++.h>
using namespace std;
int main() {
    while (true) {
        long long x, y, n;
        long double r;
        scanf("%lld %lld %lld %Lf", &x, &y, &n, &r);
        if (x==0 && y==0 && n==0 && r==0) break;
        if (r==0) {
            long long amt = x - y * 12 * n;
            if (amt <= 0) printf("YES\n");
            else printf("NO\n");
            continue;
        }
        long double a = (1+r/1200);
        long double power = pow(a, 12*n);
        long double amt = x*power - y*((power-1)/(a-1));
        if (amt<=0) printf("YES\n");
        else printf("NO\n");
    }
}