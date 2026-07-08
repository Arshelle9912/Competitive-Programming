#include <bits/stdc++.h>
using namespace std;
vector<bool> isPrime;
int sieve(int n) {
    if (n>=0) isPrime[0] = false;
    if (n>=1) isPrime[1] = false;
    for (int i = 2; 1LL*i*i<=n; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j<=n; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) ans += isPrime[i];
    return ans;
}
int main() {
    int n, q;
    cin >> n >> q;
    isPrime.assign(n+1, true);
    int total = sieve(n);
    printf("%d\n", total);
    for (int i = 0; i<q; i++) {
        int num;
        cin >> num;
        printf("%d\n", (isPrime[num]) ? 1 : 0);
    }
}