#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n, c;
        cin >> n >> c;
        int count(0);
        vector<long long> arr(n);
        vector<long long> cost(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
            cost[i] = arr[i]+i+1;
        }
        sort(cost.begin(), cost.end());
        for (int i = 0; i<n; i++) {
            c-=cost[i];
            if (c<0) {
                break;
            }
            count++;
        }
        cout << count << "\n";
    }
}