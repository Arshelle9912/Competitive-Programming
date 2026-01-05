#include <bits/stdc++.h>
using namespace std;
bool checker(int mid, vector<pair<int, int>>& arr) {
    int low = 0;
    int high = 0;
    for (auto p : arr) {
        if (high+mid<p.first || low-mid>p.second) return false;
        high = min(p.second, high + mid);
        low = max(p.first, low-mid);
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i<n; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            arr.push_back({temp1, temp2});
        }
        int low = 0; 
        int high = 1000000001;
        int ans = INT_MAX;
        while (low<=high) {
            int mid = (low+high)/2;
            if (checker(mid, arr)) {
                ans = min(mid, ans);
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        cout << ans << "\n";
    }
}