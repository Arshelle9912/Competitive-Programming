#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> factors(long long n) {
    vector<pair<long long, long long>> factor;
    if (n % 2 == 0) {
        long long cnt = 0;
        while (n % 2 == 0) {
            n /= 2;
            cnt++;
        }
        factor.push_back({2, cnt});
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            long long cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            factor.push_back({i, cnt});
        }
    }
    if (n > 1) factor.push_back({n, 1});
    return factor;
}
int main() {
    long long n, m;
    while (scanf("%lld %lld", &n, &m)==2) {
        if (m == 0) {
            printf("%lld does not divide %lld!\n", m, n);
            continue;
        }
        if (m == 1) {
            printf("%lld divides %lld!\n", m, n);
            continue;
        }
        if (m <= n) {
            printf("%lld divides %lld!\n", m, n);
            continue;
        }
        vector<pair<long long, long long>> factor = factors(m);
        bool check = true;
        for (auto [num, cnt] : factor) {
            long long ncnt = 0;
            long long curr = num;
            while (curr<=n) {
                ncnt+=(n/curr);
                if (ncnt>=cnt) break;
                if (curr > n / num) break;
                curr*=num;
            }
            if (ncnt<cnt) {check = false; break;}
        }
        if (check) printf("%lld divides %lld!\n", m, n);
        else printf("%lld does not divide %lld!\n", m, n);
    }
}