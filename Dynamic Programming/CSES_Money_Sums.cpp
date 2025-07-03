#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> dp;
int n;
vector<int> arr;
set<int> result;
int solve(int index, int sum) {
    if (index>n) {
        return 0;
    }
    if (dp[index][sum]==true) {
        return 0;
    }
    dp[index][sum] = true;
    int pick = sum + arr[index-1];
    result.insert(pick);
    solve(index+1, pick);
    solve(index+1, sum);
    return 0;
}
int main() {
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    dp.assign(n+1, vector<bool>(100001, false));
    solve(1, 0);
    cout << result.size() << "\n";
    for (int i : result) {
        cout << i << " ";
    }
}