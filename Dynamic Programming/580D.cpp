#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> values(n);
    for (long long i = 0; i<n; i++) {
        cin >> values[i];
    }
    map<pair<long long, long long>, long long> mp;
    for (long long i = 0; i<k; i++) {
        long long temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        pair<long long, long long> temp = {temp1-1, temp2-1};
        mp[temp] = temp3;
    }
    vector<vector<long long>> dp((1<<n), vector<long long> (n, -1));
    auto f = [&] (long long index, long long mask, long long last, auto &&F) -> long long {
        if (index==m) {
            return 0;
        }
        if (dp[mask][last]!=-1) {
            return dp[mask][last];
        }
        long long best = 0;
        for (long long i = 0; i<n; i++) {
            if (mask & (1LL<<i)) continue;
            long long gain = values[i];
            auto it = mp.find({last,i});
            if (it != mp.end()) {
                gain += mp[{last,i}];
            }
            best = max(best, gain+F(index+1, mask | (1LL<<i), i, F));
        }
        return dp[mask][last] = best;
    };
    long long answer = 0;
    for (long long i = 0; i < n; ++i) {
        answer = max(answer, (long long)values[i] + f(1, 1LL<<i, i, f));
    }
    cout << answer << "\n";
}