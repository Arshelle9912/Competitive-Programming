#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double h, c, target;
        cin >> h >> c >> target;
        if (h==target) {
            cout << 1 << "\n";
            continue;
        } else if ((h+c)/2>=target) {
            cout << 2 << "\n";
            continue;
        }
        int low(1), high = 1e8;
        int ans(0);
        while (low<=high) {
            int mid = (low) + (high-low)/2;
            int k = 2*mid+1;
            if ((h*(mid+1)+c*mid)/k>target) {
                low = mid+1;
            } else {
                ans = k;
                high = mid-1;
            }
        }
        (llabs( ((ans-2+1)/2LL)*h + ((ans-2-1)/2LL)*c - (long long)target*(ans-2) ) * ans<=llabs(((ans+1)/2LL)*h + ((ans-1)/2LL)*c - (long long)target*ans) * (ans-2))
        ? cout << ans-2 << "\n"
        : cout << ans   << "\n";
    }
}