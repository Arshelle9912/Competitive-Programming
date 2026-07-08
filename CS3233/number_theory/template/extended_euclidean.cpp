// if there's another number m, such that b and m are coprimes, then x is the mod inverse of a%b,
// in simple terms (a/b)%m = (a*x)%m
// will also be used in Chinese Remainder Theorem
#include <bits/stdc++.h>
using namespace std;
long long extended_euclidean(long long a, long long b, long long &x, long long &y) {
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extended_euclidean(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}
long long mod_inverse(long long a, long long m) {
    long long x, y;
    long long g = extended_euclidean(a, m, x, y);
    if (g != 1) return -1;
    x %= m;
    if (x < 0) x += m;
    return x;
}
int main() {
    long long a = 30, b = 18;
    long long x, y;

    long long g = extended_euclidean(a, b, x, y);

    cout << "gcd = " << g << "\n";
    cout << "x = " << x << "\n";
    cout << "y = " << y << "\n";
    cout << a << "*" << x << " + " << b << "*" << y << " = " << g << "\n";
}