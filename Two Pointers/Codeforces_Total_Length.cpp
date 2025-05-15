#include <bits/stdc++.h>
using namespace std;

int main() {
    long long sum(0);
    long long len(0);
    int left(0);
    long long n, s;
    cin >> n >> s;
    vector<long long> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i<n; i++) {
        sum += arr[i];
        while (sum > s) {
            sum -= arr[left];
            left++;
        }
        long long window = i-left+1;
        len += window * (window + 1)/2;
    }
    cout << len << endl;
}