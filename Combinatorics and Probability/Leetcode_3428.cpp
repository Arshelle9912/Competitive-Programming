#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

vector<long long> factorial(int n) {
    vector<long long> result(n+1,1);
    long long temp(1);
    for (int i = 1; i<=n; i++) {
        temp = (temp * i) % MOD;
        result[i] = temp;
    }
    return result;
}

long long binary_exponentiation(long long base, long long power) {
    long long result = 1;
    while (power>0) {
        if (power&1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        power >>= 1;
    }
    return result;
}

vector<long long> inverse_factorial(const vector<long long>& fact) {
    int N = fact.size() - 1;
    vector<long long> ifact(N+1);
    ifact[N] = binary_exponentiation(fact[N], MOD-2);
    for (int i = N; i > 0; i--)
        ifact[i-1] = ifact[i] * i % MOD;
    return ifact;
}

long long ncr(long long up, long long down, const vector<long long>& fact, const vector<long long>& ifact) {
    if (down < 0 || down > up) return 0;
    return fact[up] * ifact[down] % MOD * ifact[up-down] % MOD;
}

int minMaxSums(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    long long ans = 0;
    vector<long long> fact = factorial(n);
    vector<long long> ifact = inverse_factorial(fact);
    map<int, int> mp;
    for (int i = 0; i<n; i++) {
        mp[nums[i]]++;
    }
    for (int j = 1; j<=k; j++) {
        int count_big = n, count_small = 0;
        for (auto [num, freq] : mp) {
            count_big -= freq;
            for (int i = 1; i<=freq; i++) {
                ans = (
                    ans+ num % MOD * ncr(freq, i, fact, ifact) % MOD * ( (ncr(count_big, j-i, fact, ifact) + ncr(count_small, j-i, fact, ifact)) % MOD )) % MOD;
            }
            count_small += freq;
        }
    }
    cout << ans;
    return (int) ans;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    minMaxSums(nums, k);
}