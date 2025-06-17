#include <bits/stdc++.h>
using namespace std;

long long gcd (long long a, long long b) {
    if (b==0) {
        return a;
    }
    return gcd(b, a%b);
}
int main() {
    long long n, k;
    cin >> n >> k;
    long long LCM(1);
    for (int i = 1; i<=k; i++) {
        LCM = (i*LCM)/gcd(i, LCM);
        if (LCM>n+1) {
            break;
        }
    }
    if (LCM<=n+1 && (n+1)%LCM==0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}