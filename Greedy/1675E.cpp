#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int> charac(26);
        string s;
        cin >> s;
        vector<int> to(26);
        iota(to.begin(), to.end(), 0);
        int max_mapped = 0;
        long long rem = k;
        for (int i = 0; i<n; i++) {
            int ch = s[i]-'a';
            if (ch>max_mapped) {
                int cost = ch-max_mapped;
                if (cost<=rem) {
                    for (int j = max_mapped+1; j<=ch; j++) {
                        to[j] = 0;
                    }
                    rem-=cost;
                    max_mapped = ch;
                } else if (rem>0) {
                    int temp = ch-rem;
                    for (int j = temp+1; j<=ch; j++) {
                        to[j] = temp;
                    }
                    rem = 0;
                }
            }
            s[i] = char('a'+to[ch]);
        }
        cout << s << "\n";
    }
}