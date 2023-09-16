#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"
#include <climits>
#include <iostream>
#include "../../src/data_structures/lazy_segmenttree.cpp"

using ll = long long int;

// RSQ & RUQ
int main() {
    int n, q;
    ll INF = INT_MAX;
    std::cin >> n >> q;
    auto f = [=](ll a, ll b) { return a + b; };
    auto g = [=](ll a, ll b) { return (b != INF ? b : a); };
    auto p = [=](ll a, int b) { return a * b; };
    LazySegmentTree<ll, ll> seg(f, g, g, 0, INF, p);
    seg.init(n);
    for (int i = 0; i < q; i++) {
        int c, s, t;
        std::cin >> c >> s >> t;
        if (c == 0) {
            ll x;
            std::cin >> x;
            seg.update(s, t + 1, x);
        } else {
            std::cout << seg.query(s, t + 1) << std::endl;
        }
    }
    return 0;
}