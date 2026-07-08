#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, a0, b, c, m;
    cin >> n >> m >> b >> c >> a0;
    vector<long long> a(n);
    long long curr = a0;
    for (int i = 0; i<n; i++) {
        curr = (b * curr + c) % m;
        a[i] = curr;
    }
    int ans = 0;
    for (int i = 0; i<n; i++) {
        int low = 0, high = n - 1;
        bool ok = true;
        while (low<=high) {
            int mid = (low+high)/2;
            if (mid==i) break;
            if (mid<i) {
                if (a[mid]<a[i]) {
                    low=mid+1;
                } else {
                    ok = false;
                    break;
                }
            } else {
                if (a[mid]>a[i]) {
                    high = mid-1;
                } else {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) ans++;
    }
    printf("%d\n", ans);
}