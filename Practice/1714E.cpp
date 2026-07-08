#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> first;
        vector<int> other;
        for (int i = 0; i<n; i++) {
            int num;
            cin >> num;
            int val = num%10;
            if (val==0) {
                other.push_back(num);
            }
            if (val==1) {
                first.push_back(num+15);
            }
            if (val==2) {
                first.push_back(num+14);
            }
            if (val==3) {
                first.push_back(num+3);
            }
            if (val==4) {
                first.push_back(num+12);
            }
            if (val==5) {
                other.push_back(num+5);
            }
            if (val==6) {
                first.push_back(num);
            }
            if (val==7) {
                first.push_back(num+19);
            }
            if (val==8) {
                first.push_back(num+8);
            }
            if (val==9) {
                first.push_back(num+17);
            }
        }
        if (first.size()>0 && other.size()>0) {
            cout << "No\n";
            continue;
        } else if (first.size()>0) {
            bool check = true;
            for (int i = 1; i<first.size(); i++) {
                if (abs(first[i]-first[i-1])%20!=0) {
                    cout << "No\n";
                    check = false;
                    break;
                }
            }
            if (check) cout << "Yes\n";
        } else {
            bool check = true;
            for (int i = 1; i<other.size(); i++) {
                if (other[i]!=other[i-1]) {
                    cout << "No\n";
                    check = false;
                    break;
                }
            }
            if (check) cout << "Yes\n";
        }
    }
}