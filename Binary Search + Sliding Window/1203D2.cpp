#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    vector<int> left;
    vector<int> right;
    int j(0);
    for (int i = 0; i<s.length(); i++) {
        if (t[j]==s[i]) {
            j++;
            left.push_back(i);
            if (j>t.length()-1) {
                break;
            }
        }
    }
    j=t.length()-1;
    for (int i = s.length()-1; i>=0; i--) {
        if (t[j]==s[i]) {
            j--;
            right.push_back(i);
            if (j<0) {
                break;
            }
        }
    }
    int maximum = INT_MIN;
    reverse(right.begin(), right.end());
    maximum = max((long long) s.length()-left[t.length()-1]-1, (long long) right[0]);
    for (int i = 0; i<t.length()-1; i++) {
        maximum = max(right[i+1]-left[i]-1, maximum);
    }
    cout << maximum;
}