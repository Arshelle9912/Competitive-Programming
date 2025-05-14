#include <bits/stdc++.h>
using namespace std;

bool checker(const vector<long long> &a, long long mid, long long k, long long sum) {
    if (sum-mid <= k) {
        return true;
    } 
    for (long long i = (long long)a.size()-1; i>=max(1LL, (long long)a.size()-mid); i--) {
        sum -= a[i];
        long long left = mid - ((long long)a.size()-i);
        long long tempSum = sum - a[0] + ((long long)a.size() - i + 1) * (a[0]-left);
        if (tempSum<=k) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        long long n, k, ans(1e10), sum(0);
        cin >> n >> k;
        vector<long long> arr(n);
        for (int j = 0; j<n; j++) {
            cin >> arr[j];
        }
        long long low = 0, high = 1e10;
        sort(arr.begin(), arr.end());
        for (int a = 0; a<n; a++) {
            sum += arr[a];
        }
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (checker(arr, mid, k, sum)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}