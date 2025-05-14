#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    int sum = 0;
    int result = 0;
    vector<int> operations(n);
    if (nums[0] == 0) {
        operations[0] = 1;
        sum++;
    }
    for (int i = 1; i<k; i++) {
        if (sum % 2 == 0) {
            if (nums[i] == 0) {
                operations[i] = 1;
                sum++;
            } else {
                operations[i] = 0;
            }
        } else {
            if (nums[i] == 1) {
                operations[i] = 1;
                sum++;
            } else {
                operations[i] = 0;
            }
        }
    }
    result = sum;
    for (int i = k; i<n; i++) {
        sum -= operations[i-k];
        if (sum % 2 == 0) {
            if (nums[i] == 0) {
                operations[i] = 1;
                sum++;
                result++;
            } else {
                operations[i] = 0;
            }
        } else {
            if (nums[i] == 1) {
                operations[i] = 1;
                sum++;
                result++;
            } else {
                operations[i] = 0;
            }
        }
    }
    for (int i = n-k+1; i<n; i++) {
        if (operations[i] == 1) {
            cout << -1;
            return -1;
        }
    }
    cout << result;
    return result;
}