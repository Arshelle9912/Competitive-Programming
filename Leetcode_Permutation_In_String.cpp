#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length() > s2.length()) return false;
    vector<int> mps1(26, 0), freqWindow(26, 0);
    int lengths1= s1.length();
    int count = 0;
    for (char c:s1) {
        mps1[c - 'a']++;
    }
    for (int i = 0; i<s1.length(); i++) {
        freqWindow[s2[i] - 'a']++;
    }
    if (mps1 == freqWindow) {
        cout << boolalpha << true << endl;
        return 0;
    }
    for (int i = lengths1; i<s2.size(); i++) {
        freqWindow[s2[i] - 'a']++;
        freqWindow[s2[i-lengths1] - 'a']--;
        if (mps1 == freqWindow) {
            cout << boolalpha << true << endl;
            return 0;
        }
    }
    cout << boolalpha << false << endl;
    return 0;
}