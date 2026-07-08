#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<tuple<long long, long long, long long>> arr(n + 1);
    arr[0] = {0, 0, 0};

    for (long long i = 1; i <= n; i++) {
        long long sal, st, en;
        cin >> sal >> st >> en;
        arr[i] = {en, st, sal};
    }

    sort(arr.begin(), arr.end());

    vector<long long> ends(n + 1);
    for (long long i = 0; i <= n; i++) {
        ends[i] = get<0>(arr[i]);
    }

    vector<long long> p(n + 1, 0);
    for (long long i = 1; i <= n; i++) {
        long long st = get<1>(arr[i]);
        long long j = upper_bound(ends.begin(), ends.end(), st) - ends.begin() - 1;
        if (j < 0) j = 0;
        p[i] = j;
    }

    const long long INF = (1LL << 60);
    vector<pair<long long, long long>> dp(n + 1, {0, INF});
    dp[0] = {0, 0};

    for (long long i = 1; i <= n; i++) {
        auto [en, st, sal] = arr[i];
        long long dur = en - st;
        long long val = sal * dur;

        pair<long long, long long> skip = dp[i - 1];
        pair<long long, long long> take = {dp[p[i]].first + val, dp[p[i]].second + dur};

        if (take.second >= 86400) take = {0, INF};

        dp[i] = skip;
        if (take.first > dp[i].first) {
            dp[i] = take;
        } else if (take.first == dp[i].first) {
            if (take.second < dp[i].second) dp[i] = take;
        }
    }

    cout << dp[n].first << " " << dp[n].second << "\n";
}
