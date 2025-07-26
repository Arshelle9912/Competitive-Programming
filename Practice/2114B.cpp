#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int count0(0);
        int count1(0);
        string s;
        cin >> s;
        for (int i = 0; i<n; i++) {
            if (s[i]=='0') {
                count0++;
            } else {
                count1++;
            }
        }
        int maximum = count0/2 + count1/2;
        int minimum = abs(count0-count1)/2;
        if (k<minimum || k>maximum) {
            cout << "NO" << "\n";
        } else if ((minimum%2!=0 && k%2==0) || (minimum%2==0 && k%2!=0)) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}