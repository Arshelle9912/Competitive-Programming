#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        long long g(0);
        for (int i = 0; i<n/2; i++) {
            long long d = llabs(arr[i]-arr[n-i-1]);
            g = gcd(g, d);
        }
        cout << g << "\n";
    }
}