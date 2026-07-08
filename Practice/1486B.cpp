#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> x(n);
        vector<long long> y(n);
        for (long long i = 0; i<n; i++) {
            cin >> x[i] >> y[i];
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        long long xpoints = x[n/2] - x[(n-1)/2] + 1;
        long long ypoints = y[n/2] - y[(n-1)/2] + 1;
        cout << xpoints * ypoints << "\n";
    }
} 