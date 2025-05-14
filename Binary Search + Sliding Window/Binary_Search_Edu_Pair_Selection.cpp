#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    double mid, low, high, ans, sum;
    cin >> n >> k;
    vector<double> temp(n);
    vector<vector<int> > pairs(n, vector<int>(2));
    for (int i = 0; i<n; i++) {
        cin >> pairs[i][0];
        cin >> pairs[i][1];
    }
    low = 0;
    high = 1e5;
    while (high - low > 1e-7) {
        sum = 0;
        mid = low + (high - low)/2;
        for (int j = 0; j<n; j++) {
            temp[j] = pairs[j][0] - mid * pairs[j][1];
        }
        sort(temp.rbegin(), temp.rend());
        for (int a = 0; a<k; a++) {
            sum += temp[a];
        }
        if (sum >= 0) {
            ans = mid;
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}