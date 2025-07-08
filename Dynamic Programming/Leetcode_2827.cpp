#include <bits/stdc++.h>
using namespace std;
int f(int index, int tight, string temp, vector<vector<vector<vector<vector<int>>>>> &dp, int countOdd, bool start, int k, int rem, int len) {
    if (index==temp.size()) {
        return (len > 0 && len % 2 == 0 && 2*countOdd == len && rem == 0) ? 1 : 0;
    }
    if (dp[index][tight][countOdd][rem][len]!=-1) {
        return dp[index][tight][countOdd][rem][len];
    }
    int bound = tight ? temp[index]-'0' : 9;
    int ans(0);
    for (int i = 0; i<=bound; i++) {
        bool ntight = tight && (i == bound);
        int nodd = countOdd + (i%2);
        int nrem = (rem*10 + i) % k;
        int nlen = (len == 0 && i == 0) ? 0 : (len + 1);
        ans += f(index+1, ntight, temp, dp, nodd, true, k, nrem, nlen);
    }
    return dp[index][tight][countOdd][rem][len] = ans;
}
int numberOfBeautifulIntegers(int low, int high, int k) {
    string temp1 = to_string(high);
    string temp2 = to_string(low-1);
    if (temp2.size() < temp1.size())
        temp2 = string(temp1.size() - temp2.size(), '0') + temp2;
    vector<vector<vector<vector<vector<int>>>>> dp1(temp1.size()+1, vector<vector<vector<vector<int>>>> (2, vector<vector<vector<int>>> (temp1.size()+1, vector<vector<int>> (k+1, vector<int> (temp1.size()+1, -1)))));
    vector<vector<vector<vector<vector<int>>>>> dp2(temp2.size()+1, vector<vector<vector<vector<int>>>> (2, vector<vector<vector<int>>> (temp2.size()+1, vector<vector<int>> (k+1, vector<int> (temp2.size()+1, -1)))));
    if (low==0) {
        return f(0, 1, temp1, dp1, 0, false, k, 0, 0);
    }
    return f(0, 1, temp1, dp1, 0, false, k, 0, 0) - f(0, 1, temp2, dp2, 0, false, k, 0, 0);
}
int main() {
    int low, high, k;
    cin >> low >> high >> k;
    cout << numberOfBeautifulIntegers(low, high, k) << "\n";
}