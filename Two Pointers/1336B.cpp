#include <bits/stdc++.h>
using namespace std;

long long cost(long long x, long long y, long long z) {
    return (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
}
long long solve(vector<int> a, vector<int> b, vector<int> c) {
    long long best = LLONG_MAX;
    for (long long y:b) {
        auto itA = upper_bound(a.begin(), a.end(), y);
        if (itA == a.begin()) {
            continue;
        }
        long long x = *prev(itA);
        auto itC = lower_bound(c.begin(), c.end(), y);
        if (itC == c.end()) {
            continue;
        }
        long long z = *itC;
        best = min(best, cost(x, y, z));
    }
    return best;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int nr, ng, nb;
        cin >> nr >> ng >> nb;
        vector<int> red(nr); vector<int> green(ng); vector<int> blue(nb);
        vector<int> balls(nr+ng+nb);
        int temp;
        for (int i = 0; i<nr; i++) {
            cin >> red[i];
        }
        for (int i = 0; i<ng; i++) {
            cin >> green[i];
        }
        for (int i = 0; i<nb; i++) {
            cin >> blue[i];
        }
        sort(red.begin(), red.end());
        sort(green.begin(), green.end());
        sort(blue.begin(), blue.end());
        long long ans = LLONG_MAX;
        ans = min(ans, solve(red, green, blue));
        ans = min(ans, solve(red, blue, green));
        ans = min(ans, solve(green, red, blue));
        ans = min(ans, solve(green, blue, red));
        ans = min(ans, solve(blue, red, green));
        ans = min(ans, solve(blue, green, red));

        cout << ans << "\n";
    }
}