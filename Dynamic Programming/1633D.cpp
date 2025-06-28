#include <bits/stdc++.h>
using namespace std;
int main() {
    int maxV = 1000;
    vector<int> operations(maxV+1, 1e9);
    queue<int> q;
    operations[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        int op = operations[curr];
        for (int x = 1; x<=curr; x++) {
            int v = curr + curr/x;
            if (v>maxV) continue;
            if (operations[v]>op+1) {
                operations[v] = op+1;
                q.push(v);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, cost;
        cin >> n >> cost;
        vector<int> bi(n);
        vector<int> ci(n);
        for (int i = 0; i<n; i++) {
            cin >> bi[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> ci[i];
        }
        vector<int> ai(n);
        for (int i = 0; i<n; i++) {
            ai[i] = operations[bi[i]];
        }
        long long freeCoins = 0;
        vector<pair<int,int>> items;
        for (int i = 0; i < n; ++i) {
            if (ai[i] == 0) {
                freeCoins += ci[i];
            } else {
                items.emplace_back(ai[i], ci[i]);
            }
        }
        int K = min(cost, accumulate(ai.begin(), ai.end(), 0));
        vector<long long> dp(K+1, 0);
        for (auto [w, v] : items) {
            for (int j = K; j >= w; --j) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
        cout << dp[K] + freeCoins << "\n";
    }
}