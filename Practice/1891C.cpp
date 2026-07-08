#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (long long i = 0; i<n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        long long left = 0;
        long long right = n-1;
        long long curr = 0;
        long long ans = 0;
        while (left<right) {
            if (arr[right]>arr[left]+curr) {
                curr+=arr[left];
                ans+=arr[left];
                left++;
            } else if (arr[right]<arr[left]+curr) {
                long long val = arr[right]-curr;
                ans+=val+1;
                arr[left]-=val;
                right--;
                curr=0;
            } else {
                ans+=arr[left]+1;
                left++;
                right--;
                curr=0;
            }
        }
        if (left==right) {
            long long diff = (arr[right]-curr)/2;
            ans += diff;
            curr+=diff;
            arr[right]-=diff;
            if (curr>0) ans++;
            if (arr[right]-curr>0) ans++;
        }
        cout << ans << "\n";
    }
}