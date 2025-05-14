#include <bits/stdc++.h>
using namespace std;

struct median {
    long long sum_left, sum_right;
    multiset<int> left, right;
    median() {
        sum_left = 0;
        sum_right = 0;
    }
    void adjust() {
        if (left.size() && right.size() && *right.begin() < *left.rbegin()) {
            int leftLast = *left.rbegin();
            int rightFirst = *right.begin();
            sum_left -= leftLast;
            sum_right -= rightFirst;
            sum_left += rightFirst;
            sum_right += leftLast;
            auto it_left = left.find(leftLast);
            if (it_left != left.end()) left.erase(it_left);
            left.insert(rightFirst);
            auto it_right = right.find(rightFirst);
            if (it_right != right.end()) right.erase(it_right);
            right.insert(leftLast);
        }
        if (left.size() > right.size() + 1) {
            sum_left -= *left.rbegin();
            sum_right += *left.rbegin();
            right.insert(*left.rbegin());
            auto it_left = left.find(*left.rbegin());
            if (it_left != left.end()) left.erase(it_left);
        }
        else if (right.size() > left.size()) {
            sum_left += *right.begin();
            sum_right -= *right.begin();
            left.insert(*right.begin());
            auto it_right = right.find(*right.begin());
            if (it_right != right.end()) right.erase(it_right);
        }
    }
    void insert(int x) {
        right.insert(x);
        sum_right += x;
        adjust();
    }
    void remove(int x) {
        auto it_right = right.find(x);
        if (it_right != right.end()) {
            sum_right -= x;
            right.erase(it_right);
        } 
        else {
            auto it_left = left.find(x);
            if (it_left != left.end()) {
                sum_left -= x;
                left.erase(it_left);
            }
        }
        adjust();
    }
    long long cost() {
        return ((1ll * left.size() * (*left.rbegin())) - sum_left) + (sum_right - (1ll * right.size() * (*left.rbegin())));
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    median container;
    for (int i = 0; i<k; i++) {
        container.insert(arr[i]);
    }
    cout << container.cost() << " ";
    for (int i = k; i<n; i++) {
        container.remove(arr[i-k]);
        container.insert(arr[i]);
        cout << container.cost() << " ";
    }
}