#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum(0);
    vector<pair<int, int>> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort (arr.begin(), arr.end(), 
    [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    });
    for (int i = 0; i<n; i++) {
        sum+=arr[i].first;
        if (sum>arr[i].second) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}