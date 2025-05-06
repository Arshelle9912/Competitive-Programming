#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int, int);
bool check(int, const vector<int> &cows, int);
int main() {
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b);
    }
}

int solve(int a, int b) {
    vector<int> cows;
    int cow, ans = 0;
    for (int i = 0; i<a; i++) {
        cin >> cow;
        cows.push_back(cow);
    }
    sort(cows.begin(), cows.end());
    int high = cows[a-1] - cows[0];
    int low = 0;
    while (low<=high) {
        int mid = (low + high)/2;
        if (check(mid, cows, b)) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

bool check(int mid, const vector<int> &cows, int b) {
    int placed = 1;
    int lastPos = cows[0];
    for (int i = 1; i < cows.size(); i++) {
        if (cows[i] - lastPos >= mid) {
            lastPos = cows[i];
            placed++;
            if (placed >= b) 
                return true;
        }
    }
    return false;
}