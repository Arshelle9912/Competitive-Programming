#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<unsigned long long>> C(101, vector<unsigned long long>(101));

    for (int i = 0; i <= 100; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
    }

    int t;
    cin >> t;
    while (t--) {
        int id, n;
        cin >> id >> n;

        int s = n / 2;
        unsigned long long ans = 0;

        for (int a = 0; 2 * a <= s; a++) {
            int b = s - 2 * a;
            if (a < b) continue;
            int m = a + b;
            unsigned long long x = C[m][a];
            ans += x * x;
        }

        cout << id << " " << ans << "\n";
    }
}
