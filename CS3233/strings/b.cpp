#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
void computeLPSArray (string pattern, int m, vector<int>& LPS) {
    int length = 0;
    LPS[0] = 0;
    int i = 1;
    while (i<m) {
        if (pattern[i]==pattern[length]) {
            length++;
            LPS[i] = length;
            i++;
        } else {
            if (length!=0) {
                length = LPS[length-1];
            } else {
                LPS[i] = 0;
                i++;
            }
        }
    }
}
vector<int> KMP(string pattern, string text) {
    int m = pattern.length();
    int n = text.length();
    vector<int> ans;
    vector<int> LPS(m);
    computeLPSArray(pattern, m, LPS);
    int i = 0; 
    int j = 0;
    while (i<n) {
        if (pattern[j]==text[i]) {
            i++;
            j++;
        }
        if (j==m) {
            ans.push_back(i-j);
            j = LPS[j-1];
        }
        else if (i<n && text[i]!=pattern[j]) {
            if (j>0) j = LPS[j-1];
            else i++;
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> arr(n);
    long long sum = 0;
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
        sum+=arr[i].size();
    }
    vector<vector<int>> grid(n, vector<int> (n));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            string ns = arr[i]+"#"+arr[j];
            vector<int> LPS(arr[i].size()+arr[j].size()+1);
            computeLPSArray(ns, arr[i].size()+arr[j].size()+1, LPS);
            grid[j][i] = LPS[arr[i].size()+arr[j].size()];
        }
    }
    vector<vector<int>> dp(1<<n, vector<int> (n, 0));
    for (int mask = 0; mask<(1<<n); mask++) {
        for (int u = 0; u<n; u++) {
            if (!(mask & (1<<u))) continue;
            for (int v = 0; v<n; v++) {
                if (u==v) continue;
                if (mask&(1<<v)) continue;
                int nmask = mask|(1<<v);
                dp[nmask][v] = max(dp[nmask][v], dp[mask][u]+grid[u][v]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i<n; i++) {
        ans = max(dp[(1<<n)-1][i], ans);
    }
    cout << sum-ans << "\n";
}