#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n%2!=0) {
        cout << 0 << endl;
    } else {
        long long k = n/2;
        long long five(0);
        for (long long i = 5; i<=k; i*=5) {
            five += k/i;
        }
        cout << five << endl;
    }
}