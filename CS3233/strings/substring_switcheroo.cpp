#include <bits/stdc++.h>
using namespace std;
int checker(string& s1, string& s2, int l) {
    set<vector<int>> s;
    vector<int> freq(26);
    for (int i = 0; i<l; i++) {
        freq[s2[i] - 'a']++;
    }
    s.insert(freq);
    for (int i = l; i<s2.length(); i++) {
        freq[(s2[i-l]-'a')]--;
        freq[(s2[i]-'a')]++;
        s.insert(freq);
    }
    vector<int> freqn(26);
    for (int i = 0; i<l; i++) {
        freqn[(s1[i]-'a')]++;
    }
    if (s.find(freqn)!=s.end()) return 0;
    for (int i = l; i<s1.length(); i++) {
        freqn[(s1[i-l]-'a')]--;
        freqn[(s1[i]-'a')]++;
        if (s.find(freqn)!=s.end()) return i-l+1;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int up = min(s1.length(), s2.length());
        pair<int, int> ans = {-1, -1};
        for (int j = up; j>0; j--) {
            int num = checker(s1, s2, j);
            if (num>=0) {
                ans = {num, j};
                break;
            }
        }
        pair<int, int> checker = {-1, -1};
        if (ans==checker) {printf("NONE\n"); continue;}
        printf("%s\n", (s1.substr(ans.first, ans.second)).c_str());
    }
}