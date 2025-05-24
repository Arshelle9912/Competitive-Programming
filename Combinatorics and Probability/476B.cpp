#include <bits/stdc++.h>
using namespace std;

double binary_exponentiation(long long base, long long power) {
    double result = 1;
    while (power>0) {
        if (power&1) {
            result = result*base;
        }
        base = base*base;
        power>>=1;
    }
    return result;
}
double factorial(int n) {
    double result = 1;
    for (int i = 1; i<=n; i++) {
        result *= i;
    }
    return result;
}
int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    int target_sum(0), count(0), sum(0);
    for (char s : s1) {
        if (s == '+') {
            target_sum++;
        } else {
            target_sum--;
        }
    }
    for (char s : s2) {
        if (s == '+') {
            sum++;
        } else if (s == '-') {
            sum--;
        } else {
            count++;
        }
    }
    int need = target_sum - sum;
    if (count == 0) {
        if (target_sum == sum) {
            cout << fixed << setprecision(9) << 1.0 << "\n";
            return 0;
        } else {
            cout << fixed << setprecision(9) << 0.0 << "\n";
            return 0;
        }
    }
    if ((llabs(need)>count) || ((need+count) % 2 != 0)) {
        cout << fixed << setprecision(9) << 0.0 << "\n";
        return 0;
    }
    int plus(0);
    plus = (need+count)/2;
    double answer = factorial(count)*(1/factorial(plus)) * (1/factorial(count-plus)) * (1/binary_exponentiation(2, count));
    cout << fixed << setprecision(9) << answer << "\n";
}