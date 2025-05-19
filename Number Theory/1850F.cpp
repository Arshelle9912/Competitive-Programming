#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int a = 0; a<t; a++) {
        int n;
        cin >> n;
        vector<int> freq(n+1, 0);
        for (int i = 0; i<n; i++) {
            int temp;
            cin >> temp;
            if (temp<=n) {
                freq[temp]++;
            }
        }
        int result(0);
        vector<int> count(n+1);
        for (int i = 1; i<=n; i++) {
            if (freq[i]==0) {
                continue;
            }
            for (int d = i; d<=n; d+=i) {
                count[d] += freq[i];
            }
        }
        for (int i = 1; i<=n; i++) {
            result = max(result, count[i]);
        }
        cout << result << "\n";
    }
}