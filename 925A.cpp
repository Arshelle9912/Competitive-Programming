#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

int main() {
    long long n, m, v;
    int cl, ce;
    cin >> n >> m >> cl >> ce >> v;
    vector<long long> l(cl), e(ce);
    for (int i = 0; i < cl; i++) {
        cin >> l[i];
    }
    for (int j = 0; j<ce; j++) {
        cin >> e[j];
    }
    sort(l.begin(), l.end());
    sort(e.begin(), e.end());
    int q;
    cin >> q;
    while (q--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1==x2) {
            cout << llabs(y1 - y2) << endl;
            continue;
        }
        long long difference = llabs(x1-x2);
        long long best = LLONG_MAX;
        if (cl>0) {
            auto it = lower_bound(l.begin(), l.end(), y1);
            for (int k = 0; k<2; k++) {
                if (it == l.end()) {
                    --it;
                }
                long long s = *it;
                long long cost = llabs(y1-s) + difference + llabs(y2-s);
                best = min(best, cost);
                if (it == l.begin()) {
                    break;
                }
                --it;
            }
        }
        if (ce > 0) {
            auto it = lower_bound(e.begin(), e.end(), y1);
            for (int k = 0; k<2; k++) {
                if (it == e.end()) {
                    --it;
                }
                long long E = *it;
                long long vertical = (difference + v - 1)/v;
                long long cost = llabs(y1-E) + vertical + llabs(y2-E);
                best = min(best, cost);
                if(it == e.begin()) {
                    break;
                }
                --it;
            }
        }
        cout << best << endl;
    }
}