#include <bits/stdc++.h>
using namespace std;

static const long long A = 3233;
static const long long B = 323;
static const long long C = 32;
static const long long D = 3;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, unordered_set<int>> notLike;
    notLike.reserve(2 * m + 10);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        notLike[x].insert(y);
        notLike[y].insert(x);
    }
    int q;
    cin >> q;
    set<int> line;
    long long penalty = 0;
    auto dislikes = [&](int u, int v) -> bool {
        auto it = notLike.find(u);
        if (it == notLike.end()) return false;
        return it->second.count(v);
    };
    auto contrib = [&](int id) -> long long {
        auto it = line.find(id);
        if (it == line.end()) return 0;
        bool frontBad = false, backBad = false;
        if (it != line.begin()) {
            frontBad = dislikes(id, *prev(it));
        }
        auto r = next(it);
        if (r != line.end()) {
            backBad = dislikes(id, *r);
        }
        if (frontBad && backBad) return A;
        if (frontBad) return B;
        if (backBad) return C;
        return D;
    };
    for (int i = 0; i < q; i++) {
        int d, z;
        cin >> d >> z;
        set<int> affected;
        if (d == 1) {
            auto it = line.lower_bound(z);
            if (it != line.end()) affected.insert(*it);
            if (it != line.begin()) affected.insert(*prev(it));
            for (int id : affected) penalty -= contrib(id);
            line.insert(z);
            affected.insert(z);
            for (int id : affected) penalty += contrib(id);
        } else {
            auto it = line.find(z);
            if (it != line.begin()) affected.insert(*prev(it));
            auto nx = next(it);
            if (nx != line.end()) affected.insert(*nx);
            affected.insert(z);
            for (int id : affected) penalty -= contrib(id);
            line.erase(it);
            affected.erase(z);
            for (int id : affected) penalty += contrib(id);
        }
        cout << penalty << '\n';
    }
    return 0;
}