#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        int distance1, distance2, distance3;
        int result(-1);
        cin >> n >> m;
        cout << "? " << 1 << " " << 1 << endl;
        cin >> distance1;
        pair<long long, long long> e1, e2;
        if (distance1 + 1 <= m) {
            e1 = {1, distance1+1};
        } else {
            e1 = {distance1 + 2 - m, m};  
        }
        cout << "? " << e1.first << " " << e1.second << endl;
        cin >> distance2;
        if (distance1 + 1 <= n) {
            e2 = {distance1 + 1, 1};
        } else {
            e2 = {n, distance1+2-n};
        }
        cout << "? " << e2.first << " " << e2.second << endl;
        cin >> distance3;
        pair<long long, long long> cand1 = {-1, -1}, cand2 = {-1, -1};
        if (distance2 % 2 == 0) {
            long long k = distance2 / 2;
            cand1 = { e1.first + k,  e1.second - k };
        }
        if (distance3 % 2 == 0) {
            long long k = distance3 / 2;
            cand2 = { e2.first - k,  e2.second + k };
        }
        if (cand1.first >= 1 && cand1.first <= n && cand1.second >= 1 && cand1.second <= m) {
            cout << "? " << cand1.first << " " << cand1.second << endl;
            cin >> result;
            if (result == 0) {
                cout << "! " << cand1.first << ' ' << cand1.second << endl;
                continue;
            }
        }
        cout << "! " << cand2.first << ' ' << cand2.second << endl;
    }
}