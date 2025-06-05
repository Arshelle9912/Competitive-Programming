#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j = 0; j<t; j++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            string temp;
            cin >> temp >> arr[i];
        }
        sort(arr.begin(), arr.end());
        long long result(0);
        for (int i = 1; i<=n; i++) {
            result += llabs(arr[i-1]-i);
        }
        cout << result << "\n";
    }
    
}