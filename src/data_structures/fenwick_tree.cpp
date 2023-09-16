#include <vector>

template <typename T>
struct FenwickTree {
    int len;
    std::vector<T> node;

    FenwickTree() = default;
    FenwickTree(int n) : len(n), node(n, 0) {}
    void init(int n) {
        len = n;
        node.assign(n, 0);
    }
    // sum data[0,i)
    T sum(int i) {
        T res(0);
        for (int k = i; k > 0; k -= k & -k) {
            res += node[k - 1];
        }
        return res;
    }
    // add x to data[i]
    void add(int i, T x) {
        for (int k = i + 1; k <= len; k += k & -k) {
            node[k - 1] += x;
        }
    }
};