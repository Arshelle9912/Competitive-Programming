#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    long long num;
    cin >> num;
    long long ans = 0;
    vector<int> k(num);
    for (int i = 0; i<num; ++i) {
        cin >> k[i];
        k[i] = abs(k[i]);
    }
    sort(k.begin(), k.end());
    for (int j = 0; j<num; ++j) {
        auto itr = upper_bound(k.begin(), k.end(), 2*k[j]);
        itr--;
        ans += itr - k.begin() - j;
    }
    cout << ans << endl;
    return 0;
}