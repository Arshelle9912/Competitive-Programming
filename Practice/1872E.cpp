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
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        string s;
        cin >> s;
        int q;
        cin >> q;
        vector<int> prefXor(n);
        prefXor[0] = arr[0];
        int xor0 = 0;
        int xor1 = 0;
        s[0] == '0' ? xor0 = arr[0] : xor1 = arr[0];
        for (int i = 1; i<n; i++) {
            prefXor[i] = arr[i] ^ prefXor[i-1];
            s[i] == '0' ? xor0 ^= arr[i] : xor1 ^= arr[i];
        }
        for (int i = 0; i<q; i++) {
            int type, num1;
            cin >> type >> num1;
            if (type==1) {
                int num2;
                cin >> num2;
                num1--;
                num2--;
                int val = prefXor[num2] ^ (num1==0 ? 0 : prefXor[num1-1]);
                xor0 ^= val;
                xor1 ^= val;
            } else {
                if (num1==0) cout << xor0 << " ";
                else cout << xor1 << " ";
            }
        }
        cout << "\n";
    }
}