#include <bits/stdc++.h>
using namespace std;
int idx3(char a, char b, char c) {
    return (a - 'A') * 26 * 26 + (b - 'A') * 26 + (c - 'A');
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<string> words(N);
    for (int i = 0; i < N; i++) cin >> words[i];
    vector<string> ans(26 * 26 * 26, "");
    for (int wi = 0; wi < N; wi++) {
        const string &s = words[wi];
        int n = (int)s.size();
        vector<array<int, 26>> nxt(n + 1);
        nxt[n].fill(n);
        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - 'a'] = i;
        }
        for (int a = 0; a < 26; a++) {
            for (int b = 0; b < 26; b++) {
                for (int c = 0; c < 26; c++) {
                    int id = a * 26 * 26 + b * 26 + c;
                    if (!ans[id].empty()) continue;
                    int p1 = nxt[0][a];
                    if (p1 == n) continue;
                    int p2 = nxt[p1 + 1][b];
                    if (p2 == n) continue;
                    int p3 = nxt[p2 + 1][c];
                    if (p3 == n) continue;
                    ans[id] = s;
                }
            }
        }
    }
    for (int i = 0; i < M; i++) {
        string plate;
        cin >> plate;
        int id = idx3(plate[0], plate[1], plate[2]);
        if (ans[id].empty()) cout << "No valid word\n";
        else cout << ans[id] << '\n';
    }
}