#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    bool flag = false;
    bool zeroStart = false;
    int i = 0;
    int ans(0);
    while (i<n) {
        if (arr[i]==0 && flag) {
            i++;
            flag = false;
            continue;
        } else if (arr[i]==0 && !flag) {
            ans++;
            zeroStart = true;
            i++;
        } else if (arr[i]==1 || arr[i]==2) {
            ans++;
        }
        int count2(0);
        while (i<n && (arr[i]==1 || arr[i]==2)) {
            if (arr[i]==2) {
                count2++;
            }
            if (zeroStart && arr[i]==1 && (count2==0)) {
                flag = false;
            } else {
                flag = true;
            }
            i++;
        }
        zeroStart = false;
    }
    cout << ans << "\n";
}