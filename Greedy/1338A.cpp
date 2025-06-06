#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        int largest = INT_MIN;
        int result = 0;
        for (int i = 0; i<n; i++) {
            if (arr[i]<largest) {
                result = max((int)log2(largest-arr[i])+1, result);
            } else {
                largest = arr[i];
            }
        }
        cout << result << "\n";
    }
}