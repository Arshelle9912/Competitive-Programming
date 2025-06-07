#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result(0);
    bool right = false;
    vector<int> xi(n);
    vector<int> height(n);
    if (n==0) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 0; i<n; i++) {
        cin >> xi[i] >> height[i];
    }
    result++;
    for (int i = 1; i<n-1; i++) {
        if (right && (xi[i-1]+height[i-1]<xi[i]-height[i])) {
            right = false;
            result++;
        } else if (!right && xi[i-1]<xi[i]-height[i]) {
            right = false;
            result++;
        } else if (xi[i]+height[i]<xi[i+1]){
            right = true;
            result++;
        } else {
            right = false;
        }
    }
    if (n>1) {
        result++;
    }
    cout << result << "\n";
}