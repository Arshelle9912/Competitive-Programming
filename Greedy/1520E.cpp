#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> indexes;
        for (int i = 0; i<n; i++) {
            if (s[i]=='*') {
                indexes.push_back(i);
            }
        }
        int stars = indexes.size();
        long long result(0);
        long long sum1(0);
        long long sum2(0);
        if (stars == 0) {
            cout << 0 << "\n";
            continue;
        }
        if (stars%2==0) {
            int median1 = indexes[stars/2];
            int median2 = indexes[stars/2-1];
            for (int i = 0; i<stars; i++) {
                sum1 += llabs(median1 - stars/2 + i - indexes[i]);
                sum2 += llabs(median2 - stars/2 + i + 1 - indexes[i]);
            }
            result = min(sum1, sum2);
            cout << result << "\n";
        } else {
            int median = indexes[stars/2];
            for (int i = 0; i<stars; i++) {
                sum1 += llabs(median - stars/2 + i - indexes[i]);
            }
            cout << sum1 << "\n";
        }
    }
}