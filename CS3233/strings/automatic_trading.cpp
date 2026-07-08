#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> sparsetable;
vector<int> logtable;
void build_logs(int n) {
    logtable.assign(n+1, 0);
    for (int i = 2; i<=n; i++) {
        logtable[i] = logtable[i/2]+1;
    }
}
vector<int> sort_cyclic_shifts(string const&s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i<n; i++) {
        cnt[s[i]]++;
    }
    for (int i = 1; i<alphabet; i++) {
        cnt[i] += cnt[i-1];
    }
    for (int i = 0; i<n; i++) {
        p[--cnt[s[i]]] = i;
    }
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i<n; i++) {
        if (s[p[i]]!=s[p[i-1]]) classes++;
        c[p[i]] = classes-1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1<<h)<n; h++) {
        for (int i = 0; i<n; i++) {
            pn[i] = p[i] - (1<<h);
            if (pn[i]<0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
vector<int> suffix_array_construction(string s) {
    s += char(0);
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}
vector<int> kasai_lcp(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i<n; i++) {
        rank[p[i]] = i;
    }
    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i<n; i++) {
        if (rank[i]==n-1) {
            k = 0;
            continue;
        }
        int j = p[rank[i]+1];
        while (i+k<n && j+k<n && s[i+k]==s[j+k]) {
            k++;
        }
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}
void build_table(int n, vector<int>& lcp) {
    sparsetable.assign(logtable[n]+1, vector<int> (n, 1e9));
    for (int i = 0; i<n; i++) {
        sparsetable[0][i] = lcp[i];
    }
    for (int i = 1; i<logtable[n]+1; i++) {
        for (int j = 0; j<n; j++) {
            if (j+(1<<(i-1))<n) {
                sparsetable[i][j] = min(sparsetable[i-1][j], sparsetable[i-1][j+(1<<(i-1))]);
            }
        }
    }
}
int main() {
    string s;
    cin >> s;
    int n = s.length();
    build_logs(n);
    vector<int> sa = suffix_array_construction(s);
    vector<int> lcp = kasai_lcp(s, sa);
    build_table(n-1, lcp);
    vector<int> rank(n);
    for (int i = 0; i<n; i++) {
        rank[sa[i]] = i;
    }
    int q;
    cin >> q;
    for (int i = 0; i<q; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        // if (num1==num2) {
        //     cout << n-num1 << "\n";
        // }
        int ans = 1e9;
        int left = rank[num1];
        int right = rank[num2];
        if (right<left) swap(left, right);
        int len = right-left;
        int start = left;
        for (int i = logtable[len]; i>=0; i--) {
            if (len&(1<<i)) {
                ans = min(ans, sparsetable[i][start]);
                start+=(1<<i);
            }
        }
        printf("%d\n", ans);
    }
}