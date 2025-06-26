#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int MOD = 1000000007;
    vector<long long> prev(4), curr(4);
    prev[0] = 1;
    prev[1] = 1;
    prev[2] = 1;
    prev[3] = 0;
    for (int i = 2; i<=n; i++) {
        curr[0] = (prev[1] + prev[2] + prev[3])%MOD;
        curr[1] = (prev[0] + prev[2] + prev[3])%MOD;
        curr[2] = (prev[0] + prev[1] + prev[3])%MOD;
        curr[3] = (prev[0] + prev[1] + prev[2])%MOD;
        prev = curr;
    }
    cout << curr[3] << "\n";
}