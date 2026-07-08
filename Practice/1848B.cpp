#include <bits/stdc++.h>
using namespace std;
bool checker(int mid, vector<vector<int>>& colors, int n, int k) {
    for (int col = 1; col<=k; col++) {
        int bad = 0;
        int badgap = 0;
        int prev = 0;
        for (int p : colors[col]) {
            int gap = p-prev-1;
            if (gap>mid) {
                bad++;
                badgap = gap;
            }
            prev = p;
        }
        int gap = n-prev;
        if (gap>mid) {
            bad++;
            badgap = gap;
        }
        if (bad==0) return true;
        if (bad==1 && badgap/2<=mid) return true; 
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> colors(k+1);
        for (int i = 1; i<=n; i++) {
            int num;
            cin >> num;
            colors[num].push_back(i);
        }
        int low = 0;
        int high = n;
        int ans;
        while (low<=high) {
            int mid = low+(high-low)/2;
            if (checker(mid, colors, n, k)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        cout << ans << "\n";
    }
}