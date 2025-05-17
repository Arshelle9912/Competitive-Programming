#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    long long sum(0);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    long long full = (k-1)/sum;
    long long remaining = k - full * sum;
    vector<long long> prefix(2*n+1);
    for (int i = 0; i<2*n; i++) {
        prefix[i+1] = prefix[i] + arr[i%n];
    }
    long long result = LLONG_MAX;
    int index = 1;
    for (int i = 0; i<n; i++) {
        int low = i+1, high = i+n, ans = high + 1;
        while (low<=high) {
            int mid = (low+high)/2;
            if (prefix[mid]-prefix[i]>=remaining) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        if (full * n + ans - i < result) {
            result = full * n + ans - i;
            index = i+1;
        }
    }
    cout << index << " " << result << endl;
}