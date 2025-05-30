#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<char> ans = {'h', 'e', 'l', 'l', 'o'};
    int pointer = 0;
    for (int i = 0; i<s.length(); i++) {
        if (s[i]==ans[pointer]) {
            pointer++;
            if (pointer==5) {
                cout << "YES" << "\n";
                return 0;
            }
        }
    }
    cout << "NO" << "\n";
}