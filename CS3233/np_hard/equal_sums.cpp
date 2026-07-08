#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    int count = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        map<int, int> mp;
        for (int mask = 0; mask<(1<<n); mask++) {
            int sum = 0;
            for (int i = 0; i<n; i++) {
                if (mask&(1<<i)) {
                    sum+=arr[i];
                }
            }
            if (mp.count(sum)) {
                int pos = mp[sum];
                printf("Case #%d:\n", count);
                for (int i = 0; i<n; i++) {
                    if (pos&(1<<i)) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                for (int i = 0; i<n; i++) {
                    if (mask&(1<<i)) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;
            }
            mp[sum] = mask;
        }
        count++;
    }
}