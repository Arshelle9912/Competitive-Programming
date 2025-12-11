#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    vector<string> arr1 = {"12", "21"};
    vector<string> arr2 = {"123", "132", "213", "231", "312", "321"};
    vector<string> arr3 = {"1234", "1243", "1324", "1342", "1423", "1432", "2134", "2143", "2314", "2341", "2413", 
        "2431", "3124", "3142", "3214", "3241", "3412", "3421", "4123", "4132", "4213", "4231", "4312", "4321"};
    while (t--) {
        int n, first, end;
        cin >> n >> first >> end;
        vector<string> arr;
        if (n==12) arr = arr1;
        if (n==123) arr = arr2;
        if (n==1234) arr = arr3;
        string s1 = arr[first-1];
        string s2 = arr[end-1];
        map<char, int> mp;
        for (char c : s1) {
            mp[c]++;
        }
        int r(0), s(0);
        for (char c: s2) {
            if (mp.find(c)!=mp.end()) {
                s++;
                mp[c]--;
                if (mp[c]==0) mp.erase(c);
            }
        }
        for (int i = 0; i<s1.length(); i++) {
            if (s1[i]==s2[i]) {
                r++;
            }
        }
        cout << r << "A" << s-r << "B\n";
    }
}