#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        long long testans = 2;
        unordered_set<long long> vals;
        while (true) {
            for (int i = 0; i<n; i++) {
                vals.insert(arr[i]%testans);
            }
            if (vals.size() == 2) { 
                cout << testans << "\n";
                break;
            }
            testans *= 2;
            vals.clear();
        }
    }
}