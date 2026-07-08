#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n, t;
    cin >> m >> n >> t;
    long long checker = 1;
    if (t==1) {
        bool check = false;
        for (int i = 1; i<=n; i++) {
            checker*=i;
            if (checker>m) {
                check = true;
                break;
            }
        }
        if (check) cout << "TLE" << "\n";
        else cout << "AC" << "\n";
    }
    if (t==2) {
        bool check = false;
        long long base = 2;
        while (n>0) {
            if (n&1) {
                checker*=base;
                if (checker>m) {
                    check = true;
                    break;
                }
            }
            base*=base;
            n>>=1;
        }
        if (check) cout << "TLE" << "\n";
        else cout << "AC" << "\n";
    }
    if (t==3) {
        bool check = false;
        for (int i = 0; i<4; i++) {
            checker*=n;
            if (checker>m) {
                check = true;
                break;
            }
        }
        if (check) cout << "TLE" << "\n";
        else cout << "AC" << "\n";
    }
    if (t==4) {
        bool check = false;
        for (int i = 0; i<3; i++) {
            checker*=n;
            if (checker>m) {
                check = true;
                break;
            }
        }
        if (check) cout << "TLE" << "\n";
        else cout << "AC" << "\n";
    }
    if (t==5) {
        if (1LL*n*n>m) cout << "TLE" << "\n";
        else cout << "AC" << "\n";
    }
    if (t==6) {
        if (1LL*n*log2(n)>m) cout << "TLE" << "\n";
        else cout << "AC" << "\n";
    }
    if (t==7) {
        if (n>m) {
            cout << "TLE" << "\n";
        } else cout << "AC" << "\n";
    }
}