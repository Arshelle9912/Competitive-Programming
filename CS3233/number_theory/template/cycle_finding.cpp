#include <bits/stdc++.h>
using namespace std;
int f (int x) {
    return (x*x+1) % 255;
}
pair<int, int> floydCycleFinding(int x0) {
    int tortoise = f(x0);
    int hare = f(f(x0));
    while (tortoise!=hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    int mu = 0;
    tortoise = x0;
    while (tortoise!=hare) {
        hare = f(hare);
        tortoise = f(tortoise);
        mu++;
    }
    int lambda = 1;
    hare = f(tortoise);
    while (tortoise!=hare) {
        hare = f(hare);
        lambda++;
    }
    return {mu, lambda};
}
int main() {

}