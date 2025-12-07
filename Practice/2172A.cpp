#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr(3);
    for (int i = 0; i<3; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if (arr[2]-arr[0]>=10) {
        cout << "check again";
    } else {
        cout << "final " << arr[1];
    }
}