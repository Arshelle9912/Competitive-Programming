#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long ans = 0;
        vector<int> arr;
        for (int i = 0; i<n; i++) {
            for (int j = 1; j<=n; j++) {
                long long sum = i*n+j + ((j-1>0)? i*n+j-1 : 0) + ((j+1<=n)? i*n+j+1 : 0) + 
                ((i-1>=0)? (i-1)*n+j : 0) + ((i+1<n)? (i+1)*n+j : 0);
                ans = max(sum, ans);
            }
        }
        cout << ans << "\n";
    }
}