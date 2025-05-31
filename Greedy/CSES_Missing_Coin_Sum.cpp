#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    long long sum = 0;
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i<n; i++) {
        if (arr[i]>sum+1) {
            break;
        } else {
            sum+=arr[i];
        }
    }
    cout << sum + 1 << "\n";
}