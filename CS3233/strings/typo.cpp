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
struct Hashing{
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 1000000007};
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowersOfBase;
    Hashing(string a){
        primes = sz(hashPrimes);
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length(); 
        for(int i = 0; i < sz(hashPrimes); i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(int j = 1; j <= n; j++){
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for(int j = n - 1; j >= 0; j--){
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            } 
        }
        for(int i = 0; i < sz(hashPrimes); i++) {
            hashValues[i].resize(n);
            for(int j = 0; j < n; j++){
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<ll> substringHash(int l, int r){
        vector<ll> hash(primes);
        for(int i = 0; i < primes; i++){
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<pair<ll, ll>> se;
    vector<string> strings(n);
    for (int i = 0; i<n; i++) {
        string s;
        cin >> s;
        strings[i] = s;
        Hashing h = Hashing(s);
        vector<ll> temp = h.substringHash(0, s.size()-1);
        pair<ll, ll> pair = {temp[0], temp[1]};
        se.insert(pair);
    }
    vector<string> ans;
    for (int i = 0; i<n; i++) {
        int len = strings[i].length();
        Hashing h = Hashing(strings[i]);
        bool check = false;
        for (int j = 0; j<len; j++) {
            if (j==0) {
                vector<ll> subHash = h.substringHash(1, len-1);
                pair<ll, ll> p = {subHash[0], subHash[1]};
                if (se.find(p)!=se.end()) {
                    ans.push_back(strings[i]);
                    break;
                }
                continue;
            }
            if (j==len-1) {
                vector<ll> subHash = h.substringHash(0, len-2);
                pair<ll, ll> p = {subHash[0], subHash[1]};
                if (se.find(p)!=se.end()) {
                    ans.push_back(strings[i]);
                    break;
                }
                continue;
            }
            vector<ll> subHash1 = h.substringHash(0, j-1);
            vector<ll> subHash2 = h.substringHash(j+1, len-1);
            int nlen = len-1-(j+1)+1;
            int MOD1 = 1000000009;
            int MOD2 = 1000000007;
            ll pairFirst = (subHash1[0] + (subHash2[0] * h.powersOfBase[0][j]) % MOD1) % MOD1;
            ll pairSecond = (subHash1[1] + (subHash2[1] * h.powersOfBase[1][j]) % MOD2) % MOD2;
            pair<ll, ll> p = {pairFirst, pairSecond};
            if (se.find(p)!=se.end()) {
                ans.push_back(strings[i]);
                break;
            }
        }
    }
    if (ans.empty()) {cout << "NO TYPOS\n"; return 0;}
    for (string ns : ans) {
        cout << ns << "\n";
    }
}