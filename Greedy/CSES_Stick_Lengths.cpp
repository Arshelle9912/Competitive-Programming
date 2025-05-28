#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    long long sum1 = 0;
    long long sum2 = 0;
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if (n%2==0) {
        int median1 = arr[n/2-1];
        int median2 = arr[n/2];
        for (int i = 0; i<n; i++) {
            sum1 += llabs(arr[i]-median1);
            sum2 += llabs(arr[i]-median2);
        }
        cout << min(sum1, sum2) << "\n";
    } else {
        int median = arr[n/2];
        for (int i = 0; i<n; i++) {
            sum1 += llabs(arr[i]-median);
        }
        cout << sum1 << "\n";
    }
}