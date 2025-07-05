#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

static ull smallest(ull l, ull left, ull right) {
    ull cand = left;
    while (cand <= right) {
        if ((cand & l) == 0) {
            return cand;
        }
        ull clash = cand & l;
        ull low = clash & -clash;
        cand = (cand | (low - 1)) + 1;
    }
    return ULLONG_MAX;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, l, r, k;
        cin >> n >> l >> r >> k;

        if (n % 2 != 0) {
            cout << l << "\n";
            continue;
        }

        if (n == 2) {
            cout << -1 << "\n";
            continue;
        }
        ull y = smallest((ull)l, (ull)(l+1), (ull)r);
        if (y == ULLONG_MAX) {
            cout << -1 << "\n";
            continue;
        }
        if (k <= n - 2) {
            cout << l << "\n";
        } else {
            cout << y << "\n";
        }
    }
    return 0;
}
