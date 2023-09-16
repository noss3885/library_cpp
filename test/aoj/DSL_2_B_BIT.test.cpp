#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include <iostream>
#include "../../src/data_structures/fenwick_tree.cpp"

using ll = long long int;

int main() {
    int n, q;
    std::cin >> n >> q;
    FenwickTree<ll> fenwick(n);
    for (int i = 0; i < q; i++) {
        ll c, x, y;
        std::cin >> c >> x >> y;
        if (c) {
            std::cout << fenwick.sum(y) - fenwick.sum(x - 1) << std::endl;
        } else {
            fenwick.add(x - 1, y);
        }
    }
    return 0;
}