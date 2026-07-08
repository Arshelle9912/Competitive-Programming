#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    map<char, int> mp;
    bool check = false;
    for (int i = 0; i<n; i++) {
        mp[line[i]]++;
        cout << line[i] << " " << mp[line[i]] << "\n";
        if (mp['(']<mp[')']) {
            cout << ") " << i;
            check = true;
            break;
        } else if (mp['{']<mp['}']) {
            cout << "} " << i;
            check = true;
            break;
        } else if (mp['[']<mp[']']) {
            cout << "] " << i;
            check = true;
            break;
        }
    }
    if (!check) cout << "ok so far";
}