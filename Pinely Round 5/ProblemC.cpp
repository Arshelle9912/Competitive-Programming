#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n; long long X;
        cin >> n >> X;
        vector<long long> a(n);
        for (auto &v : a) {
            cin >> v;
        }
        sort(a.begin(), a.end());       
        long long bonus = 0, rem = 0;       
        int i = 0, j = n - 1;
        vector<long long> order; 
        order.reserve(n);

        while (i <= j) {
            if (rem + a[j] >= X) {
                order.push_back(a[j]);
                bonus += a[j];
                rem = rem + a[j] - X;
                --j;
            } else if (a[i] <= X - 1 - rem) {
                order.push_back(a[i]);
                rem += a[i];
                ++i;
            } else {
                order.push_back(a[j]);
                bonus += a[j];
                rem = rem + a[j] - X;
                --j;
            }
        }

        cout << bonus << "\n";
        for (int k = 0; k < n; ++k) {
            if (k) {
                cout << ' ';
            }
            cout << order[k];
        }
        cout << "\n";
    }
}
