#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<char> se;
        bool check = false;
        for (int i = 0; i<n; i++) {
            if (se.find(s[i])!=se.end()) {
                if (i==n-1 && s[0]!=s[n-1]) {
                    check = true;
                } else if (i!=n-1){
                    check = true;
                }
            }
            se.insert(s[i]);
        }
        if (check) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
}