/*
Union-Find木
*/

#include <utility>
#include <vector>
using namespace std;

struct UnionFindTree {
    vector<int> par;
    vector<int> rank;
    vector<int> siz;

    void init(int n) {
        par.resize(n);
        rank.resize(n);
        siz.resize(n);
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