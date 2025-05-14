#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, S, temp, items, money;
    cin >> n >> S;
    vector<long long> cost(n);
    vector<long long> base(n);
    int low = 0, high = n;
    for (int i = 0; i<n; i++) {
        cin >> temp;
        base[i] = temp;
    }
    while (low <= high) {
        int j = 0;
        int mid = low + (high-low)/2;
        for (int i = 0; i<n; i++) {
            cost[i] = base[i] + (long long)(i+1)*mid;
        }
        sort(cost.begin(), cost.end());
        temp = S;
        while (j < mid) {
            temp -= cost[j];
            j++;
        }
        if (temp < 0) {
            high = mid-1;
        } else {
            items = mid;
            money = S - temp;
            low = mid+1;
        }
    }
    cout << items << " " << money << endl;
}