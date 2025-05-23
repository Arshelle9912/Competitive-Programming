#include <bits/stdc++.h>
using namespace std;

long long binary_exponentiation(long long base, long long power) {
    long long result = 1;
    while (power>0) {
        if (power&1) {
            result = result * base;
        }
        base = base*base;
        power>>=1;
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    long long result = 0;
    vector<vector<int> > arr(n, vector<int>(m));
    for (int i = 0; i<n; i++) {
        int count1s(0);
        for (int j = 0; j<m; j++) {
            cin >> arr[i][j];
            if (arr[i][j]==1) {
                count1s++;
            }
        }
        result += binary_exponentiation(2, count1s) - 1 - count1s;
        result += binary_exponentiation(2, m-count1s) - 1 - m + count1s;
    }
    for (int i = 0; i<m; i++) {
        int count1s(0);
        for (int j = 0; j<n; j++) {
            if (arr[j][i]==1) {
                count1s++;
            }
        }
        result += binary_exponentiation(2, count1s) - 1 - count1s;
        result += binary_exponentiation(2, n-count1s) - 1 - n + count1s;
    }
    cout << result + 1LL*n*m << "\n";
}