#include <bits/stdc++.h>
using namespace std;
struct point {
    double x, y;
};
double dist(point a, point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double totaldist(point p, vector<point>& points) {
    double sum = 0;
    for (auto&q : points) sum+=dist(p, q);
    return sum;
}
int main() {
    vector<point> points(3);
    for (int i = 0; i<3; i++) {
        cin >> points[i].x >> points[i].y;
    }
    point cur = {
        (points[0].x + points[1].x + points[2].x) / 3.0, (points[0].y + points[1].y + points[2].y) / 3.0
    };
    double step = 2000;
    double dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    double dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    double best = totaldist(cur, points);
    while (step>1e-10) {
        bool improved = false;
        for (int dir = 0; dir<8; dir++) {
            point nxt = {cur.x + dx[dir]*step, cur.y+dy[dir]*step};
            double val = totaldist(nxt, points);
            if (val < best) {
                best = val;
                cur = nxt;
                improved = true;
                break;
            }
        }
        if (!improved) step *= 0.85;
    }
    cout << fixed << setprecision(12) << cur.x << " " << cur.y << "\n";
}