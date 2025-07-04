#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> d(n);
        for (int i = 0; i<n; i++) {
            cin >> d[i];
        }
        vector<pair<int, int>> constraints(n);
        for (int i = 0; i<n; i++) {
            cin >> constraints[i].first >> constraints[i].second;
        }
        int sum(0);
        stack<int> st;
        bool check = true;
        for (int i = 0; i<n; i++) {
            if (d[i]==-1) {
                st.push(i);
            } else {
                sum += d[i];
            }
            while (sum<constraints[i].first) {
                if (!st.empty()) {
                    d[st.top()] = 1;
                    st.pop();
                    sum++;
                } else {
                    cout << -1 << "\n";
                    check = false;
                    break;
                }
            }
            if (!check) {
                break;
            }
            if (sum>constraints[i].second) {
                check = false;
                cout << -1 << "\n";
                break;
            }
            while (sum + st.size() > constraints[i].second) {
                d[st.top()] = 0;
                st.pop();
            }
        }
        if (check) {
            for (int i : d) {
                if (i==-1) {
                    cout << 0 << " ";
                } else {
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
    }
}