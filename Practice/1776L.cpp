#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long count1 = 0;
    long long count2 = 0;
    for (long long i = 0; i<n; i++) {
        if (s[i]=='+') count1++;
        else if (s[i]=='-') count2++;
    }
    long long q;
    cin >> q;
    for (long long i = 0; i<q; i++) {
        long long num1, num2;
        cin >> num1 >> num2;
        if (count1==count2) {
            cout << "YES\n";
            continue;
        }
        if (num1<num2) swap(num1, num2);
        long long diff = count1 - count2;
        if (num1 == num2) {
            cout << "NO\n";
            continue;
        }
        long long k = diff*num2 / (num2 - num1);
        if ((diff*num2)%(num2-num1)==0 && (-count2 <= k && count1 >= k)) {  
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}