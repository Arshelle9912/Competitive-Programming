#include <bits/stdc++.h>
using namespace std;
bool checker(long long mid, vector<long long>& arr) {
    long long n = arr.size();
    long long rem = 0;
    for (long long i = 0; i<n; i++) {
        if (arr[i]>mid) rem+=arr[i]-mid;
        else rem-=(mid-arr[i])/2;
    }
    return rem<=0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        vector<long long> arr(n);
        for (long long i = 0; i<m; i++) {
            long long num;
            cin >> num;
            --num;
            arr[num]++;
        }
        long long low = 0;
        long long high = 2*m;
        long long ans;
        while (low<=high) {
            long long mid = (low+high)/2;
            if (checker(mid, arr)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        cout << ans << "\n";
    }
}