#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

bool checker(vector<double>& c, int k , int n) {
    double sum = 0;
    sort(c.begin(), c.end());
    for (int i = 0; i<k; ++i) {
        sum += c[n-i-1];
    }
    return sum >= 0;
}
int main() {
    int n,k;
    cin >> n >> k;
    vector<pair<double, double> > arr(n);
    for (int i = 0; i<n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    double low = 0, high = 1e6, ans, error = 1e-7;
    while (low<=high) {
        double mid = (low + high)/2;
        vector<double> c(n);
        for (int i = 0; i<n; ++i) {
            c[i] = arr[i].first - mid * arr[i].second;
        }
        if (checker(c,k,n)) {
            ans = mid;
            low = mid + error;
        }
        else {
            high = mid - error;
        }
    }
    cout << setprecision(7) << fixed << ans << endl;
}