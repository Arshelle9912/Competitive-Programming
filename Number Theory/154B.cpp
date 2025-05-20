#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > factors(n+1);
    for (int p = 2; p <= n; ++p) {
        if (factors[p].empty()) {
            for (int j = p; j <= n; j += p) {
                factors[j].push_back(p);
            }
        }
    }
    map<int, int> mp;
    vector<bool> active(n+1);
    for (int i = 0; i<m; i++) {
        char op;
        int z;
        cin >> op >> z;
        if (op == '+') {
            if (active[z]) {
                cout << "Already on" << "\n";
            } else {
                vector<int> temp;
                bool check = true;
                for (auto x : factors[z]) {
                    auto it = mp.find(x);
                    if (it != mp.end()) {
                        cout << "Conflict with " << it->second << "\n";
                        check = false;
                        break;
                    }
                    temp.push_back(x);
                }
                if (check) {
                    for (auto x : temp) {
                        mp[x] = z;
                    }
                    cout << "Success" << "\n";
                    active[z] = true;
                }
            }
        } else {
            if (!active[z]) {
                cout << "Already off" << "\n";
            } else {
                cout << "Success" << "\n";
                active[z] = false;
                for (auto x : factors[z]) {
                    mp.erase(x);
                }
            }
        }
    }
}