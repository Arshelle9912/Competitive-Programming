#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

void bestAverage(vector<long long>, int);

void bestMedian(vector<long long>, int);

double checker(vector<double>, int);

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    bestAverage(arr, n);
    bestMedian(arr, n);
}

void bestAverage(vector<long long> arr, int n) {
    double low = 0, high = 1e12, avg, ans;
    while  (high - low >= 1e-5) {
        double mid = low + (high - low)/2;
        vector<double> temp(n);
        for (int i = 0; i<n; i++) {
            temp[i] = arr[i] - mid;
        }
        if (checker(temp, n) >= 0) {
            ans = mid;
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << fixed << setprecision(7) << ans << endl;
}

void bestMedian(vector<long long> arr, int n) {
    long long low = 0, high = 1e12, median, mid;
    while (low<=high) {
        vector<double> temp(n);
        mid = low + (high - low)/2;
        for (int i = 0; i<n; i++) {
            if (arr[i] >= mid) {
                temp[i] = 1;
            } else {
                temp[i] = -1;
            }
        }
        if (checker(temp, n) > 0) {
            median = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << median << endl;
}

double checker(vector<double> arr, int n) {
    vector<double> prefix(n);
    prefix[0] = arr[0];
    prefix[1] = arr[1] + max(prefix[0], double(0));
    for (int i = 2; i<n; i++) {
        prefix[i] = arr[i] + max(prefix[i-1], prefix[i-2]);
    }
    return max(prefix[n-1], prefix[n-2]);
}