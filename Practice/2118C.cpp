#include <bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> arr(n);
        for (long long i = 0; i<n; i++) {
            cin >> arr[i];
        }
        long long count(0);
        vector<long long> exponent(64);
        exponent[0] = 1;
        for (long long i = 1; i<=63; i++) {
            exponent[i] = exponent[i-1]*2;
        }
        for (long long i = 0; i<=63; i++) {
            for (long long j : arr) {
                if (!((j>>i)&1) && (k-exponent[i])>=0) {
                    count++;
                    k-=exponent[i];
                } else if ((j>>i)&1){
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
}