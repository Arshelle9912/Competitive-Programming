#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> pairs(3);
        for (int i = 0; i<3; i++) {
            cin >> pairs[i].first >> pairs[i].second;
        }
        if ((pairs[0].first==pairs[1].first && pairs[1].first==pairs[2].first)) {
            int sum = pairs[0].second + pairs[1].second + pairs[2].second;
            if (sum==pairs[0].first) {
                cout << "YES" << "\n";
                continue;
            }
        }
        if ((pairs[0].second==pairs[1].second && pairs[1].second==pairs[2].second)) {
            int sum = pairs[0].first + pairs[1].first + pairs[2].first;
            if (sum==pairs[0].second) {
                cout << "YES" << "\n";
                continue;
            }
        }
        if ((pairs[0].first == pairs[1].first+pairs[2].first)&&(pairs[0].second<pairs[0].first)) {
            int diff = abs(pairs[0].first-pairs[0].second);
            if (pairs[1].second==pairs[2].second && pairs[2].second==diff) {
                cout << "YES" << "\n";
                continue;
            }
        }
        if ((pairs[0].second == pairs[1].second+pairs[2].second)&&(pairs[0].first<pairs[0].second)) {
            int diff = abs(pairs[0].first-pairs[0].second);
            if (pairs[1].first==pairs[2].first && pairs[2].first==diff) {
                cout << "YES" << "\n";
                continue;
            }
        }
        cout << "NO" << "\n";
    }
}