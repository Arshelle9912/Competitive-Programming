#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> freq1(26);
        vector<long long> freq2(26);
        freq1['a'-'a'] = 1;
        freq2['a'-'a'] = 1;
        for (int i = 0; i<n; i++) {
            int num, k;
            string s;
            cin >> num >> k >> s;
            if (num==1) {
                for (int j = 0; j<s.length(); j++) {
                    freq1[s[j]-'a']+=k;
                }
            } else {
                for (int j = 0; j<s.length(); j++) {
                    freq2[s[j]-'a']+=k;
                }
            }
            pair<long long, long long> pair1;
            pair<long long, long long> pair2;
            for (int j = 0; j<26; j++) {
                if (freq1[j]>0) {
                    pair1 = {j, freq1[j]};
                    break;
                }
            }
            for (int j = 25; j>=0; j--) {
                if (freq2[j]>0) {
                    pair2 = {j, freq2[j]};
                    break;
                }
            }
            bool check1 = true;
            bool check2 = true;
            if (pair1.first<pair2.first) {
                cout << "YES" << "\n";
            } else if (pair1.first>pair2.first) {
                cout << "NO" << "\n";
            } else {
                if (pair1.second>pair2.second) {
                    cout << "NO" << "\n";
                } else if (pair1.second<pair2.second) {
                    int temp = pair1.first+1;
                    while (temp<26) {
                        if (freq1[temp]>0) {
                            cout << "NO" << "\n";
                            check1 = false;
                            break;
                        }
                        temp++;
                    }
                    if (check1) {
                        cout << "YES" << "\n";
                    }
                } else {
                    int temp = pair1.first+1;
                    while (temp<26) {
                        if (freq1[temp]>0) {
                            check2 = false;
                            break;
                        }
                        temp++;
                    }
                    temp = pair2.first-1;
                    while (temp>=0) {
                        if (freq2[temp]>0) {
                            check1 = false;
                            break;
                        }
                        temp--;
                    }
                    if (check2 && !check1) {
                        cout << "YES" << "\n";
                    } else {
                        cout << "NO" << "\n";
                    }
                }
            }
        }
    }
}