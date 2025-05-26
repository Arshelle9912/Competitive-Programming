#include <bits/stdc++.h>
using namespace std;

vector<long long> factorial(long long x, long long prime) {
    long long result = 1;
    vector<long long> ans(x+1);
    ans[0] = 1, ans[1]=1;
    for (int i = 2; i<=x; i++) {
        result = (result * i) % prime;
        ans[i] = result;
    }
    return ans;
}

int main() {
    int n, prime;
    cin >> n >> prime;
    vector<long long> fact = factorial(n, prime);
    long long result(0);
    for (int i = 1; i<=n; i++) {
        int ans = ((((1LL * (n-i+1) * (n-i+1)) % prime) * fact[i])%prime * fact[n-i])%prime;
        result = (result + ans)%prime;
    }
    cout << result << "\n";
}