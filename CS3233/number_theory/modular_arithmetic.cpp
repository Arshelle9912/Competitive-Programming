#include <bits/stdc++.h>
using namespace std;
long long extended_euclidean(long long a, long long b, long long &x, long long &y) {
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    int g = extended_euclidean(b, a%b, x1, y1);
    x = y1;
    y = x1-(a/b)*y1;
    return g;
}   
int main() {
    long long mod, n;
    while (scanf("%lld %lld", &mod, &n)==2) {
        for (int i = 0; i<n; i++) {
            long long num1, num2;
            char op;
            cin >> num1 >> op >> num2;
            if (op=='/') {
                long long x, y;
                long long g = extended_euclidean(num2, mod, x, y);
                if (g!=1) printf("-1\n");
                else printf("%lld\n", ((x*num1)%mod+mod)%mod);
            } else if (op=='-') {
                printf("%lld\n", ((num1-num2)%mod+mod)%mod);
            } else if (op=='+') {
                printf("%lld\n", (num1+num2)%mod);
            } else {
                printf("%lld\n", (num1*num2)%mod);
            }
        }
    }
}