#include <bits/stdc++.h>
using namespace std;

vector<int> monotonic_stack(vector<int>&, int);
int main() {
    int n, k;
    vector<int> ans;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i:a) {
        cin >> i;
    }
    ans = monotonic_stack(a, k);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

vector<int> monotonic_stack(vector<int> &a, int k) {
    int n = a.size();
    vector<int> ans;
    deque<int> deq;
    for (int i = 0; i<n; i++) {
        if (!deq.empty() && deq.front() == i - k) {
            deq.pop_front();
        }
        while (!deq.empty() && a[deq.back()] > a[i]) {
            deq.pop_back();
        }
        deq.push_back(i);
        
        if (i >= k-1) {
            ans.push_back(deq.front() + 1);
        }
    }
    return ans;
}