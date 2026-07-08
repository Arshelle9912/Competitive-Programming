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
        long long ans = 0;
        vector<long long> arr(n);
        for (long long i = 0; i<n; i++) {
            cin >> arr[i];
            ans ^= arr[i];
        }
        if (ans==0) {cout << "YES\n"; continue;}
        long long count = 0;
        long long curr = 0;
        for (long long num : arr) {
            curr ^= num;
            if (curr == ans) {
                count++;
                curr = 0;
            }
        }
        if (count>=3) cout << "YES\n";
        else cout << "NO\n";
    }
}