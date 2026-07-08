#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sparseTable;
vector<int> logTable;

void build_logs(int n) {
    logTable.assign(n+1, 0);
    for (int i = 2; i <= n; i++)
        logTable[i] = logTable[i/2] + 1;
}

void build_table(int n, vector<int>& lcp) {
    if (n == 0) return;
    sparseTable.assign(logTable[n]+1, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++)
        sparseTable[0][i] = lcp[i];
    for (int i = 1; i <= logTable[n]; i++)
        for (int j = 0; j < n; j++)
            if (j + (1<<(i-1)) < n)
                sparseTable[i][j] = min(sparseTable[i-1][j], sparseTable[i-1][j+(1<<(i-1))]);
}

int rmq(int l, int r) {
    if (l > r) return 1e9;
    int k = logTable[r - l + 1];
    return min(sparseTable[k][l], sparseTable[k][r-(1<<k)+1]);
}

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]]) classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1<<h) < n; h++) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1<<h);
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++) cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int,int> cur  = {c[p[i]],   c[(p[i]   + (1<<h)) % n]};
            pair<int,int> prev = {c[p[i-1]], c[(p[i-1] + (1<<h)) % n]};
            if (cur != prev) ++classes;
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
    vector<int> rank_(n, 0);
    for (int i = 0; i < n; i++) rank_[p[i]] = i;
    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank_[i] == n-1) { k = 0; continue; }
        int j = p[rank_[i]+1];
        while (i+k < n && j+k < n && s[i+k] == s[j+k]) k++;
        lcp[rank_[i]] = k;
        if (k) k--;
    }
    return lcp;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<string> pokemons(n);
    string s = "";
    vector<int> start(n);
    for (int i = 0; i < n; i++) {
        cin >> pokemons[i];
        start[i] = s.size();
        s += pokemons[i];
        if (i != n-1) s += char(1); 
    }
    vector<int> sa = suffix_array_construction(s);
    vector<int> lcp = kasai_lcp(s, sa);
    int slen = s.size();
    vector<int> rank_(slen);
    for (int i = 0; i < slen; i++) rank_[sa[i]] = i;
    vector<int> pokemon_rank(n);
    for (int i = 0; i < n; i++)
        pokemon_rank[i] = rank_[start[i]];
    build_logs(lcp.size() + 1);
    build_table(lcp.size(), lcp);
    while (q--) {
        int m, k;
        cin >> m >> k;
        vector<int> idx(m);
        for (int i = 0; i < m; i++) {
            cin >> idx[i];
            idx[i]--; 
        }
        if (k > m) {
            cout << 0 << "\n";
            continue;
        }
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return pokemon_rank[a] < pokemon_rank[b];
        });
        vector<int> L(m+1, 0);
        for (int i = 1; i < m; i++) {
            int r1 = pokemon_rank[idx[i-1]];
            int r2 = pokemon_rank[idx[i]];
            if (r1 > r2) swap(r1, r2);
            L[i] = rmq(r1, r2 - 1);
        }
        long long answer = 0;
        if (k == 1) {
            for (int i = 0; i < m; i++) {
                int left_b = L[i];
                int right_b = L[i+1];
                int len = pokemons[idx[i]].size();
                int contrib = max(0, len - max(left_b, right_b));
                answer += contrib;
            }
        } else {
            deque<int> dq;
            for (int j = 1; j <= k-1; j++) {
                while (!dq.empty() && L[dq.back()] >= L[j]) dq.pop_back();
                dq.push_back(j);
            }
            for (int a = 0; a <= m - k; a++) {
                while (!dq.empty() && dq.front() < a+1) dq.pop_front();
                int win_min = (k == 1) ? (int)1e9 : L[dq.front()];
                int left_b  = L[a];
                int right_b = L[a+k];
                int contrib = max(0, win_min - max(left_b, right_b));
                answer += contrib;
                if (a + k <= m - 1) { 
                    int j = a + k;
                    while (!dq.empty() && L[dq.back()] >= L[j]) dq.pop_back();
                    dq.push_back(j);
                }
            }
        }
        cout << answer << "\n";
    }
}