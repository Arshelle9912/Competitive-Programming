#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        vector<int> prefix(n);
        int sum(0);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        for (int i = 2; i<n; i++) {
            if (arr[i-2]<arr[i-1] && arr[i]<arr[i-1]) {
                sum++;
            }
            prefix[i] = sum;
        }
        int result(-1);
        int index;
        for (int i = 0; i<n-k+1; i++) {
            if (prefix[i+k-1] - prefix[i+1] > result) {
                result = prefix[i+k-1] - prefix[i+1];
                index = i;
            }
        }
        cout << result + 1 << " " << index + 1 << endl;
    }
}