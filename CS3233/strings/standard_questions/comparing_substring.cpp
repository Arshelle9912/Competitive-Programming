#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> cl;
vector<int> log2val;
void build_logs(int n) {
    log2val.assign(n+1, 0);
    for (int i = 2; i<=n; i++) {
        log2val[i] = log2val[i/2]+1;
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
    cl.push_back(c);
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
        cl.push_back(c);
    }
    return p;
}
vector<int> suffix_array_construction(string s) {
    cl.clear();
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}
int compare_substrings(int i, int j, int l, int n) {
    int k = log2val[l];
    pair<int, int> a = {cl[k][i], cl[k][(i+l-(1<<k))]};
    pair<int, int> b = {cl[k][j], cl[k][(j+l-(1<<k))]};
    if (a==b) return 0;
    return (a<b ? -1 : 1);
}
int main() {
    string s = "gacagaca";
    vector<int> sa = suffix_array_construction(s);
    build_logs(s.size() + 1);
    // for (int x : sa) cout << x << " ";
    // cout << "\n";
    cout << compare_substrings(0, 4, 4, s.size()) << "\n";
}