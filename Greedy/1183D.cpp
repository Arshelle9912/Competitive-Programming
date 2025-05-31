#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n;
        cin >> n;
        vector<int> freq(n+1);
        for (int i = 0; i<n; i++) {
            int temp;
            cin >> temp;
            freq[temp]++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int allowed = INT_MAX;
        long long result = 0;
        for (int i = 0; i<n; i++) {
            allowed = min(freq[i], allowed-1);
            if (allowed<=0) {
                break;
            }
            result += allowed;
        }
        cout << result << "\n";
    }
}