#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> horizontal, vertical;
vector<vector<vector<int>>> dp;
int solve(int i, int j, int k) {
    if (k == 0) 
        return 0;
    if (k % 2 == 1) {
        return INT_MAX;
    }
    int &ans = dp[i][j][k];
    if (ans != INT_MAX) {
        return ans;
    }
    int temp = INT_MAX;
    if (i > 0) {
        int cost = solve(i-1, j, k-2);
        if (cost != INT_MAX) {
            temp = min(temp, cost + 2 * vertical[i-1][j]);
        }
    }
    if (i+1 < n) {
        int cost = solve(i+1, j, k-2);
        if (cost != INT_MAX) {
            temp = min(temp, cost + 2 * vertical[i][j]);
        }
    }
    if (j > 0) {
        int cost = solve(i, j-1, k-2);
        if (cost != INT_MAX) {
            temp = min(temp, cost + 2 * horizontal[i][j-1]);
        }
    }
    if (j+1 < m) {
        int cost = solve(i, j+1, k-2);
        if (cost != INT_MAX) {
            temp = min(temp, cost + 2 * horizontal[i][j]);
        }
    }
    return ans = temp;
}
int main() {
    int k;
    cin >> n >> m >> k;
    horizontal.assign(n, vector<int> (m-1));
    vertical.assign(n-1, vector<int> (m));
    dp.assign(n, vector<vector<int>> (m, vector<int> (k+1, INT_MAX)));

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m-1; j++) {
            cin >> horizontal[i][j];
        }
    }
    for (int i = 0; i<n-1; i++) {
        for (int j = 0; j<m; j++) {
            cin >> vertical[i][j];
        }
    }
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            int res = solve(i, j, k);
            if (res==INT_MAX) {
                cout << "-1" << " ";
            } else {
                cout << res << " ";
            }
        }
        cout << "\n";
    }
}