#include <bits/stdc++.h>
using namespace std;
int m, n;
bool vis[10][10];
int ans = 0;
pair<int, int> A, B, C;
int total;
bool inside(int r, int c) {
    return r>=0 && r<m && c>=0 && c<n;
}
int manhattan(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}
void dfs(int r, int c, int step) {
    if (!inside(r, c) || vis[r][c]) return;
    if (step==total/4 && make_pair(r, c)!=A) return;
    if (step==total/2 && make_pair(r, c)!=B) return;
    if (step==3*total/4 && make_pair(r, c)!=C) return;
    if (make_pair(r,c) == A && step != total/4) return;
    if (make_pair(r,c) == B && step != total/2) return;
    if (make_pair(r,c) == C && step != 3*total/4) return;
    if (step == total) {
        if (r == 0 && c == 1) ans++;
        return;
    }
    pair<int, int> target;
    int targetStep;
    if (step<total/4) target=A, targetStep=total/4;
    else if (step<total/2) target=B, targetStep=total/2;
    else if (step<3*total/4) target=C, targetStep=3*total/4;
    else target={0,1}, targetStep=total;
    int rem = targetStep - step;
    if (manhattan(r, c, target.first, target.second) > rem) return;
    vis[r][c] = true;
    dfs(r+1, c, step+1);
    dfs(r-1, c, step+1);
    dfs(r, c+1, step+1);
    dfs(r, c-1, step+1);
    vis[r][c] = false;
}
int main() {


}