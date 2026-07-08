#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    vector<string> core;
    set<string> seen;
    while (true) {
        getline(cin, line);
        if (line=="***") break;
        string s = "";
        for (int i = 0; i<line.size(); i++) {
            if (isalpha(line[i])) {
                s+=tolower(line[i]);
            } else if (line[i]==' ' || (line[i]=='\\' && i+1<line.size() && (line[i+1]=='n' || line[i+1]=='r'))) {
                if (!s.empty() && seen.find(s)==seen.end()) {core.push_back(s); seen.insert(s);}
                s="";
            }
        }
        if (!s.empty() && seen.find(s)==seen.end()) {core.push_back(s); seen.insert(s);}
    }
    sort(core.begin(), core.end());
    int n = core.size();
    bool checking = false;
    for (int i = 0; i<n; i++) {
        vector<string> temp;
        for (int j = 0; j<n; j++) {
            if (i==j) continue;
            if (abs((int) core[i].size()- (int) core[j].size())>1) continue;
            int a = 0;
            int b = 0;
            int a1 = core[i].size();
            int a2 = core[j].size();
            bool check1 = true;
            bool check2 = true;
            string temp1 = core[i];
            string temp2 = core[j];
            if (a1<a2) {
                swap(a1, a2);
                swap(temp1, temp2);
            }
            if (a1==a2) {
               int a = 0;
                while (a<a1) {
                    if (core[i][a]!=core[j][a]) {
                        if (check1) check1 = false;
                        else {check2 = false; break;}
                        if (a+1<a1 && core[i][a+1]==core[j][a] && core[i][a]==core[j][a+1]) {a+=2; continue;}
                        a++;
                    } else {
                        a++;
                    }
                }
            } else {
                while (b<a2 && a<a1) {
                    if (temp1[a]==temp2[b]) {
                        a++;
                        b++;
                    } else {
                        if (check1) check1 = false;
                        else {check2 = false; break;}
                        a++;
                    }
                }
            }
            if (check2) temp.push_back(core[j]);
        }
        if (temp.size()>0) {
            checking = true;
            printf("%s: ", core[i].c_str());
            for (string s : temp) {
                printf("%s ", s.c_str());
            }
            printf("\n");
        }
    }
    if (!checking) printf("***\n");
}