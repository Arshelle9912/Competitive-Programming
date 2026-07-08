#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            string temp;
            int num;
            cin >> temp >> num;
            arr[i] = num;
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i<n; i++) {
            ans+= abs(arr[i]-i-1);
        }
        printf("%d\n", ans);
    }
}