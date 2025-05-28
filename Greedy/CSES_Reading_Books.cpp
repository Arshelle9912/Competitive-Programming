#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0, maximum = 0;
    for(int i = 0; i < n; i++){
        long long t;
        cin >> t;
        sum += t;
        maximum = max(maximum, t);
    }
    cout << max(sum, 2*maximum) << "\n";
}