#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int count(0);
        for (int i = 0; i<n; i++) {
            int temp1, temp2, x, y;
            cin >> temp1 >> temp2 >> x >> y;
            if (temp1==-1 && temp2==1) {
                if (x==(s-y)) {
                    count++;
                }
            } else if (temp1==1 && temp2==-1) {
                if ((s-x)==y) {
                    count++;
                }
            } else {
                if (x==y) {
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
}