#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m , k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    deque<int> dq;
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int left(0);
    int count(0);
    for (int i = 0; i<n; i++) {
        while (!dq.empty() && arr[i] - dq.front() >= m) {
            dq.pop_front();
        }
        if (dq.size()==k-1) {
            count++;
        } else {
            dq.push_back(arr[i]);
        }
    }
    cout << count << "\n";
}