#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int prefix(0);
        bool negative(false), positive(false);
        vector<int> result;
        for (char c : s) {
            if (c=='(') {
                prefix++;
                if (prefix>0) {
                    positive = true;
                    s[0] == '(' ? result.push_back(1) : result.push_back(2);
                } else {
                    s[0] == '(' ? result.push_back(2) : result.push_back(1);
                }
            } else {
                prefix--;
                if (prefix<0) {
                    negative = true;
                    s[0] == '(' ? result.push_back(2) : result.push_back(1);
                } else {
                    s[0] == '(' ? result.push_back(1) : result.push_back(2);
                }
            }
        }
        if (prefix!=0) {
            cout << -1 << "\n";
            continue;
        }
        cout << positive + negative << "\n";
        for (auto x : result) {
            cout << x << " ";
        }
        cout << "\n";
    }
}