#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
void build_primes() {
    const int LIM = 31623;
    vector<bool> is_prime(LIM+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= LIM; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j<=LIM; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i<=LIM; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}

vector<pair<long long, int>> factorize(long long x) {
    vector<pair<long long,int>> fac;
    long long tmp = x;
    for (int p : primes) {
        long long pp = p;
        if (pp*pp>tmp) break;
        if (tmp%pp==0) {
            int c = 0;
            while (tmp%pp==0) {
                tmp /= pp;
                c++;
            }
            fac.push_back({pp, c});
        }
    }
    if (tmp>1) fac.push_back({tmp, 1});
    return fac;
}

void generate_divisors(int index, long long curr, const vector<pair<long long, int>> &fac, vector<long long> &divs) {
    if (index == (int) fac.size()) {
        divs.push_back(curr);
        return;
    }
    auto [p,e] = fac[index];
    long long mul = 1;
    for (int i = 0; i<=e; i++) {
        generate_divisors(index+1, curr*mul, fac, divs);
        mul*=p;
    }
}

vector<long long> get_divisors(long long x) {
    auto fac = factorize(x);
    vector<long long> divs;
    divs.reserve(64);
    generate_divisors(0, 1, fac, divs);
    return divs;
}
int main() {
    build_primes();
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }
        set<long long> sSet;
        for (long long x : a) sSet.insert(x);
        vector<long long> S;
        S.reserve(sSet.size());
        for (auto x : sSet) S.push_back(x);
        int d = S.size();
        unordered_map<long long, int> cnt;
        for (long long x : S) {
            vector<long long> divs = get_divisors(x);
            for (long long dv : divs) {
                cnt[dv]++;
            }
        }
        vector<long long> G;
        for (long long b : S) {
            long long need = k / b;
            auto it = cnt.find(b);
            int have = (it == cnt.end() ? 0 : it->second);
            if (have == need) {
                G.push_back(b);
            }
        }
        if (G.empty()) {
            cout << -1 << "\n";
            continue;
        }
        sort(G.begin(), G.end());
        set<long long> goodSet(G.begin(), G.end());
        bool feasible = true;
        if (goodSet.count(1)) {
            feasible = true;
        } else {
            for (long long x: S) {
                bool ok = false;
                vector<long long> divs = get_divisors(x);
                for (long long dv : divs) {
                    if (goodSet.count(dv)) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    feasible = false;
                    break;
                }
            }
        }
        if (!feasible) {
            cout << -1 << "\n";
            continue;
        }
        vector<long long> B;
        for (long long x : G) {
            bool has_smaller_good_div = false;
            vector<long long> divs = get_divisors(x);
            for (long long dv : divs) {
                if (dv!=x && goodSet.count(dv)) {
                    has_smaller_good_div = true;
                    break;
                }
            }
            if (!has_smaller_good_div) {
                B.push_back(x);
            }
        }
        cout << B.size() << "\n";
        for (int i = 0; i < (int)B.size(); i++) {
            if (i) cout << " ";
            cout << B[i];
        }
        cout << "\n";
    }
}