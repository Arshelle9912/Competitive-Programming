#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    int left(0);
    long long count(0);
    for (int i = 0; i<n; i++) {
        while (arr[i]-arr[left]>r) {
            count += n-i;
            left++;
        }
    }
    cout << count << endl;
}