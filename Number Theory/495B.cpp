#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (b>a) {
        cout << 0 << "\n";
        return 0;
    } else if (b==a) {
        cout << "infinity" << "\n";
        return 0;
    }
    int factorisation = a-b;
    int count(0);
    for (int i = 1; i*i<=factorisation; i++) {
        if (factorisation%i==0) {
            int j = factorisation / i;
            if (i > b) {
                count++;
            }
            if (j != i && j > b) {
                count++;
            }
        }
    }
    cout << count << "\n";
}