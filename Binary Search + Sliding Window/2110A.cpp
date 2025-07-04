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
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int result;
        int ans1(0);
        int ans2(0);
        int left(0), right(n-1);
        while (left<right && (arr[left]+arr[right])%2!=0) {
            left++;
            ans1++;
        }
        left = 0;
        while (left<right && (arr[left]+arr[right])%2!=0) {
            right--;
            ans2++;
        }
        cout << min(ans1, ans2) << "\n";
    }
}