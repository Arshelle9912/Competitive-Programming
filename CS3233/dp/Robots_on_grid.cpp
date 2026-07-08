#include <bits/stdc++.h>
using namespace std;
long long MOD = powl(2, 31)-1;
int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i<n; i++) {
        cin >> grid[i];
    }
    vector<vector<long long>> dp(n, vector<long long> (n));
    dp[0][0] = 1;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (grid[i][j]=='#') continue;
            if (i-1>=0) {
                dp[i][j] = ((__int128) dp[i][j] + dp[i-1][j])%MOD;
            }
            if (j-1>=0) {
                dp[i][j] = ((__int128) dp[i][j] + dp[i][j-1])%MOD;
            }
        }
    }
    if (dp[n-1][n-1]>0) {
        cout << dp[n-1][n-1] << "\n";
        return 0;
    }
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<bool>> visited(n, vector<bool> (n));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int r = front.first;
        int c = front.second;
        for (int i = 0; i<4; i++) {
            int nI = dir[i].first + r;
            int nJ = dir[i].second + c;
            if (nI>=0 && nI<n && nJ>=0 && nJ<n) {
                if (grid[nI][nJ]!='#' && !visited[nI][nJ]) {
                    visited[nI][nJ] = true;
                    q.push({nI, nJ});
                }
            }
        }
    }
    if (visited[n-1][n-1]) cout << "THE GAME IS A LIE\n";
    else cout << "INCONCEIVABLE";
}