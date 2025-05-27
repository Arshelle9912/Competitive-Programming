#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;
int main() {
    string s;
    cin >> s;
    int count_a(0);
    long long result = 1;
    for (char c : s) {
        if (c=='a') {
            count_a++;
        } else if (c=='b') {
            result = (result*(count_a+1))%MOD;
            count_a = 0;
        }
    }
    if (count_a!=0) {
        result = (result*(count_a+1))%MOD;
    }
    cout << (result - 1 + MOD) % MOD << "\n";
}