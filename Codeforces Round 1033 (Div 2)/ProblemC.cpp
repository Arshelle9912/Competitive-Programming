#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        long long maxSum = n*(n+1)/2;
        if (m < n || m > maxSum) {
            cout << -1 << "\n";
            continue;
        }
        set<long long> s;
        for (long long i = 1; i<=n; i++) {
            s.insert(i);
        }
        long long last;
        long long root = m - (n - 1);
        if (root >= 1 && root <= n) {
            cout << root << "\n";
            if (root != 1) {
                cout << root << " " << 1 << "\n";
            }
            for (long long v = 2; v <= n; v++) {
                if (v == root) continue;
                cout << 1 << " " << v << "\n";
            }
            continue;
        }
        cout << n << "\n";
        long long remain = m-n;
        long long count = 1;
        last = n;
        s.erase(n);
        while (last!=1) {
            long long need = remain - (n - count - 1);
            auto it = s.upper_bound((long long) need);
            --it;
            long long v = *it;
            s.erase(it);
            cout << last << " " << v << "\n";
            last = v;
            remain -= v;
            count++;
        }
        for (long long v : s) {
            cout << 1 << " " << v << "\n";
        }
    }
}