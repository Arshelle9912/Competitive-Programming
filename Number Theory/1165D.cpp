#include <bits/stdc++.h>
using namespace std;

vector<long long> all_divisors(long long X) {
    vector<long long> divs;
    for (long long i = 2; i * i <= X; ++i) {
        if (X % i == 0) {
            divs.push_back(i);
            if (i * i != X)
                divs.push_back(X / i);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> factors(n);
        for (long long i = 0; i<n; i++) {
            cin >> factors[i];
        }
        sort(factors.begin(), factors.end());
        long long possible = factors[0] * factors[n-1];
        long long temp = possible;
        vector<long long> divisors = all_divisors(possible);
        bool check = true;
        if (divisors.size()!=factors.size()) {
            cout << "-1" << "\n";
            continue;
        }
        for (long long i = 0; i<divisors.size(); i++) {
            if (divisors[i]!=factors[i]) {
                check = false;
                break;
            }
        }
        if (check) {
            cout << possible << "\n";
        } else {
            cout << "-1" << "\n";
        }
    }
}