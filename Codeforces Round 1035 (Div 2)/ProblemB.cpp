#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;
        vector<int> dist(n);
        int sum(0);
        int maximum(0);
        for (int i = 0; i<n; i++) {
            cin >> dist[i];
            sum+=dist[i];
            maximum = max(maximum, dist[i]);
        }
        long long distance = 1LL * (qx-px) * (qx-px) + 1LL * (qy-py) * (qy-py);
        long long calc = max(0, maximum - (sum-maximum));
        calc *= calc;
        if (calc<=distance && distance <= 1LL * sum * sum) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}