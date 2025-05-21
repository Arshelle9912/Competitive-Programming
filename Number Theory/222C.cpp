#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

static vector<int> build_spf(int maxV) {
    vector<int> spf(maxV+1, 0), primes;
    spf[1] = 1;
    for (int i = 2; i<=maxV; i++) {
        if (spf[i]==0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            long long ip = 1LL * i * p;
            if (ip>maxV || p>spf[i]) {
                break;
            }
            spf[ip] = p;
        }
    }
    return spf;
}

int main() {
    int n, m;
    cin >> n >> m;
    int temp;
    map<int, int> mp1, mp2;
    set<long long> primes_used;
    vector<int> a1(n), a2(m);
    for (int j = 0; j<n; j++) {
        cin >> a1[j];
    }
    for (int j = 0; j<m; j++) {
        cin >> a2[j];
    }
    auto spf = build_spf(10000001);
    auto factor = [&](int x, map<int, int>& mp) {
        while (x>1) {
            int p = spf[x], e = 0;
            while(x%p==0) {
                x/=p;
                e++;
            }
            mp[p] += e;
            primes_used.insert(p);
        }
    };
    for (int &x : a1) {
        factor(x, mp1);
    }
    for (int &x : a2) {
        factor(x, mp2);
    }
    map<int, int> remove;
    for (int p : primes_used) {
        remove[p] = min(mp1[p], mp2[p]);
    }
    vector<int> outA = a1;
    for (int &x : outA) {
        int t = x, result = 1;
        while (t>1) {
            int p = spf[t], e = 0;
            while (t%p==0) {
                t/=p;
                ++e;
            }
            int use = min(e, remove[p]);
            remove[p] -= use;
            e -= use;
            while (e--) {
                result *= p;
            }
        }
        x = result;
    }
    for (int p : primes_used) {
        remove[p] = min(mp1[p], mp2[p]);
    }

    vector<int> outB = a2;
    for (int &x : outB) {
        int t = x, result = 1;
        while (t>1) {
            int p = spf[t], e = 0;
            while (t%p==0) {
                t/=p;
                ++e;
            }
            int use = min(e, remove[p]);
            remove[p] -= use;
            e -= use;
            while (e--) {
                result *= p;
            }
        }
        x = result;
    }
    
    cout << n << " " << m << "\n";
    for (int v : outA) {
        cout << v << " ";
    } 
    cout << "\n";
    for (int v : outB) {
        cout << v << " ";
    }
    cout << "\n";
}