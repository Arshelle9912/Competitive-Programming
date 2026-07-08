#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    if (b==0) {
        return a;
    }
    return gcd(b, a%b);
}
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;
        long long lcm = x*y/gcd(x, y);
        long long same = n/lcm;
        long long diffx = n/x-same;
        long long diffy = n/y-same;
        cout << (n-diffx)*diffx + (diffx)*(diffx+1)/2 - (diffy)*(diffy+1)/2 << "\n";
    }
}