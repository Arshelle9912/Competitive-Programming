#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<string> s1;
        set<string> s2;
        set<string> s2Pref;
        bool found = false;
        for (int i = 0; i<n; i++) {
            string temp;
            cin >> temp;
            string rev = temp;
            reverse(rev.begin(), rev.end());
            if (temp == rev) {
                found = true;
                continue;
            }
            if (temp.length()==3) {
                string sub = temp.substr(1,2);
                string rev = temp;
                reverse(rev.begin(), rev.end());
                if (s1.find(rev.substr(0,2))!=s1.end()) {
                    found = true;
                } else {
                    s2Pref.insert(temp.substr(0,2));
                    if (s2.find(rev)!=s2.end()) {
                        found = true;
                    } else {
                        s2.insert(temp);
                    }
                }
            } 
            if (temp.length()==2) {
                string rev = temp;
                reverse(rev.begin(), rev.end());
                if (s1.find(rev)!=s1.end()) {
                    found = true;
                } else if (s2Pref.find(rev)!=s2Pref.end()) {
                    found = true;
                } else {
                    s1.insert(temp);
                }
            }
        }
        if (found) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}