#include <bits/stdc++.h>
using namespace std;
long long ncr(long long n, long long m) {
    long long ans = 1;
    m = min(m, n-m);
    for (int i = 1; i<=m; i++) {
        ans = (ans*(n-m+i))/i;
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        printf("%lld\n", ncr(n, m-1));
    }
}