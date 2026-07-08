#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    while (scanf("%lld", &n)==1) {
        long long count = 1;
        long long r = 1 % n;
        while (r!=0) {
            r = ((10*r)+1)%n;
            count++;
        }
        printf("%lld\n", count);
    }
}