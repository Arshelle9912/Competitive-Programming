#include <bits/stdc++.h>
using namespace std;
int MOD = 998244353;
long long mod_pow(long long num, long long power)
{
    long long result = 1;
    while (power)
    {
        if (power & 1)
        {
            result = (result * num) % MOD;
        }
        num = (num * num) % MOD;
        power >>= 1;
    }
    return result;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<tuple<long long, long long, long long, long long>>> seg(m + 1);
    long long inv = 1;
    for (int i = 0; i < n; i++)
    {
        long long l, r, p, q;
        cin >> l >> r >> p >> q;
        seg[l].push_back({l, r, p, q});
        long long non_active = ((q - p) * (mod_pow(q, MOD - 2))) % MOD;
        inv = (inv * non_active) % MOD;
    }
    vector<long long> dp(m + 1, 0);
    dp[0] = inv;
    for (int i = 1; i < m + 1; i++)
    {
        for (auto [l, r, p, q] : seg[i])
        {
            long long x = dp[l - 1];
            x = (x * p) % MOD;
            x = (x * mod_pow(q - p, MOD - 2)) % MOD;
            dp[r] = (dp[r] + x) % MOD;
        }
    }
    cout << dp[m] % MOD << "\n";
}