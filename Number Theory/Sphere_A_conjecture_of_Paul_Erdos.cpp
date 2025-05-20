#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> primes(1e7+1, 1);
    primes[0] = 0, primes[1] = 0;
    for (int i = 2; i*i<=1e7; i++) {
        if (primes[i]==1) {
            for (int j = i*i; j<=1e7; j+=i) {
                primes[j] = 0;
            }
        }
    }
    vector<int> counted(1e7+1);
    int count(0);
    for (int y = 0; y*y*y*y<=1e7; y++) {
        for (int x = 0; (x*x + y*y*y*y)<=1e7; x++) {
            if (primes[x*x + y*y*y*y]) {
                counted[x*x + y*y*y*y]=1;
            }
        }
    }
    vector<int> prefix(1e7+1);
    for (int i = 1; i<=1e7; i++) {
        prefix[i] = prefix[i-1] + counted[i];
    }
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n;
        cin >> n;
        cout << prefix[n] << "\n";
    }
}