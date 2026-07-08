#include <bits/stdc++.h>
using namespace std;
void computeLPSArray (string pattern, int m, vector<int>& LPS) {
    int length = 0;
    LPS[0] = 0;
    int i = 1;
    while (i<m) {
        if (pattern[i]==pattern[length]) {
            length++;
            LPS[i] = length;
            i++;
        } else {
            if (length!=0) {
                length = LPS[length-1];
            } else {
                LPS[i] = 0;
                i++;
            }
        }
    }
}
bool KMP(string pattern, string text) {
    vector<string> arr;
    string s = "";
    for (int i = 0; i<pattern.size(); i++) {
        if (pattern[i]=='*') {
            if (!s.empty()) arr.push_back(s);
            s = "";
            continue;
        }
        s+=pattern[i];
    }
    if (s!="") arr.push_back(s);
    int len = text.length();
    bool check = true;
    int start = 0;
    for (int k = 0; k<arr.size(); k++) {
        bool in = false;
        int m = arr[k].length();
        int n = text.size();
        vector<int> LPS(m);
        computeLPSArray(arr[k], m, LPS);
        int i = start; 
        int j = 0;
        while (i<n) {
            if (arr[k][j]==text[i]) {
                i++;
                j++;
            }
            if (j==m) {
                in = true;
                start=i;
                break;
            }
            else if (i<n && text[i]!=arr[k][j]) {
                if (j>0) j = LPS[j-1];
                else i++;
            }
        }
        check &= in;
    }
    return check;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    string pattern;
    cin >> pattern;
    int num;
    cin >> num;
    for (int i = 0; i<num; i++) {
        cin >> text;
        int j = 0;
        if (pattern[0]!='*') {
            while (j<pattern.size() && pattern[j]!='*') {
                j++;
            }
            if (j>text.size() || pattern.substr(0, j)!=text.substr(0, j)) {
                continue;
            }
        }
        if (pattern[pattern.size()-1]!='*') {
            int j = 0;
            while (j<pattern.size() && pattern[pattern.size()-1-j]!='*') {
                j++;
            }
            if (j>text.size() || pattern.substr(pattern.size()-j, j)!=text.substr(text.size()-j, j)) {
                continue;
            }
        }
        if (KMP(pattern, text)) {
            cout << text << "\n";
        }
    }
}