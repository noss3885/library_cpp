#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#include <iostream>
#include "../../src/data_structures/lazy_segmenttree.cpp"

using ll = long long int;

// RSQ & RAQ
int main() {
    int n, q;
    std::cin >> n >> q;
    auto f = [=](ll a, ll b) { return a + b; };
    auto p = [=](ll a, int b) { return a * b; };
    LazySegmentTree<ll, ll> seg(f, f, f, 0, 0, p);
    seg.init(n);
    for (int i = 0; i < q; i++) {
        int c, s, t;
        std::cin >> c >> s >> t;
        if (c == 0) {
            ll x;
            std::cin >> x;
            seg.update(s - 1, t, x);
        } else {
            std::cout << seg.query(s - 1, t) << std::endl;
        }
    }
    return 0;
}