#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool check = false;
        int ans;
        // Can do binary search as well after making an array log n solution
        for (int i = 0; i<100; i++) {
            if ((i*i) == stoi(s)) {
                check = true;
                ans = i;
                break;
            }
        }
        if (check) {
            cout << "0" << " " << ans << "\n";
        } else {
            cout << "-1" << "\n";
        }
    }
}