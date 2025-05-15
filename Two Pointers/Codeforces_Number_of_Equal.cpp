#include <bits/stdc++.h>
using namespace std;

int main() {
    long long count(0);
    int n1, n2;
    cin >> n1 >> n2;
    int temp;
    map<int, int> mp1, mp2;
    for (int i = 0; i<n1; i++) {
        cin >> temp;
        mp1[temp]++;
    }
    for (int j = 0; j<n2; j++) {
        cin >> temp;
        mp2[temp]++;
    }
    for (auto a:mp1) {
        if (mp2.find(a.first) != mp2.end()) {
            count += 1LL * mp2[a.first] * mp1[a.first];
        }
    }
    cout << count << endl;
}