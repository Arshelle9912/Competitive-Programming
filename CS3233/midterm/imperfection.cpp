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
    void make_update(int index, ll val, ll cnt) {
        Update new_update = Update(val, cnt);
        update(0, n-1, 1, index, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n-1, 1, left, right);
    }
    ll sum_cheapest_k (int start, int end, int index, ll k, const vector<ll>& vals) {
        if (k<=0) return 0;
        if (tree[index].cnt<=k) return tree[index].val;
        if (start==end) {
            return k*vals[start];
        }
        int mid = (start+end)/2;
        ll leftCnt = tree[2*index].cnt;
        if (leftCnt>=k) {
            return sum_cheapest_k(start, mid, 2*index, k, vals);
        } else {
            return tree[2*index].val + sum_cheapest_k(mid+1, end, 2*index+1, k-leftCnt, vals);
        }
    }
    ll sum_cheapest_k(ll k, const vector<ll>& vals) {
        if (k<=0) return 0;
        k = min(k, tree[1].cnt);
        return sum_cheapest_k(0, n-1, 1, k, vals);
    }
};

struct Node1 {
    ll val;
    ll cnt;
    Node1() {
        val = 0;
        cnt = 0;
    }
    Node1(ll p1) {
        val = 0;
        cnt = 0;
    }
    void merge(Node1& l, Node1& r) {
        cnt = l.cnt+r.cnt;
        val = l.val+r.val;
    }
};

struct Update1 {
    ll val;
    ll cnt;
    Update1(ll p1=0, ll p2=0) : val(p1), cnt(p2) {
    }
    void apply(Node1 &a) {
        a.val += val;
        a.cnt+=cnt;
    }
};

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    vector<ll> val(n);
    vector<pair<ll, ll>> comb(n);
    for (int i = 0; i<n; i++) {
        cin >> val[i];
        comb[i] = {arr[i], val[i]};
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    vector<ll> init(val.size());
    SegmentTree<Node1, Update1> st(val.size(), init);
    sort(comb.begin(), comb.end());
    vector<ll> suff(n);
    suff[n-1] = comb[n-1].second;
    for (int i = n-2; i>=0; i--) {
        suff[i] = suff[i+1]+comb[i].second;
    }
    ll ans = LLONG_MAX;
    int l = 0;
    while (l<n) {
        int r = l;
        while (r+1<n && comb[r+1].first==comb[r].first) r++;
        vector<ll> same;
        same.reserve(r-l+1);
        for (int i = l; i<=r; i++) {
            same.push_back(comb[i].second);
        }
        sort(same.begin(), same.end());
        vector<ll> pref(same.size() + 1, 0);
        for (int i = 0; i < (int)same.size(); i++) {
            pref[i + 1] = pref[i] + same[i];
        }
        ll forced = (r + 1 < n ? suff[r + 1] : 0);
        ll cntLess = st.tree[1].cnt;
        ll f = same.size();
        ll need = max(0LL, cntLess-(f-1));
        ll costLess = st.sum_cheapest_k(need, val);
        ans = min(ans, forced + costLess);
        for (int i = l; i<=r; i++) {
            ll x = comb[i].second;
            ll pos = lower_bound(val.begin(), val.end(), x) - val.begin();
            st.make_update(pos, x, 1);
        }
        l=r+1;
    }
    printf("%lld\n", ans);
}