#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        long long original = n;
        long long power2 = 0;
        long long power5 = 0;
        while (n%2==0) {
            power2++;
            n/=2;
        }
        while (n%5==0) {
            power5++;
            n/=5;
        }
        long long power = min(power2, power5);
        long long num = 1;
        while (power2<power5 && num*2<=m) {
            power2++;
            num*=2;
        }
        
        while (power5<power2 && num*5<=m) {
            power5++;
            num*=5;
        }
        while (num*10<=m) {
            num*=10;
        }
        num *= (m/num);
        cout << num*original << "\n";
    }
}