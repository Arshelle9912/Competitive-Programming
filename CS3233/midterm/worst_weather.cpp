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
    ll count;
    Node1() {
        val = 0;
    }
    Node1(ll p1) {
        val = p1;
        count=1;
    }
    void merge(Node1& l, Node1& r) {
        val = max(l.val, r.val);
        count = l.count+r.count;
    }
};

struct Update1 {
    ll val;
    Update1(ll p1) {
        val = p1;
    }
    void apply(Node1 &a) {
        a.val = val;
    }
};

int main() {
    int n, m;
    bool first = true;

    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            scanf("%d", &m);
            if (m == 0) break;
        }

        vector<int> years(n);
        vector<ll> rain(n);
        map<int, int> index;

        for (int i = 0; i < n; i++) {
            scanf("%d %lld", &years[i], &rain[i]);
            index[years[i]] = i;
        }

        SegmentTree<Node1, Update1> st(n, rain);

        scanf("%d", &m);

        if (!first) printf("\n");
        first = false;

        for (int i = 0; i < m; i++) {
            int y1, y2;
            scanf("%d %d", &y1, &y2);

            bool has1 = index.count(y1);
            bool has2 = index.count(y2);

            if (!has1 && !has2) {
                printf("maybe\n");
                continue;
            }

            if (has1 && has2) {
                int ind1 = index[y1];
                int ind2 = index[y2];

                if (rain[ind1] < rain[ind2]) {
                    printf("false\n");
                    continue;
                }

                Node1 mid = st.make_query(ind1 + 1, ind2 - 1);
                if (mid.val >= rain[ind2]) {
                    printf("false\n");
                    continue;
                }

                if (ind2 - ind1 == y2 - y1) printf("true\n");
                else printf("maybe\n");
            }
            else if (has1 && !has2) {
                int ind1 = index[y1];

                auto itL = index.upper_bound(y1);   // first > y1
                auto itR = index.lower_bound(y2);   // first >= y2

                if (itL == itR) {
                    printf("maybe\n");
                    continue;
                }

                int l = itL->second;
                auto tmp = itR;
                --tmp;
                int r = tmp->second;

                Node1 mid = st.make_query(l, r);
                if (mid.val >= rain[ind1]) printf("false\n");
                else printf("maybe\n");
            }
            else { // !has1 && has2
                int ind2 = index[y2];

                auto itL = index.upper_bound(y1);   // first > y1
                auto itR = index.lower_bound(y2);   // first >= y2

                if (itL == itR) {
                    printf("maybe\n");
                    continue;
                }

                int l = itL->second;
                auto tmp = itR;
                --tmp;
                int r = tmp->second;

                Node1 mid = st.make_query(l, r);
                if (mid.val >= rain[ind2]) printf("false\n");
                else printf("maybe\n");
            }
        }
    }
}