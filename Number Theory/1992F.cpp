#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }
        int segments = 0;
        int i = 0;
        while (i<n) {
            segments++;
            set<int> seen;
            vector<int> reachable;
            seen.insert(1);
            reachable.push_back(1);
            while (i<n) {
                if (x%a[i]!=0) {
                    i++;
                    continue;
                }
                bool flag = false;
                int sz = reachable.size();
                for (int j = 0; j<sz; j++) {
                    long long product = 1LL * reachable[j] * a[i];
                    if (product>x || x%product!=0) {
                        continue;
                    }
                    int d = (int) product;
                    if (d==x) {
                        flag = true;
                        break;
                    }
                    if (!seen.count(d)) {
                        seen.insert(d);
                        reachable.push_back(d);
                    }
                }
                if (flag) {
                    break;
                }
                ++i;
            }
        }
        cout << segments << "\n";
    }
}