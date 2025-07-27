#include <bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (long long i = 0; i<n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        long long ans(0);
        for (long long i = n-1; i>1; i--) {
            long long maximum = arr[n-1];
            bool taken = true;
            if (i!=n-1) {
                if (maximum < 2*arr[i]) {
                    taken = true;
                    maximum = arr[i];
                } else {
                    taken = false;
                }
            }
            long long right = i-1;
            long long left = 0;
            while (left<right) {
                while (left<right && (arr[left]+arr[right] + (taken ? 0 : arr[i]))<=maximum) {
                    left++;
                }
                ans += right-left;
                right--;
            }
        }
        cout << ans << "\n";
    }
}