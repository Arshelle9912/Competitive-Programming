#include <bits/stdc++.h>
using namespace std;
void computeLPSArray(string pattern, int m, vector<int>& LPS) {
    LPS[0] = 0;
    int i = 1;
    int length = 0;
    while (i<m) {
        if (LPS[i]==LPS[length]) {
            length++;
            LPS[i] = length;
            i++;
        }
        else {
            if (length!=0) {
                length = LPS[length-1];
            } else {
                LPS[i] = 0;
                i++;
            }
        }
    }
}
bool KMP (string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> ans;
    vector<int> LPS(m);
    computeLPSArray(pattern, m, LPS);
    int i = 0;
    int j = 0;
    while (i<n) {
        if (text[i]==pattern[j]) {
            i++;
            j++;
        } 
        if (j==m) {
            return true;
        }
        else if (i<n && text[i]!=pattern[j]) {
            if (j!=0) {
                j = LPS[j-1];
            } else {
                i++;
            }
        }
    }
    return false;
}
int main() {
    string line;
    while (getline(cin, line)) {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if (KMP(line, "problem")) printf("yes\n");
        else printf("no\n");
    }
}