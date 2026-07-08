#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        if (k>=3) {
            cout << 0 << "\n";
            continue;
        }
        vector<long long> narr;
        for (int i = 0; i<n; i++) {
            for (int j = i+1; j<n; j++) {
                narr.push_back(llabs(arr[j]-arr[i]));
            }
        }
        if (k==1) {
            long long ans = *min_element(arr.begin(), arr.end());;
            for (int i = 0; i<narr.size(); i++) {
                ans = min(ans, narr[i]);
            }
            cout << ans << "\n";
            continue;
        }
        sort(arr.begin(), arr.end());
        sort(narr.begin(), narr.end());
        long long ans = min(arr[0], narr[0]);
        int i = 0;
        int j = 0;
        while (i<narr.size() && j<n) {
            ans = min(ans, llabs(arr[j]-narr[i]));
            if (arr[j]>narr[i]) i++;
            else j++;
        }
        cout << ans << "\n";
    }
}