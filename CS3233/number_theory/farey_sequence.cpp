#include <bits/stdc++.h>
using namespace std;
vector<int> euler_sieve(int n) {
    vector<double> euler(n+1, 0);
    vector<bool> isPrime(n+1, true);
    iota(euler.begin(), euler.end(), 0);
    for (int p = 2; p<=n; p++) {
        if (isPrime[p]) {
            for (int j = p; j<=n; j+=p) {
                if (j>p) isPrime[j] = false;
                euler[j]-=euler[j]/p;
            }
        }
    }
    euler[1]++;
    vector<int> prefEuler(n+1);
    for (int i = 1; i<=n; i++) {
        prefEuler[i] = prefEuler[i-1]+euler[i];
    }
    return prefEuler;
}
int main() {
    int t;
    cin >> t;
    vector<int> euler = euler_sieve(10000);
    while (t--) {
        int num, n;
        cin >> num >> n;
        printf("%d %d\n", num, euler[n]);
    }
}