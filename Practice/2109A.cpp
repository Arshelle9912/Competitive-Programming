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
        int count(0);
        bool check = true;
        for (int i = 0; i<n; i++) {
            if (arr[i]==0) {
                count++;
                if (i>0 && arr[i]==arr[i-1]) {
                    check = false;
                }
            }
        }
        if (arr[n-1]==1 && count==0) {
            check = false;
        }
        if (!check) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}