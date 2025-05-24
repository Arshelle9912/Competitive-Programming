#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i<n; i++) {
        cin >> s[i];
    }
    long long result = 1;
    for (int j = 0; j<m; j++) {
        int count(0);
        vector<int> a(26, false);
        for (int i = 0; i<n; i++) {
            a[s[i][j]-'A'] = true;
        }
        for (int i = 0; i<26; i++) {
            if (a[i]) {
                count++;
            }
        }
        result = (result * count) % MOD;
    }
    cout << result << "\n";
}