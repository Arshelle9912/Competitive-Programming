#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n;
    cin >> n;
    long long result(0);
    map<long long,int> expo;
    for (long long i = 2; i*i <= n; i++){
        int power(0);
        while (n % i == 0){
            power++;
            n /= i;
        }
        long long k(0);
        while ((k)*(k+1)/2 <= power) {
            k++;
        }
        result+=k-1;
    }
    if (n > 1) {
        result++;
    };
    cout << result << "\n";
}