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
        int count3(0);
        int need1, need2, last, first(INT_MAX);
        for (int i = 0; i<s.length(); i++) {
            if (s[i]=='(') {
                count1++;
            } else if (s[i]==')') {
                count2++;
            } else {
                count3++;
            }
        }
        if (count3==0 || count3==1) {
            cout << "YES" << "\n";
            continue;
        }
        need1 = s.length()/2 - count1;
        need2 = s.length()/2 - count2;
        int k(0);
        last = -1;
        while (k<s.length() && need1!=0) {
            if (s[k]=='?') {
                need1--;
                s[k] = '(';
                last = max(last,k);
            }
            k++;
        }
        while(k<s.length() && need2!=0) {
            if (s[k]=='?') {
                need2--;
                s[k] = ')';
                first = min(k, first);
            }
            k++;
        }
        if (last==-1 || first == INT_MAX) {
            cout << "YES" << "\n";
            continue;
        }
        s[last] = ')';
        s[first] = '(';
        count1=0, count2=0;
        bool check = false;
        for (int i = 0; i<s.length(); i++) {
            if (s[i]=='(') {
                count1++;
            } else {
                count2++;
            }
            if (count2>count1) {
                check = true;
                break;
            }
        }
        check ? cout << "YES" << "\n" : cout << "NO" << "\n";
    }
}