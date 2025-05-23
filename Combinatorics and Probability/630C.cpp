#include <bits/stdc++.h>
using namespace std;

long long binary_exponentiation(long long base, long long power) {
    long long result = 1;
    while (power>0) {
        if (power&1) {
            result = result*base;
        }
        base = base*base;
        power>>=1;
    }
    return result;
}
int main() {
    int n;
    cin >> n;
    cout << binary_exponentiation(2, n+1) - 2 << "\n";
}