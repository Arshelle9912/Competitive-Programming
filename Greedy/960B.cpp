#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i<n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i<n; i++) {
        cin >> b[i];
    }
    multiset<vector<int>> ms;
    for (int i = 0; i<n; i++) {
        vector<int> difference = {abs(a[i]-b[i]), a[i], b[i]};
        ms.insert(difference);
    }
    for (int i = 0; i<k1; i++) {
        auto rit = prev(ms.end());
        vector<int> it = *rit;
        ms.erase(rit);
        int num1 = it[1];
        int num2 = it[2];
        if (num1>num2) {
            num1--;
        } else {
            num1++;
        }
        vector<int> difference = {abs(num1-num2), num1, num2};
        ms.insert(difference);
    }
    for (int i = 0; i<k2; i++) {
        auto rit = prev(ms.end());
        vector<int> it = *rit;
        ms.erase(rit);
        int num1 = it[1];
        int num2 = it[2];
        if (num1>num2) {
            num2++;
        } else {
            num2--;
        }
        vector<int> difference = {abs(num1-num2), num1, num2};
        ms.insert(difference);
    }
    long long result(0);
    for (int i = 0; i<n; i++) {
        auto rit = prev(ms.end());
        vector<int> it = *rit;
        ms.erase(rit);
        result += (1LL*it[0]*it[0]);
    }
    cout << result << "\n";
}