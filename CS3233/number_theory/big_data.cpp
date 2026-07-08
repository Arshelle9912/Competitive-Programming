#include <bits/stdc++.h>
using namespace std;
vector<int> sieve (int n) {
    vector<int> numDiffPF(n+1, 0);
    for (int p = 2; p<=n; p++) {
        if (numDiffPF[p]==0) {
            for (int j = p; j<=n; j+=p) {
                numDiffPF[j]++;
            }
        }
    }
    return numDiffPF;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int> diff = sieve(14000);
    vector<int> dp((1<<n));
    for (int mask1 = 0; mask1<(1<<n); mask1++) {
        for (int sub = mask1; sub>0; sub = (sub-1)&mask1) {
            int temp = sub;
            int sum = 0;
            for (int i = 0; i<n; i++) {
                if (temp&(1<<i)) sum+=arr[i];
            }
            int val = diff[sum];
            dp[mask1] = max(dp[mask1], dp[mask1^sub]+val);
        }
    }
    printf("%d\n", dp[(1<<n)-1]);
}