#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> classes(m);
        for (int i = 0; i<m; i++) {
            cin >> classes[i];
        }
        sort(classes.begin(), classes.end());
        int left = 0; int right = m-1;
        for (int i = 0; i<n; i+=2) {
            for (int j = 0; j<3; j++) {
                cout << classes[left] << " " << classes[right] << " ";
            }
            cout << "\n";
            if (i+1<n) {
                for (int j = 0; j<3; j++) {
                    cout << classes[right] << " " << classes[left] << " ";
                }
                cout << "\n";
                right--;
                left++;
            }
        }
    }
}