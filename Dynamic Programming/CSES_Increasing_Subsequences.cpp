#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        auto it = lower_bound(arr.begin(), arr.end(), temp);
        if (it == arr.end()) {
            arr.push_back(temp);
        } else {
            *it = temp;
        }
    }
    cout << arr.size() << "\n";
}