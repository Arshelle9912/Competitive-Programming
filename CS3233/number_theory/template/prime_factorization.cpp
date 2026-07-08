#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, int>> prime_factorize(long long n) {
    vector<pair<long long, int>> factors;
    for (long long p = 2; p*p<=n; p++) {
        int cnt = 0;
        if (n%p==0) {
            while (n%p==0) {
                n/=p;
                cnt++;
            }
            factors.push_back({p, cnt});
        }
    }
    if (n>1) factors.push_back({n, 1});
    return factors;
}
int main() {

}