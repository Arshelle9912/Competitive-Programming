#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        long long bestLeft = arr[0] + 1;
        long long bestPair = LLONG_MIN;
        long long answer = LLONG_MIN;

        for (int i = 1; i < n; i++) {
            if (i >= 2) {
                answer = max(answer, bestPair + (arr[i] - (i+1)));
            }
            bestPair = max(bestPair, bestLeft + arr[i]);
            bestLeft = max(bestLeft, arr[i] + (i+1));
        }
        cout << answer << "\n";
    }
}