#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;
long long binary_exponentiation(long long base, long long pow) {
    long long result = 1;
    while (pow) {
        if (pow&1) {
            result = (result * base) % MOD;
        }
        base = (base*base) % MOD;
        pow>>=1;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    vector<int> inverses(200001);
    inverses[1] = 1;
    for (int i = 2; i<200001; i++) {
        inverses[i] = binary_exponentiation(i, MOD-2);
    }
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i<n; i++) {
            cin >> nums[i];
        }
        vector<int> checker;
        map<int, int> mp;
        sort(nums.begin(), nums.end());
        set<int> se;
        for (int i = 0; i<n; i++) {
            if (se.find(nums[i])==se.end()) {
                checker.push_back(nums[i]);
                mp[nums[i]]++;
                se.insert(nums[i]);
            } else {
                mp[nums[i]]++;
            }
        }
        int m = checker.size();
        vector<long long> f(m);
        for (int i = 0; i < m; i++) {
            f[i] = mp[checker[i]];
        }
        long long prod = 1;
        for (int i = 0; i < k && i < m; i++) {
            prod = (prod * f[i]) % MOD;
        }
        long long ans = 0;
        for (int i = 0; i + k <= m; i++) {
            if (checker[i + k - 1] - checker[i] < k)
                ans = (ans + prod) % MOD;
            if (i + k < m) {
                prod = prod * inverses[f[i]] % MOD;
                prod = prod * f[i + k] % MOD;
            }
        }
        cout << ans << "\n";
    }
}