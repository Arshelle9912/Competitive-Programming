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
        int ans(0);
        int i = 0;
        while (i<n) {
            if (arr[i]==0) {
                i++;
            } else if (arr[i]<=2) {
                bool flg = false;
                int k = i+1;
                while (k<n) {
                    if (arr[k]==0) {
                        break;
                    }
                    if (arr[k]<=2) {
                        flg = true;
                        k++;
                        break;
                    } else if (k+1<n && arr[k]<=4 && 0<arr[k+1] && arr[k+1]<=4) {
                        k+=2;
                    } else {
                        break;
                    }
                }
                ans+=(k-i)-flg;
                i=k;
            } else {
                ans++;
                i++;
            }
        }
        cout << ans << "\n";
    }
}