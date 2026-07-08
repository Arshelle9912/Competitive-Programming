#include <bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long maximum(0), minimum(0);
        long long maxBlue(0), minBlue(0), minRed(0), maxRed(0);
        vector<long long> arr1(n);
        vector<long long> arr2(n);
        for (long long i = 0; i<n; i++) {
            cin >> arr1[i];
        }
        for (long long i = 0; i<n; i++) {
            cin >> arr2[i];
        }
        for (long long i = 0; i<n; i++) {
            maxRed = maximum - arr1[i];
            minRed = minimum - arr1[i];
            maxBlue = arr2[i] - minimum;
            minBlue = arr2[i] - maximum;
            maximum = max(maxRed, maxBlue);
            minimum = min(minRed, minBlue);
        }
        cout << maximum << "\n";
    }
}