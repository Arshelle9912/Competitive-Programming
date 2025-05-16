#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, result(INT_MAX), checker;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> indexes;
    for (int i = 0; i<n; i++) {
        if (s[i] == '0') {
            indexes.push_back(i);
        }
    }
    for (int left = 0; left<indexes.size()-k; left++) {
        int right = left + k;
        int a = indexes[left];
        int b = indexes[right];
        int mid = (a+b+1)/2;
        int low = left, high = right+1;
        while (low<high) {
            int m = (low+high)/2;
            if (indexes[m]<mid) {
                low = m+1;
            } else {
                high = m;
            }
        }
        int next = low;
        auto cost = [&](int p) {
            return max(p - a, b - p);
        };
        checker = INT_MAX;
        if (next <= right) {
            checker = min(checker, cost(indexes[next]));
        }
        if (next - 1 >= left) {
            checker = min(checker, cost(indexes[next - 1]));
        }
        result = min(result, checker);
    }
    cout << result << "\n";
}