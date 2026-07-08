#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> skiing(n);
        vector<pair<int, int>> movie(n);
        vector<pair<int, int>> board(n);
        for (int i = 0; i<n; i++) {
            cin >> skiing[i].first;
            skiing[i].second = i;
        }
        for (int i = 0; i<n; i++) {
            cin >> movie[i].first;
            movie[i].second = i;
        }
        for (int i = 0; i<n; i++) {
            cin >> board[i].first;
            board[i].second = i;
        }
        sort(skiing.begin(), skiing.end(), greater<pair<int, int>>());
        sort(movie.begin(), movie.end(), greater<pair<int, int>>());
        sort(board.begin(), board.end(), greater<pair<int, int>>());
        int ans = 0;
        for (int i = 0; i<3; i++) {
            for (int j = 0; j<3; j++) {
                for (int k = 0; k<3; k++) {
                    int vals = skiing[i].first;
                    int inds = skiing[i].second;
                    int valm = movie[j].first;
                    int indm = movie[j].second;
                    int valb = board[k].first;
                    int indb = board[k].second;
                    if (inds!=indm && indm!=indb && indb!=inds) {
                        ans = max(ans, vals + valm + valb);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}