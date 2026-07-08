#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int until = 0;
        int total = 0;
        for (int i = 0; i<n; i++) {
            if (s[i]=='1') {
                until = i+k+1;
            } else if (i>=until) {
                total++;
            }
        }
        cout << total << "\n";
    }
}