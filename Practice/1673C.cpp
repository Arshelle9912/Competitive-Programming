#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<int> palindromes;
    for (int i = 1; i<=40000; i++) {
        string s = to_string(i);
        string ns = s;
        reverse(s.begin(), s.end());
        if (ns==s) {
            palindromes.push_back(i);
        }
    }
    int sz = palindromes.size();
    vector<vector<long long>> dp(sz+1, vector<long long> (40001));
    dp[0][0] = 1;
    for (int i = 1; i<=sz; i++) {
        for (int j = 0; j<=40000; j++) {
            dp[i][j] = (dp[i][j]+dp[i-1][j])%MOD;
            if (j>=palindromes[i-1]) {
                dp[i][j] = (dp[i][j]+dp[i][j-palindromes[i-1]])%MOD;
            }
        }
    }
    while (t--) {
        int n;
        cin >> n;
        cout << dp[sz][n] << "\n";
    }
}