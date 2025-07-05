#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (a==b) {
            cout << 0 << "\n";
        }
        if (a<b && x<=y) {
            cout << (b-a)*x << "\n";
        }
        int cost(0);
        if (a<b && x>y) {
            while (a<b) {
                if (a%2==0) {
                    cost+=y;
                    a++;
                } else {
                    cost+=x;
                    a++;
                }
            }
            cout << cost << "\n";
        }
        if (a>b) {
            if (a&1 && a-1==b) {
                cout << y << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
}