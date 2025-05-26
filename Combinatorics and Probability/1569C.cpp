#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

long long binary_exponentiation(long long base, long long power) {
    long long result = 1;
    while (power>0) {
        if (power&1) {
            result = (result * base)%MOD;
        }
        base = (base * base) % MOD;
        power>>=1;
    }
    return result;
}

vector<long long> factorial(int n) {
    vector<long long> result(n+1,1);
    long long temp(1);
    for (int i = 1; i<=n; i++) {
        temp = (temp * i) % MOD;
        result[i] = temp;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    vector<long long> fact = factorial(200000);
    for (int i = 0; i<t; i++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int max = INT_MIN;
        int count_max = 0;
        int second_max = INT_MIN;
        int count_second_max = 0;
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
            if (arr[i]>max) {
                second_max = max;
                count_second_max = count_max;
                max = arr[i];
                count_max = 1;
            } else if (arr[i]==max) {
                count_max++;
            } else if (arr[i]>second_max) {
                count_second_max = 1;
                second_max = arr[i];
            } else if (arr[i]==second_max) {
                count_second_max++;
            }
        }
        if (count_max>1) {
            cout << fact[n] << "\n";
            continue;
        }
        if (max-second_max>1) {
            cout << 0 << "\n";
            continue;
        }
        long long inv = binary_exponentiation(count_second_max+1, MOD-2);
        long long bad = fact[n] * inv % MOD;
        long long ans = (fact[n] - bad + MOD) % MOD;
        cout << ans << "\n";
    }
}