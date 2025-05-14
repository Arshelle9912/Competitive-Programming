#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
double maxSumChecker(vector<double>& temp, int n) {
    vector<double> prefix(n);
    prefix[0] = temp[0];
    prefix[1] = temp[1] + max(prefix[0], double(0));
    for (int i = 2; i<n; ++i) {
        prefix[i] = temp[i] + max(prefix[i-1], prefix[i-2]);
    }
    return max(prefix[n-1], prefix[n-2]);
}
long long bestmedian(vector<long long>& arr, int n) {
    long long left = 0, right = 1e12, median;
    while (left <= right) {
        long long mid = (left + right) / 2;
        vector<double> temp(n);
        for (int i = 0; i<n; ++i) {
            if (arr[i] >= mid) {
                temp[i] = 1;
            } else {
                temp[i] = -1;
            }
        }
        if (maxSumChecker(temp, n)>0) {
            median = mid;
            left = mid +1;
        } else {
            right = mid -1;
        }
    }
    return right;
}
double bestaverage(vector<long long>& arr, int n) {
    double low = 0, high = 1e12, error = 1e-5, avg;
    while (low <= high) {
        double mid = (low + high) /2 ;
        vector<double> temp(n);
        for (int i = 0; i<n; ++i) {
            temp[i] = arr[i] - mid;
        }
        if (maxSumChecker(temp, n) >= 0)  {
            avg = mid;
            low = mid + error;
        } else {
            high = mid - error;
        }
    }
    return avg;
}
int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i<n; ++i) {
        cin >> arr[i];
    }
    cout << setprecision(7) << bestaverage(arr,n) << endl;
    cout << bestmedian(arr, n) << endl;
}