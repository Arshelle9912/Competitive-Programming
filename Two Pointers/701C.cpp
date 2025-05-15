#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<int, int> mp1, mp2;
    int result(INT_MAX), len;
    int low(0);
    for (int i = 0; i<n; i++) {
        mp1[s[i]]++;
    }
    len = mp1.size();
    for (int i = 0; i<n; i++) {
        mp2[s[i]]++;
        while (mp2.size() == len) {
            result = min(i-low+1, result);
            mp2[s[low]]--;
            if (mp2[s[low]]==0) {
                mp2.erase(s[low]);
            }
            low++;
        }
    }
    cout << result << endl;
}