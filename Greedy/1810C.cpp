#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j = 0; j<t; j++) {
        long long n, c, d;
        cin >> n >> c >> d;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        set<long long> s;
        long long duplicates = 0;
        long long best = c*n+d;
        for (int i = 0; i<n; i++) {
            if (s.find(arr[i])==s.end()) {
                s.insert(arr[i]);
            } else {
                duplicates++;
            }
            long long cost = 0;
            cost+=duplicates*c;
            if (arr[i]-(i+1-duplicates)>0) {
                cost += (arr[i]-(i+1-duplicates))*d;
            }
            cost += (n-i-1)*c;
            best = min(cost, best);
        }
        cout << best << "\n";
    }
}