#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n, k;
        cin >> n >> k;
        int answer(0);
        string s;
        cin >> s;
        for (int i = 0; i<(k+1)/2; i++) {
            vector<int> freq(26);
            for (int j = 0; j<n; j+=k) {
                freq[s[j+i]-'a']++;
                if (j+i!=j+k-i-1) {
                    freq[s[j+k-i-1]-'a']++;
                }
            }
            answer-=*max_element(freq.begin(), freq.end());
        }
        cout << answer + n << "\n";
    }
}