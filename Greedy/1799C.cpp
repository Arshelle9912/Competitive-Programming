#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i<t; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        int n = s.length();
        vector<char> ans(n);
        int left = 0, right = n-1;
        for (int i = 0; i<n; i+=2) {
            if (i == n-1) {
                ans[left] = s[i];
            } else if (s[i]==s[i+1]) {
                ans[left] = s[i];
                ans[right] = s[i];
                left++;
                right--;
            } else {
                if (s[i+1] == s[n-1]) {
                    int len = n-i-1;
                    int first = ceil(len/2.0);
                    int second = len - first;
                    while (first--) {
                        ans[left] = s[i+1];
                        left++;
                    }
                    ans[left] = s[i];
                    while (second--) {
                        ans[right] = s[i+1];
                        right--;
                    }
                    break;
                } else {
                    for (int j = i+1; j<n; j++) {
                        ans[left] = s[j];
                        left++;
                    }
                    ans[right] = s[i];
                    break;
                }
            }
        }
        string answer = "";
        for (auto it: ans) {
            answer += it;
        }
        cout << answer << "\n";
    }
}