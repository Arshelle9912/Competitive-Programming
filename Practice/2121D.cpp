#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<pair<int, int>> ops;
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i<n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i<n; i++) {
            for (int j = 1; j<n; j++) {
                if (a[j-1]>a[j]) {
                    swap(a[j-1], a[j]);
                    ops.push_back({1, j});
                }
            }
        }
        for (int i = 0; i<n; i++) {
            for (int j = 1; j<n; j++) {
                if (b[j-1]>b[j]) {
                    swap(b[j-1], b[j]);
                    ops.push_back({2, j});
                }
            }
        }
        for (int i = 0; i<n; i++) {
            if (a[i]>b[i]) {
                ops.push_back({3, i+1});
            }
        }
        cout << ops.size() << "\n";
        for (int i = 0; i<ops.size(); i++) {
            cout << ops[i].first << " " << ops[i].second << "\n";
        }
    }
}