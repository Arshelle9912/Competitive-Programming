#include <bits/stdc++.h>
using namespace std;
int smallestFactor(int n) {
    for (int i = 2; i*i<=n; i++) {
        if (n%i==0) {
            return i;
        }
    }
    return n;
}
int main() {
    int n;
    cin >> n;
    if (n==1) {printf("0\n"); return 0;}
    printf("%d\n", n-(n/smallestFactor(n)));
}