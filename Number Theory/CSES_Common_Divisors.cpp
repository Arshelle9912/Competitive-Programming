#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(1e6+1);
    int count(0);
    int temp;
    for (int i = 0; i<n; i++) {
        cin >> temp;
        arr[temp]++;
    }
    for (int i = 1e6; i>0; i--) {
        count = 0;
        for (int d = i; d<=1e6; d+=i) {
            count += arr[d];
            if (count >= 2) {
                cout << i << "\n";
                return 0;
            }
        }
    }
}