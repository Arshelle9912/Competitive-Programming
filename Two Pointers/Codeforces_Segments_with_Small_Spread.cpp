#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k, count(0), low(0);
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    multiset<long long> ms;
    long long maximum(LONG_MIN), minimum(LONG_MAX);
    for (int i = 0; i<n; i++) {
        ms.insert(arr[i]);
        while (*ms.rbegin()-*ms.begin()>k) {
            ms.erase(ms.find(arr[low]));
            low++;
        }
        count += i - low + 1;
    }
    cout << count << endl;
}