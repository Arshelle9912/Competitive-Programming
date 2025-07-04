#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int count1(0);
        int count2(0);
        int count(0);
        for (char c : s) {
            if (c=='(') {
                count1++;
            } else {
                count2++;
                if (count1==count2) {
                    count++;
                }
            }
        }
        if (count>=2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}