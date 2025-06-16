#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i<n; i++) {
        cin >> str[i];
    }
    int len = s.length();
    int lastBad = -1;
    int bestLen(0), bestpos(0);
    for (int i = 0; i<len; i++) {
        for (int j = 0; j<n; j++) {
            int l = str[j].length();
            if (i-l+1<0) {
                continue;
            }
            bool match = true;
            for (int k = 0; k<l; k++) {
                if (s[i-l+1+k]!=str[j][k]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                lastBad = max(lastBad, i-l+1);
            }
        }
        int curr = i-lastBad;
        if (curr>bestLen) {
            bestLen = curr;
            bestpos = lastBad+1;
        }
    }
    cout << bestLen << " " << bestpos << endl;
}