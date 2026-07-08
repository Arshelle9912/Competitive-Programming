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
void build_table(int n, vector<int>& lcp) {
    sparsetable.assign(logtable[n]+1, vector<int> (n));
    for (int i = 0; i<n; i++) {
        sparsetable[0][i] = lcp[i];
    }
    for (int i = 1; i<=logtable[n]; i++) {
        for (int j = 0; j<n; j++) {
            if (j+(1<<(i-1))<n) {
                sparsetable[i][j] = min(sparsetable[i-1][j], sparsetable[i-1][j+(1<<(i-1))]);
            }
        }
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
int rmq (int l1, int l2) {
    if (l1>l2) return -1;
    int k = logtable[l2-l1+1];
    return min(sparsetable[k][l1], sparsetable[k][l2-(1<<k)+1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s = "";
    vector<string> strings(n);
    vector<int> starts(n);
    for (int i = 0; i<n; i++) {
        starts[i] = s.size();
        cin >> strings[i];
        s+=strings[i];
        if (i!=n-1) s+=char(1);
    }
    vector<int> sa = suffix_array_construction(s);
    vector<int> lcp = kasai_lcp(s, sa);
    build_logs(lcp.size());
    build_table(lcp.size(), lcp);
    vector<int> ranks(sa.size());
    for (int i = 0; i<sa.size(); i++) {
        ranks[sa[i]] = i;
    }
    auto string_of = [&] (int rank) {
        int pos = sa[rank];
        return (int) (upper_bound(starts.begin(), starts.end(), pos)-starts.begin())-1;
    };
    for (int i = 0; i<q; i++) {
        int num;
        cin >> num;
        // vector<int> arr(num);
        // for (int j = 0; j<num; j++) {
        //     int ind;
        //     cin >> ind;
        //     --ind;
        //     arr[j] = ranks[starts[ind]];
        // }
        // sort(arr.begin(), arr.end());
        // int ans = 0;
        // for (int i = 1; i<num; i++) {
        //     int r1 = arr[i-1];
        //     int r2 = arr[i];
        //     if (string_of(r1)!=string_of(r2)) {
        //         ans = max(ans, rmq(r1, r2-1));
        //     }
        // }
        // cout << ans << "\n";
        vector<pair<int,int>> arr;
        for (int j = 0; j < num; j++) {
            int ind; cin >> ind; --ind;
            for (int k = 0; k < (int)strings[ind].size(); k++) {
                arr.push_back({ranks[starts[ind] + k], ind});
            }
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int j = 1; j < (int)arr.size(); j++) {
            int r1 = arr[j-1].first;
            int r2 = arr[j].first;
            if (arr[j-1].second != arr[j].second) {
                ans = max(ans, rmq(r1, r2-1));
            }
        }
        cout << ans << "\n";
        vector<vector<int>> best(n, vector<int>(n, 0));
        for (int k = 0; k + 1 < sa.size(); k++) {
            int s1 = string_of(k);
            int s2 = string_of(k+1);
            if (s1 != s2) {
                best[s1][s2] = max(best[s1][s2], lcp[k]);
                best[s2][s1] = best[s1][s2];
            }
        }
    }
}