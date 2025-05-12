#include <bits/stdc++.h>
using namespace std;

void print(deque<int> q, vector<int>&arr) {
    while (!q.empty()) {
        cout << "{" << arr[q.front()] << ", " << q.front() << "}";
        q.pop_front();
    }
    cout << "\n";
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i:a) {
        cin >> i;
    }
    deque<int> q;
    for (int j = 0; j<k; j++) {
        while (q.size() && a[q.back()] > a[j]) {
            q.pop_back();
        }
        q.push_back(j);
        cout << j << "\n";
        print(q, a);
    } 
    for (int i = k; i<n; i++) {
        while (q.size() && a[q.back()] > a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (q.front() == i-k) {
            q.pop_front();
        }
        cout << i << "\n";
        print(q, a);
    }
}