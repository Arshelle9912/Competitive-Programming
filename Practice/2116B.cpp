#include <bits/stdc++.h>
using namespace std;
int MOD = 998244353;
long long exponentiation(long long base, long long power) {
    long long result = 1;
    while (power>0) {
        if (power&1) {
            result = (result*base)%MOD;
        }
        base = (base*base)%MOD;
        power>>=1;
    }
    return result;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        vector<int> q(n);
        for (int i = 0; i<n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> q[i];
        }
        int maxP(INT_MIN);
        int maxQ(INT_MIN);
        int maxPind(-1);
        int maxQind(-1);
        vector<int> r(n);
        for (int i = 0; i<n; i++) {
            int power1, power2;
            if (p[i]>maxP) {
                maxP = p[i];
                maxPind = i;
            }
            if (q[i]>maxQ) {
                maxQ = q[i];
                maxQind = i;
            }
            if (maxP==maxQ) {
                power1 = maxP;
                power2 = max(p[i-maxQind], q[i-maxPind]);
            } else {
                if (maxP>maxQ) {
                    power1 = maxP;
                    power2 = q[i-maxPind];
                } else {
                    power1 = maxQ;
                    power2 = p[i-maxQind];
                }
            }
            r[i] = (exponentiation(2, power1) + exponentiation(2, power2))%MOD;
        }
        for (int i = 0; i<n; i++) {
            cout << r[i] << " ";
        }
        cout << "\n";
    }
}