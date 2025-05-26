#include <bits/stdc++.h>
using namespace std;

double binary_exponentiation(double base, long long power) {
    double result = 1;
    while (power>0) {
        if (power&1) {
            result = (result * base);
        }
        base = (base * base);
        power>>=1;
    }
    return result;
}

int main() {
    double n, k;
    cin >> n >> k;
    vector<double> prefix(k+1);
    prefix[0] = 0;
    double result(0);
    for (double i = 1; i<=k; i++) {
        prefix[i] = binary_exponentiation(i/k, n);
        result += i*(prefix[i] - prefix[i-1]);
    }
    cout << fixed << setprecision(6) << result << "\n";
}