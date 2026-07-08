#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
template<typename Node, typename Update>
struct SegmentTree {
    vector<Node> tree;
    string arr;
    int n;
    int s;
    SegmentTree(int a_len, string& a) {
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
            string temp = {arr[start]};
            tree[index] = Node(temp);
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
    void make_update(int index, string val) {
        Update new_update = Update(val);
        update(0, n-1, 1, index, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n-1, 1, left, right);
    }
};

struct Node1 {
    vector<ll> freq;
    ll val;
    Node1() {
        freq.assign(26, 0);
        val = 0;
    }
    Node1(string p1) {
        freq.assign(26, 0);
        for (char c : p1) {
            freq[c-'a']++;
        }
        val = 0;
        for (int i = 0; i<26; i++) {
            if (freq[i]>0) val++;
        }
    }
    void merge(Node1& l, Node1& r) {
        freq.assign(26, 0);
        val = 0;
        for (int i = 0; i<26; i++) {
            freq[i] = l.freq[i] + r.freq[i];
            if (freq[i]>0) val++;
        }
    }
};

struct Update1 {
    vector<ll> freq;
    ll val;
    Update1(string p1) {
        freq.assign(26, 0);
        for (char c : p1) {
            freq[c-'a']++;
        }
        val = 0;
        for (int i = 0; i<26; i++) {
            if (freq[i]>0) val++;
        }
    }
    void apply(Node1 &a) {
        a.freq = freq;
        a.val = val;
    }
};

int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    SegmentTree<Node1, Update1> st(n, s);
    int type, num1, num2;
    string temp;
    for (int i = 0; i<q; i++) {
        cin >> type >> num1;
        if (type==1) {
            cin >> temp;
            st.make_update(num1-1, temp);
        } else {
            cin >> num2;
            cout << (st.make_query(num1-1, num2-1)).val << "\n";
        }
    }
}