/*
Union-Find木
*/

#include <utility>
using namespace std;

const int MAX_N = 100000;

struct UnionFindTree {
    int par[MAX_N];
    int rank[MAX_N];
    int siz[MAX_N];

    void init(int n) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
            siz[i] = 1;
        }
    }
    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) rank[x]++;
        par[y] = x;
        siz[x] += siz[y];
    }
    bool is_same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        x = find(x);
        return siz[x];
    }
};