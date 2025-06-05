#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int> gaps;
    for (int i = 1; i<n; i++) {
        gaps.push_back(arr[i]-arr[i-1]);
    }
    sort(gaps.begin(), gaps.end());
    long long result(0);
    for (int i = 0; i<n-k; i++) {
        result+=gaps[i];
    }
    cout << result + k << "\n";
}