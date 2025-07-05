#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> freq(n+1);
        vector<int> pref(n+1);
        vector<int> diff(n+2);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }
        int check = 0;
        while (check<=n && freq[check]) {
            check++;
        }
        for (int i = 0; i<=check; i++) {
            diff[freq[i]]++;
            diff[n-i+1]--;
        }
        pref[0] = diff[0];
        for (int i = 1; i<=n; i++) {
            pref[i] = (pref[i-1]+diff[i]);
        }
        for (int i = 0; i<=n; i++) {
            cout << pref[i] << " ";
        }
        cout << "\n";
    }
}