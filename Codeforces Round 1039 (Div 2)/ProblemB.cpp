#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;            
    cin >> t;
    while (t--) {
        int n;     
        cin >> n;
        vector<int> p(n);
        for (int &x : p) {
            cin >> x;
        }
        int l = 0, r = n - 1;
        bool takeMax = true;      
        string ans;  
        ans.reserve(n);

        while (l <= r) {
            if (takeMax) {   
                if (p[l] > p[r]) { 
                    ans.push_back('L'); 
                    ++l; 
                }
                else { 
                    ans.push_back('R'); 
                    --r; 
                }
            } else {               
                if (p[l] < p[r]) { 
                    ans.push_back('L'); 
                    ++l; 
                }
                else { 
                    ans.push_back('R'); 
                    --r; 
                }
            }
            takeMax = !takeMax;
        }
        cout << ans << '\n';
    }
}