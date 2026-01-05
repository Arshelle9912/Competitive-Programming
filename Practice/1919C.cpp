#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr1;
        vector<int> arr2;
        int penalty=0;
        for (int i = 0; i<n; i++) {
            int temp;
            cin >> temp;
            bool check1 = false;
            bool check2 = false;
            if (!arr1.empty()) {
                if (arr1.back()>=temp) {
                    check1 = true;
                    if (arr2.empty()) {
                        arr1.push_back(temp);
                        continue;
                    }
                }
            }
            if (!arr2.empty()) {
                if (arr2.back()>=temp) check2 = true;
            }
            if (arr1.empty()) {
                arr1.push_back(temp);
                continue;
            }
            if (arr2.empty()) {
                arr2.push_back(temp);
                continue;
            }
            if (check1 && check2) {
                if (arr1.back()>arr2.back()) {
                    arr2.push_back(temp);
                } else {
                    arr1.push_back(temp);
                }
            }
            if (!check1 && check2) {
                arr2.push_back(temp);
            }
            if (check1 && !check2) {
                arr1.push_back(temp);
            }
            if (!check1 && !check2) {
                penalty++;
                if (arr1.back()>arr2.back()) {
                    arr2.push_back(temp);
                } else {
                    arr1.push_back(temp);
                }
            }
        }
        cout << penalty << "\n";
    }
}