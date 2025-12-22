#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> numEndZeros;
        int totalDigits = 0;
        for (int i = 0; i<n; i++) {
            string s;
            cin >> s;
            int len = s.length();
            totalDigits+=len;
            int j = len-1;
            int zeros = 0;
            while (s[j]=='0') {
                zeros++;
                j--;
            }
            if (zeros!=0) numEndZeros.push_back(zeros);
        }
        sort(numEndZeros.begin(), numEndZeros.end(), greater<int>());
        for (int i = 0; i<numEndZeros.size(); i+=2) {
            totalDigits-=numEndZeros[i];
        }
        if (totalDigits>m) cout << "Sasha\n";
        else cout << "Anna\n";
    }
}