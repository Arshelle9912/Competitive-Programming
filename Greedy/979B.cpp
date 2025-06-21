#include <bits/stdc++.h>
using namespace std;

int getMaxBeauty(const string &s, int n) {
    vector<int> freq(128);
    int len = s.length();
    for (char c : s) {
        freq[c]++;
    }
    int maxFreq = *max_element(freq.begin(), freq.end());
    if (n == 1 && maxFreq == len) {
        return len - 1;
    }
    return min(maxFreq + n, len);
}

int main() {
    int n;
    string kuro, shiro, katie;
    cin >> n >> kuro >> shiro >> katie;

    int b1 = getMaxBeauty(kuro, n);
    int b2 = getMaxBeauty(shiro, n);
    int b3 = getMaxBeauty(katie, n);

    if (b1 > b2 && b1 > b3) {
        cout << "Kuro\n";
    }
    else if (b2 > b1 && b2 > b3) {
        cout << "Shiro\n";
    }
    else if (b3 > b1 && b3 > b2) {
        cout << "Katie\n";
    }
    else {
        cout << "Draw\n";
    }
    return 0;
}
