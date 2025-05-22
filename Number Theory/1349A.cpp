#include <bits/stdc++.h>
using namespace std;

vector<int> spf(int x) {
    vector<int> spf(x+1);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i*i<=x; i++) {
        if (spf[i]==i) {
            for (int j = i*i; j<=x; j+=i) {
                if (spf[j]==j) {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

long long binary_exponentiation(long long base, long long power) {
    long long result = 1;
    while (power>0) {
        if (power&1) {
            result = result * base;
        }
        base = base*base;
        power>>=1;
    }
    return result;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    vector<long long> minimum(200001, INT_MAX);
    vector<long long> second_min(200001, INT_MAX);
    vector<int> count(200001);
    vector<int> factors = spf(200000);
    set<long long> primes_used;
    for (int i = 0; i<n; i++) {
        while (arr[i]!=1) {
            int factor = factors[arr[i]];
            int power = 0;
            while (arr[i]%factor==0) {
                arr[i]/=factor;
                power++;
            }
            primes_used.insert(factor);
            count[factor]++;
            if (power<minimum[factor]) {
                second_min[factor] = minimum[factor];
                minimum[factor] = power;
            } else if (power<second_min[factor]) {
                second_min[factor] = power;
            }
        }
    }
    long long gcd(1);
    for (long long x : primes_used) {
        if (count[x]==n) {
            gcd*=binary_exponentiation(x, second_min[x]);
        } else if (count[x]==n-1) {
            gcd*=binary_exponentiation(x, minimum[x]);
        }
    }
    cout << gcd << "\n";
}