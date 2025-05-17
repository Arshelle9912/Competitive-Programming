#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        string s;
        cin >> s;
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i<s.length(); i++) {
            int temp = s[i]-'0';
            if (temp%2==0) {
                even.push_back(temp);
            } else {
                odd.push_back(temp);
            }
        }
        int pointer1(0), pointer2(0);
        while(pointer1<odd.size() && pointer2<even.size()) {
            if (odd[pointer1]>even[pointer2]) {
                cout << even[pointer2];
                pointer2++;
            } else {
                cout << odd[pointer1];
                pointer1++;
            }
        }
        while (pointer1<odd.size()) {
            cout << odd[pointer1];
            pointer1++;
        }
        while (pointer2<even.size()) {
            cout << even[pointer2];
            pointer2++;
        }
        cout << "\n";
    }
}