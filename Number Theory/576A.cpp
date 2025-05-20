#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> primes(n+1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i*i<=n; i++) {
        if (primes[i]==1) {
            for (int j = i*i; j<=n; j+=i) {
                primes[j] = 0;
            }
        }
    }
    vector<int> ans;
    int count = 0;
    for (int i = 2; i<=n; i++) {
        if (primes[i]==1) {
            for (int j = i; j<=n; j*=i) {
                ans.push_back(j);
                count++;
            }
        }
    }
    cout << count << "\n";
    for (int i = 0; i<count; i++) {
        cout << ans[i] << " ";
    }
}