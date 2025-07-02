#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
string s;
int d;
int dp[10001][2][101];
int f(int index, int tight, int sum) {
    if (index == s.size()) {
        if (sum%d==0) {
            return 1;
        }
        return 0;
    }
    if (dp[index][tight][sum]!=-1) {
        return dp[index][tight][sum];
    }
    int bound = (tight ? s[index]-'0' : 9);
    int answer = 0;
    for (int i = 0; i<=bound; i++) {
        answer = (answer + f(index+1, tight & (s[index]-'0'==i), (sum+i)%d)) % MOD;
    }
    return dp[index][tight][sum] = answer;
}
int main() {
    cin >> s >> d; 
    memset(dp, -1, sizeof(dp));
    cout << (f(0,1,0) -1 + MOD) % MOD << "\n";
}