#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, c;
    cin >> n >> c;
    string s;
    cin >> s;
    long long left(0), a(0), b(0), answer(LONG_MIN), current(0);
    for (int i = 0; i<n; i++) {
        a += (s[i] == 'a');
        b += (s[i] == 'b');
        if (s[i]=='b') {
            current += a;
        }
        while (current>c) {
            a -= (s[left]=='a');
            b -= (s[left]=='b');
            if (s[left]=='a') {
                current -= b;
            }
            left++;
        }
        answer = max(answer, i-left+1);
    }
    cout << answer << endl;
}