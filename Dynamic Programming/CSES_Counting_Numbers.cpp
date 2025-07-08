#include <bits/stdc++.h>
using namespace std;
string low, high;
long long f(int index, int tight, string num, int lastUsed, vector<vector<vector<long long>>> &dp) {
    if (index==num.size()) {
        return 1;
    }
    if (dp[index][tight][lastUsed]!=-1) {
        return dp[index][tight][lastUsed];
    }
    int bound = tight ? num[index] - '0' : 9;
    long long answer(0);
    for (int i = 0; i<=bound; i++) {
        if (i==lastUsed) {
            continue;
        } 
        int nextLast = lastUsed;
        if(!(lastUsed==10 && i==0)) {
            nextLast = i;
        }
        answer += f(index+1, tight&(i==bound), num, nextLast, dp);
    }
    return dp[index][tight][lastUsed] = answer;
}
int main() {
    cin >> low >> high;
    int n = high.size();
    vector<vector<vector<long long>>> dp1(n+1, vector<vector<long long>> (2, vector<long long> (11, -1)));
    long long temp = stoll(low) - 1;
    string less = to_string(temp);
    vector<vector<vector<long long>>> dp2(less.size()+1, vector<vector<long long>> (2, vector<long long> (11, -1)));
    if (low == "0") {
        cout << f(0,1, high,10, dp1) << "\n";
        return 0;
    }
    cout << f(0, 1, high, 10, dp1) - f(0, 1, less, 10, dp2) << "\n";
}