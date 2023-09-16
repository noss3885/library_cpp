#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#include <climits>
#include <iostream>
#include "../../src/data_structures/lazy_segmenttree.cpp"

using ll = long long int;

// RMQ & RUQ
int main() {
    int n, q;
    std::cin >> n >> q;
    auto f = [=](int a, int b) { return std::min(a, b); };
    auto g = [=](int a, int b) { return (b >= 0 ? b : a); };
    LazySegmentTree<int, int> seg(f, g, g, INT_MAX, -1);
    seg.init(n);
    for (int i = 0; i < q; i++) {
        int c, s, t;
        std::cin >> c >> s >> t;
        if (c == 0) {
            int x;
            std::cin >> x;
            seg.update(s, t + 1, x);
        } else {
            std::cout << seg.query(s, t + 1) << std::endl;
        }
    }
    return 0;
}