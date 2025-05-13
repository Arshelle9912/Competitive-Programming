#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> arr(n);
    vector<long long> prefix(n);
    long long sum(0), maximum(LLONG_MIN);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
        sum += arr[i];
        prefix[i] = sum;
    }
    multiset<long long> ms;
    for (int i = a-1; i<b; i++) {
        ms.insert(prefix[i]);
    }
    maximum = max(maximum, *ms.rbegin());
    for(int i = 1; i <= n - a; i++){
        auto it = ms.find(prefix[i + a - 2]);
        if(it != ms.end()) {
            ms.erase(it);
        }
        if (i + b - 1 < n) {
            ms.insert(prefix[i + b - 1]);
        }
        maximum = max(maximum, *ms.rbegin() - prefix[i - 1]);
    }
    cout << maximum << endl;
}