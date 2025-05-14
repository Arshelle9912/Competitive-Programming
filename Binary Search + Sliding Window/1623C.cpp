#include <bits/stdc++.h>
using namespace std;

bool checker(vector<int>, int);
int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n, ans;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j<n; j++) {
            cin >> arr[j];
        }
        int low = 0, high = 1e9;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (checker(arr, mid)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        cout << ans << endl;
    }
}

bool checker(vector<int> arr, int mid) {
    int n = arr.size();
    vector<int> a = arr;
    for (int i = n-1; i >=0; i--) {
        if (a[i] < mid) {
            return false;
        }
        long long excess = a[i]-mid;
        long long y = min(excess/3LL, arr[i]/3LL);
        a[i] -= 3*y;
        if (i > 1) {
             a[i-1] += y;
             a[i-2] += 2 * y;
        }
    }
    return true;
}



