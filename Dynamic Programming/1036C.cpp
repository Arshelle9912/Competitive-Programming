#include <bits/stdc++.h>
using namespace std;
int dp[19][2][4];
string li, ri;
int f (int index, int tight, int used, const string& s) {
    if (used > 3) {
        return 0;
    }
    if (index==s.length()) {
        return 1;
    }
    if (dp[index][tight][used]!=-1) {
        return dp[index][tight][used];
    }
    int bound = (tight ? s[index] - '0' : 9);
    int answer = 0;
    for (int i = 0; i<=bound; i++) {
        if (i==0) {
            answer = answer + f(index+1, tight && (s[index]-'0'==i), used, s);
        } else {
            answer = answer + f(index+1, tight && (s[index]-'0'==i), used+1, s);
        }
    }
    return dp[index][tight][used] = answer;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> li >> ri;
        long long temp = stoll(li)-1;
        memset(dp, -1, sizeof(dp));
        int right = f(0, 1, 0, ri);
        memset(dp, -1, sizeof(dp));
        int left = f(0, 1, 0, to_string(temp));
        cout << right - left << "\n";
    }
}