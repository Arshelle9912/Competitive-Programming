#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
vector<bool> sieve(int n) {
    vector<bool> isPrime(n+1, true);
    if (n>=0) isPrime[0] = false;
    if (n>=1) isPrime[1] = false;
    for (int i = 2; 1LL*i*i<=n; i++) {
        if (isPrime[i]) {
            for (long long j = 1LL*i*i; j<=n; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}
int main() {
    vector<bool> isPrime = sieve(1e6);
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        int num;
        scanf("%d", &num);
        if (num==1) {
            printf("No\n");
            continue;
        }
        bool check = (isPrime[num] || isPrime[num-2]);
        if (num%2==0) check = true;
        if (check) printf("Yes\n");
        else printf("No\n");
    }
}