#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& cities, vector<int>& towers, int mid) {
    int i = 0, j = 0;
    bool ans = true;
    while (i < cities.size() && j < towers.size()) {
        if (abs(cities[i] - towers[j]) > mid) {
            if (cities[i] > towers[j]) {
                j++;
            } else {
                ans = false;
                break;
            }
        } else {
            i++;
        }
    }
    if (i < cities.size()) {
        ans = false;
    }
    return ans;
}

int binarySearch(vector<int>& cities, vector<int>& towers) {
    int high = 2e9;
    int result;
    int low = 0;
    long long mid;
    while (low<=high) {
        bool ans = true;
        int i = 0, j = 0;
        mid = low + (high - low)/2;
        if (check(cities, towers, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}
int main() {
    int cit, tow;
    cin >> cit >> tow;
    int max = 0;
    vector<int> cities(cit);
    vector<int> towers(tow);
    for (int i = 0; i<cit; ++i) {
        cin >> cities[i];
    }
    for (int j = 0; j<tow; ++j) {
        cin >> towers[j];
    }
    cout << binarySearch(cities, towers);
}