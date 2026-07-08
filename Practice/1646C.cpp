#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<long long> factorials;
    long long num1 = 6;
    long long i = 4;
    while (num1<=1e12) {
        factorials.push_back(num1);
        num1 *= i;
        i++;
    }
    int maxi = pow(2, 12);
    while (t--) {
        long long n;
        cin >> n;
        int ans = INT_MAX;
        for (int mask = 0; mask<maxi; mask++) {
            long long sum = 0;
            int temp = mask;
            int count = 0;
            int index = 0;
            while (temp>0) {
                if (temp&1) {
                    sum += factorials[index];
                    if (sum>n) break;
                    count++;
                }
                index++;
                temp >>= 1;
            }
            if (sum>n) continue;
            long long rem = n - sum;
            ans = min(ans, count + __builtin_popcountll(rem));
        }
        cout << ans << "\n";
    }
}