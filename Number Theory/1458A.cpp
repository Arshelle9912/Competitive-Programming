#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a%b);
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    long long divisor = 0;
    for (int i = 0; i<n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i<n; i++) {
        divisor = gcd(divisor, llabs(a[i]-a[i-1]));
    }
    for (int i = 0; i<m; i++) {
        cin >> b[i];
        cout << gcd(a[0]+b[i], divisor) << " ";
    }
}