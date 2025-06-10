#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(x) ((int)(x).size())
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1;} return res;}
void extendgcd(ll a, ll b, ll* v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x;}
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return ((a + b) % m + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return ((a * b) % m + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return ((a - b) % m + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return mod_mul(a, mminvprime(b, m), m);}
struct Hashing {
    string s;
    int n;
    long long hashPrimes = 1000000009;
    const long long base = 31;
    vector<long long> hashValues;
    vector<long long> powersOfBase;
    vector<long long> inversePowersOfBase;

    Hashing(const string &a) {
        s = a;
        n = s.size();
        hashValues.resize(n);
        powersOfBase.resize(n + 1);
        inversePowersOfBase.resize(n + 1);

        powersOfBase[0] = 1;
        for (int j = 1; j <= n; j++) {
            powersOfBase[j] = (base * powersOfBase[j - 1]) % hashPrimes;
        }

        inversePowersOfBase[n] = mminvprime(powersOfBase[n], hashPrimes);
        for (int j = n - 1; j >= 0; j--) {
            inversePowersOfBase[j] = mod_mul(inversePowersOfBase[j + 1], base, hashPrimes);
        }

        for (int j = 0; j < n; j++) {
            long long v = (s[j] - 'a' + 1LL) * powersOfBase[j] % hashPrimes;
            hashValues[j] = (v + (j > 0 ? hashValues[j - 1] : 0LL)) % hashPrimes;
        }
    }
    
    long long substringHash(int l, int r) {
        long long val1 = hashValues[r];
        long long val2 = (l > 0 ? hashValues[l - 1] : 0LL);
        long long h = ( (val1 - val2 + hashPrimes) % hashPrimes );
        return mod_mul(h, inversePowersOfBase[l], hashPrimes);
    }
};

int main() {
    string s;
    cin >> s;
    int n = s.length();
    Hashing h = Hashing(s);
    vector<pair<ll, ll>> check;
    for (int i = 0; i<n; i++) {
        if (h.substringHash(0, i)==h.substringHash(n-i-1, n-1)) {
            pair<ll, ll> p = {0, i};
            check.push_back(p);
        }
    }
    if (check.empty()) {
        cout << "Just a legend" << "\n";
        return 0;
    }
    int left = 0, right = check.size()-1;
    string result = "";
    while (left<=right) {
        int mid = (left+right)/2;
        ll start = check[mid].first;
        ll end = check[mid].second;
        ll size = end - start + 1;
        bool b = false;
        ll borderHash = h.substringHash(start, end);
        for (int j = 1; j+size-1<n-1; j++) {
            if (h.substringHash(j, j+size-1)==borderHash) {
                result = s.substr(j, size);
                b = true;
                break;
            }
        }
        if (b) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    result == "" ? cout << "Just a legend" << "\n" : cout << result << "\n";
    return 0;
}
