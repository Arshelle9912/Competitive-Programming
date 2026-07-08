#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;
    void build (int node, int start, int end) {
        if (start==end) {
            tree[node] = arr[start];
        } else {
            int mid = (start+end)/2;
            int leftChild = 2*node+1;
            int rightChild = 2*node+2;
            build(leftChild, start, mid);
            build(rightChild, mid+1, end);
            tree[node] = min(tree[leftChild], tree[rightChild]);
        }
    }
    int query(int node, int start, int end, int left, int right) {
        if (start>right || end<left) return INT_MAX;
        if (start>=left && end<=right) return tree[node];
        int mid = (start+end)/2;
        int left_min = query(2*node+1, start, mid, left, right);
        int right_min = query(2*node+2, mid+1, end, left, right);
        return min(left_min, right_min); 
    }

    void update(int node, int start, int end, int index, int value) {
        if (start==end) {
            arr[index] = value;
            tree[node] = value;
        } else {
            int mid = (start+end)/2;
            int left_child = 2*node+1;
            int right_child = 2*node+2;
            if (index<=mid) {
                update(left_child, start, mid, index, value);
            } else {
                update(right_child, mid+1, end, index, value);
            }
            tree[node] = min(tree[left_child], tree[right_child]);
        }
    }
public:
    SegmentTree(vector<int>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4*n);
        if (n>0) {
            build(0, 0, n-1);
        }
    }

    int rangeMinQuery(int left, int right) {
        if (left<0 || right>=n || left>right) return INT_MAX;
        return query(0, 0, n-1, left, right);
    }

    void updateValue(int index, int value) {
        if (index<0 || index>=n) return;
        update(0, 0, n-1, index, value);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) cin >> arr[i];
    SegmentTree st(arr);
    for (int i = 0; i<q; i++) {
        int type, num1, num2;
        cin >> type >> num1 >> num2;
        if (type==1) st.updateValue(num1-1, num2);
        else cout << st.rangeMinQuery(num1-1, num2-1) << "\n";
    }
}