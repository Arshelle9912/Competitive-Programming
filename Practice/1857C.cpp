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
        int val = n*(n-1)/2;
        map<int, int> mp;
        for (int i = 0; i<val; i++) {
            int num;
            cin >> num;
            mp[num]++;
        }
        int lastval;
        int start = n-1;
        for (auto [key, value]: mp) {
            lastval = key;
            while (value>0 && start>0) {
                value-=start;
                start--;
                cout << key << " ";
            }
        }
        cout << lastval << "\n";
    }
}