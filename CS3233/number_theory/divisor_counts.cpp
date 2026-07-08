#include <bits/stdc++.h>
using namespace std;
vector<long long> num_divisors(int n) {
    vector<long long> num_div(n+1, 1);
    vector<bool> isPrime(n+1, true);
    for (int i = 2; i<=n; i++) {
        if (isPrime[i]) {
            for (int j = i; j<=n; j+=i) {
                if (j>i) isPrime[j] = false;
                int cnt = 1;
                int num = j;
                while (num%i==0) {
                    num/=i;
                    cnt++;
                }
                num_div[j]*=(cnt);
            }
        }
    }
    return num_div;
}
int main() {
    int n;
    cin >> n;
    vector<long long> num_div = num_divisors(n);
    for (int i = 1; i<=n; i++) {
        printf("%lld\n", num_div[i]);
    }
}