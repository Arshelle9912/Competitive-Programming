#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, left(0);
    cin >> n >> m;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    long long count(0);
    map<char, int> mp1, mp2;
    for (int i = 0; i<m; i++) {
        mp2[s2[i]]++;
    }
    for (int i = 0; i<n; i++) {
        mp1[s1[i]]++;
        while (mp1[s1[i]]>mp2[s1[i]]) {  
            mp1[s1[left]]--;
            left++;
        }
        count += i - left + 1;
    }
    cout << count << endl;
}