#include <utility>
#include <vector>

struct UnionFindTree {
    int N;
    std::vector<int> par;
    std::vector<int> siz;

    UnionFindTree() = default;
    UnionFindTree(int n) : N(n) { init(n); }
    void init(int n) {
        par.resize(n);
        siz.assign(n, 1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int root(int x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = root(par[x]);
    }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) std::swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        N--;
        return true;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        return siz[root(x)];
    }
    int count() {
        return N;
    }
};