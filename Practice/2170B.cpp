#include <bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long countPositive(0), sumOver(0);
        for (long long i = 0; i<n; i++) {
            long long temp;
            cin >> temp;
            if (temp>0) {
                countPositive++;
                if (temp>1) sumOver+=temp-1;
            }
        }
        cout << countPositive - max(0LL, n-sumOver-1) << "\n";
    }
}