#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    int result(0);
    multiset<int> ms;
    for (int i = 0; i<n; i++) {
        auto it = ms.upper_bound(arr[i]);
        if (it!=ms.end()) {
            ms.erase(it);
            ms.insert(arr[i]);
        } else {
            result++;
            ms.insert(arr[i]);
        }
    }
    cout << result << "\n";
}