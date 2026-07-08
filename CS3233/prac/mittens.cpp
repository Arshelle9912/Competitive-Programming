#include <bits/stdc++.h>
using namespace std;
int main() {
    long long numShares = 0;
    long double totalValue = 0;
    while (true) {
        string s;
        long long num1, num2;
        cin >> s >> num1;
        if (s=="buy") {
            cin >> num2;
            totalValue+=(long double) num2* (long double) num1;
            numShares+=num1;
        } else if (s=="sell") {
            cin >> num2;
            long double averageValue = totalValue/numShares;
            numShares-=num1;
            totalValue-=averageValue*num1;
        } else if (s=="split") {
            numShares*=num1;
        } else if (s=="merge") {
            if (numShares == 0) continue;
            long double averageValue = totalValue/numShares;
            long long remainder = numShares%num1;
            totalValue-=averageValue*remainder;
            numShares /= num1;
        } else if (s=="die") {
            if (numShares==0) {
                cout << 0 << "\n";
                break;
            }
            long double sellValue = (long double) num1* (long double) numShares;
            long double profit = num1 - totalValue/numShares;
            if (profit>0) {
                cout << fixed << setprecision(8) << (sellValue - (long double)numShares * profit * 0.3L) << "\n";
            } else {
                cout << fixed << setprecision(8) << sellValue << "\n";
            }
            break;
        }
    }
}