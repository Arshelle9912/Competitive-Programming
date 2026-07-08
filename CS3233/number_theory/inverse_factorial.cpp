#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<string> small = {
        "",
        "1",
        "2",
        "6",
        "24",
        "120",
        "720",
        "5040",
        "40320",
        "362880"
    };
    for (int i = 1; i < (int)small.size(); i++) {
        if (s == small[i]) {
            cout << i << "\n";
            return 0;
        }
    }
    int len = s.size();
    double cur = 0.0;
    for (int i = 1; ; i++) {
        cur += log10((double)i);
        if ((int)cur + 1 == len) {
            cout << i << "\n";
            return 0;
        }
    }
}