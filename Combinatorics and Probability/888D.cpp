#include <bits/stdc++.h>
using namespace std;

int main() {
    static const int D[5] = { 1, 0, 1, 2, 9 };
    int n, k;
    long long result(0);
    cin >> n >> k;
    for (int i = 0; i<=k; i++) {
        long long sum = 1;
        long long lowersum = 1;
        for (int j = 0; j<i; j++) {
            sum *= (n-j);
        }
        for (int j = 1; j<=i; j++) {
            lowersum*=j;
        }
        result += (sum/lowersum) * D[i];
    }
    cout << result << "\n";
}