#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int> > arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    long long count(0);
    long long result(LONG_MIN);
    int left(0);
    for (int i = 0; i<n; i++) {
        count+=arr[i].second;
        while (arr[i].first-arr[left].first>=d) {
            count -= arr[left].second;
            left++;
        }
        result = max(result, count);
    }
    cout << result << "\n";
}