#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m = 1e5;
    vector<int> v;
    v.push_back(0);
    for (int i = 3; i<m; i+=2) {
        long long A = i * i;
        int B = A/2;
        int C = A/2 + 1;
        if (B * 1LL * B + i * 1LL * i == C * 1LL * C && A == B + C) {
            v.push_back(C);
        }
    }
    int num;
    cin >> num;
    for (int i = 0; i<num; ++i) {
        int n;
        cin >> n;
        auto upper = upper_bound(v.begin(), v.end(), n) - v.begin();
        cout << upper - 1 << endl;
    }
}