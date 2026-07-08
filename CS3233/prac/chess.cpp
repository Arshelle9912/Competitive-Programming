#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        char startChar, endChar;
        int startInt, endInt;
        cin >> startChar >> startInt >> endChar >> endInt;
        if (startInt==endInt && startChar==endChar) {
            cout << 0 << " " << startChar << " " << startInt << "\n";
            continue;
        }
        int num1, num2;
        num1 = startChar-'A';
        num2 = endChar-'A';
        if (abs(num1-num2)==abs(startInt-endInt)) {
            cout << 1 << " " << startChar << " " << startInt << " " << endChar << " " << endInt << "\n";
            continue;
        }
        bool check = false;
        for (int i = 1; i<8; i++) {
            num1 = startChar-'A';
            num2 = endChar-'A';
            if (abs(num1+i-num2)==abs((startInt+i)-endInt) && !(startInt+i>8) && !(num1+i<0 || num1+i>=8)) {
                check = true;
                char diag = num1+i+'A';
                cout << 2 << " " << startChar << " " << startInt << " " << diag << " " << startInt+i << " " << endChar << " " << endInt << "\n";
                break;
            }
            if (abs(num1-i-num2)==abs((startInt+i)-endInt) && !(startInt+i>8) && !(num1-i<0 || num1-i>=8)) {
                check = true;
                char diag = num1-i+'A';
                cout << 2 << " " << startChar << " " << startInt << " " << diag << " " << startInt+i << " " << endChar << " " << endInt << "\n";
                break;
            }
            if (abs(num1-i-num2)==abs((startInt-i)-endInt) && !(startInt-i<=0) && !(num1-i<0 || num1-i>=8)) {
                check = true;
                char diag = num1-i+'A';
                cout << 2 << " " << startChar << " " << startInt << " " << diag << " " << startInt-i << " " << endChar << " " << endInt << "\n";
                break;
            }
            if (abs(num1+i-num2)==abs((startInt-i)-endInt) && !(startInt-i<=0) && !(num1+i<0 || num1+i>=8)) {
                check = true;
                char diag = num1+i+'A';
                cout << 2 << " " << startChar << " " << startInt << " " << diag << " " << startInt-i << " " << endChar << " " << endInt << "\n";
                break;
            }
        }
        if (!check) cout << "Impossible" << "\n";
    }
}