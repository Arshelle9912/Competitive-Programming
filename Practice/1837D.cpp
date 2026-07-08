#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<char> st;
        int count = 0;
        int sz = s.size();
        set<int> indexes;
        int bracket = 0;
        for (int i = 0; i<sz; i++) {
            if (s[i]=='(') {
                bracket++;
                if (count>0) {
                    count--;
                    indexes.insert(i);
                    continue;
                }
                st.push(s[i]);
            } else {
                if (!st.empty()) {
                    st.pop();
                } else {
                    count++;
                    indexes.insert(i);
                }
            }
        }
        if (bracket*2!=sz) {
            cout << -1 << "\n";
            continue;
        }
        if (indexes.size()==0 || indexes.size()==n) {
            cout << "1" << "\n";
            for (int i = 0; i<n; i++) {
                cout << "1" << " ";
            }
            cout << "\n";
            continue;
        }
        cout << 2 << "\n";
        for (int i = 0; i<n; i++) {
            if (indexes.find(i)==indexes.end()) cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << "\n";
    }
}