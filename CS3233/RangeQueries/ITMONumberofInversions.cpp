#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
template<typename Node, typename Update>
struct SegmentTree {
    vector<Node> tree;
    vector<ll> arr;
    int n;
    int s;
    SegmentTree(int a_len, vector<ll>& a) {
        arr = a;
        n = a_len;
        s = 1;
        while (s<2*n) {
            s<<=1;
        }
        tree.resize(s);
        fill(all(tree), Node());
        build(0, n-1, 1);
    }
    void build (int start, int end, int index) {
        if (start==end) {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start+end)/2;
        build(start, mid, 2*index);
        build(mid+1, end, 2*index+1);
        tree[index].merge(tree[2*index], tree[2*index+1]);
    }
    void update(int start, int end, int index, int query_index, Update& u) {
        if (start==end) {
            u.apply(tree[index]);
            return;
        }
        int mid = (start+end)/2;
        if (mid>=query_index) {
            update(start, mid, 2*index, query_index, u);
        } else {
            update(mid+1, end, 2*index+1, query_index, u);
        }
        tree[index].merge(tree[2*index], tree[2*index+1]);
    }
    Node query(int start, int end, int index, int left, int right) {
        if (start>right || end<left) return Node();
        if (start>=left && end<=right) return tree[index];
        int mid = (start+end)/2;
        Node l, r, ans;
        l = query(start, mid, 2*index, left, right);
        r = query(mid+1, end, 2*index+1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int index, int val) {
        Update new_update = Update(val);
        update(0, n-1, 1, index, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n-1, 1, left, right);
    }
};

struct Node1 {
    vector<ll> val;
    ll inversions;
    Node1() {
        val.assign(41, 0);
        inversions = 0;
    }
    Node1(ll p1) {
        val.assign(41, 0);
        val[p1] = 1;
        inversions = 0;
    }
    void merge(Node1& l, Node1& r) {
        val.assign(41, 0);
        inversions = 0;
        for (int i = 1; i < 41; i++) {
            val[i] = l.val[i] + r.val[i];
        }
        inversions = l.inversions + r.inversions;
        
        for (int v = 1; v < 41; v++) {
            if (l.val[v] > 0) {
                ll smaller_count = 0;
                for (int smaller = 1; smaller < v; smaller++) {
                    smaller_count += r.val[smaller];
                }
                inversions += (ll)l.val[v] * smaller_count;
            }
        }
    }
};

struct Update1 {
    vector<ll> val;
    Update1(ll p1) {
        val.assign(41, 0);
        val[p1] = 1;
    }
    void apply(Node1 &a) {
        a.val = val;
        a.inversions = 0;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    SegmentTree<Node1, Update1> st(n, arr);
    int type, num1, num2;
    for (int i = 0; i<q; i++) {
        cin >> type >> num1 >> num2;
        if (type==2) {
            st.make_update(num1-1, num2);
        } else {
            cout << (st.make_query(num1-1, num2-1)).inversions << "\n";
        }
    }
}