#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string moneyS, unitsS;
    int n;
    cin >> moneyS >> unitsS >> n;

    auto parse_num = [&](const string& s) {
        long long x = 0;
        for (char ch : s) x = x * 10 + (ch - '0');
        return x;
    };

    auto cents = [&](const string& s) {
        long long a = 0, b = 0;
        size_t dot = s.find('.');
        if (dot == string::npos) return parse_num(s) * 100;

        string left = s.substr(0, dot);
        string right = s.substr(dot + 1);

        a = left.empty() ? 0 : parse_num(left);

        if (right.size() == 0) b = 0;
        else if (right.size() == 1) b = (right[0] - '0') * 10;
        else b = (right[0] - '0') * 10 + (right[1] - '0');

        return a * 100 + b;
    };

    auto tenths = [&](const string& s) {
        long long a = 0, b = 0;
        size_t dot = s.find('.');
        if (dot == string::npos) return parse_num(s) * 10;

        string left = s.substr(0, dot);
        string right = s.substr(dot + 1);

        a = left.empty() ? 0 : parse_num(left);
        b = right.empty() ? 0 : (right[0] - '0');

        return a * 10 + b;
    };

    int B = cents(moneyS);
    int U = tenths(unitsS) * 3;

    vector<string> name(n);
    vector<int> cost(n), unit(n);

    for (int i = 0; i < n; i++) {
        string sz, costS;
        int strength;
        cin >> name[i] >> strength >> sz >> costS;

        cost[i] = cents(costS);

        if (sz == "1/1") unit[i] = strength * 30;
        else if (sz == "1/2") unit[i] = strength * 15;
        else unit[i] = strength * 10;
    }

    vector<vector<int>> prevM(B + 1, vector<int>(U + 1, -1));
    vector<vector<int>> prevU(B + 1, vector<int>(U + 1, -1));
    vector<vector<int>> prevD(B + 1, vector<int>(U + 1, -1));

    prevM[0][0] = 0;
    prevU[0][0] = 0;

    for (int m = 0; m <= B; m++) {
        for (int u = 0; u <= U; u++) {
            if (prevM[m][u] == -1) continue;
            for (int d = 0; d < n; d++) {
                int nm = m + cost[d];
                int nu = u + unit[d];
                if (nm > B || nu > U) continue;
                if (prevM[nm][nu] != -1) continue;
                prevM[nm][nu] = m;
                prevU[nm][nu] = u;
                prevD[nm][nu] = d;
            }
        }
    }

    if (prevM[B][U] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<long long> count(n, 0);
    int currM = B, currU = U;
    while (!(currM == 0 && currU == 0)) {
        int d = prevD[currM][currU];
        count[d]++;
        int pm = prevM[currM][currU];
        int pu = prevU[currM][currU];
        currM = pm;
        currU = pu;
    }

    for (int i = 0; i < n; i++) {
        if (count[i] > 0) cout << name[i] << " " << count[i] << "\n";
    }
    return 0;
}
