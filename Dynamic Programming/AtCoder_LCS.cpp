#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    string t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for (int i = n-1; i>=0; i--) {
        for (int j = m-1; j>=0; j--) {
            if (s[i]==t[j]) {
                dp[i][j] = 1 + dp[i+1][j+1];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    string ans = "";
    int i = 0, j = 0;
    while (i<n && j<m) {
        if (s[i]==t[j]) {
            ans+=s[i];
            ++i;
            ++j;
        } else if (dp[i+1][j]>=dp[i][j+1]) {
            ++i;
        } else {
            ++j;
        }
    }
    cout << ans << "\n";
}