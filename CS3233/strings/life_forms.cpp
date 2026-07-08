#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
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
int string_num(int ind, vector<int>& sa, vector<int>& pref_lengths) {
    int accind = sa[ind];
    auto it1 = lower_bound(pref_lengths.begin(), pref_lengths.end(), accind);
    int stringnum = it1-pref_lengths.begin();
    return stringnum;
}
bool checker(int L, vector<int>& lcp, vector<int>& sa, vector<int>& pref_lengths, int n) {
    int i = 0;
    while (i<(int) lcp.size()) {
        set<int> used;
        if (lcp[i]>=L) {
            while (i<(int)lcp.size() && lcp[i]>=L) {
                used.insert(string_num(i, sa, pref_lengths));
                used.insert(string_num(i+1, sa, pref_lengths));
                i++;
            }
            if (used.size()>=n/2+1) return true;
        } else i++;
    }
    return false;
}
vector<int> indexes(int L, vector<int>& lcp, vector<int>& sa, vector<int>& pref_lengths, int n) {
    int i = 0;
    vector<int> starts;
    while (i<(int)lcp.size()) {
        set<int> used;
        if (lcp[i]>=L) {
            int start = i;
            while (i<(int)lcp.size() && lcp[i]>=L) {
                used.insert(string_num(i, sa, pref_lengths));
                used.insert(string_num(i+1, sa, pref_lengths));
                i++;
            }
            int end = i;
            if (used.size()>=n/2+1) {
                starts.push_back(sa[start]);
            }
        } else i++;
    }
    return starts;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        int n;
        cin >> n;
        if (n==0) break;
        vector<string> str_arr(n);
        int maxLength = 0;
        for (int i = 0; i<n; i++) {
            cin >> str_arr[i];
            maxLength = max(maxLength, (int) str_arr[i].size());
        }
        string s = "";
        vector<int> pref_lengths(n);
        for (int i = 0; i < n; i++) {
            for (char c : str_arr[i]) s += c;
            pref_lengths[i] = s.size() - 1;
            if (i != n-1) s += char(i+1);
        }
        vector<int> sa = suffix_array_construction(s);
        vector<int> lcp = kasai_lcp(s, sa);
        int low = 0;
        int high = maxLength;
        int ansLength = 0;
        while (low<=high) {
            int mid = (low+high)/2;
            if (checker(mid, lcp, sa, pref_lengths, n)) {
                low = mid+1;
                ansLength = mid;
            } else {
                high = mid-1;
            }
        }
        if (ansLength==0) {
            printf("?\n\n");
            continue;
        }
        set<string> ans;
        vector<int> starts = indexes(ansLength, lcp, sa, pref_lengths, n);
        for (int num : starts) {
            ans.insert(s.substr(num, ansLength));
        }
        for (string sn : ans) {
            printf("%s\n", sn.c_str());
        }
        printf("\n");
    }
}