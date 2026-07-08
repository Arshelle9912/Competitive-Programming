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
    ll val;
    Node1() {
        val = 0;
    }
    Node1(ll p1) {
        val = 0;
    }
    void merge(Node1& l, Node1& r) {
        val = l.val + r.val;
    }
};

struct Update1 {
    ll val;
    Update1(ll p1) {
        val = 1;
    }
    void apply(Node1 &a) {
        a.val = val;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<ll> arr(2*n);
    map<int, vector<int>> mp;
    SegmentTree<Node1, Update1> st(n, arr);
    for (int i = 0; i<2*n; i++) {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
        if (mp[arr[i]].size()==2) {
            ans[arr[i]-1] = st.make_query(mp[arr[i]][0], mp[arr[i]][1]).val;
            st.make_update(mp[arr[i]][0], 1);
        }
    }
    for (int i = 0; i<n; i++) {
        cout << ans[i] << " ";
    }
}