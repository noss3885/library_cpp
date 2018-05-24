#include <vector>
#include <algorithm>

using namespace std;

struct segtree {
    int H, W;
    const int inf = 99999999;
    vector<vector<int>> dat;
    segtree() {}
    segtree(vector<vector<int>> &f) {
        H = W = 1;
        while (H < (int)f.size()) H <<= 1;
        while (W < (int)f[0].size()) W <<= 1;
        dat.assign(2 * H - 1, vector<int>(2 * W - 1, inf));
        init(f);
    }
    void init(vector<vector<int>> &f) {
        for (int i = 0; i < (int)f.size(); i++)
            for (int j = 0; j < (int)f[0].size(); j++)
                dat[i + H - 1][j + W - 1] = f[i][j];
        for (int i = 2 * H - 2; i > H - 2; i--)
            for (int j = W - 2; j >= 0; j--)
                dat[i][j] = min(dat[i][2 * j + 1], dat[i][2 * j + 2]);
        for (int i = H - 2; i >= 0; i--)
            for (int j = 0; j < 2 * W - 1; j++)
                dat[i][j] = min(dat[2 * i + 1][j], dat[2 * i + 2][j]);
    }
    int minimum(int li, int lj, int ri, int rj) {
        return minimum_h(li, lj, ri, rj, 0, H, 0);
    }
    int minimum_h(int li, int lj, int ri, int rj, int si, int ti, int k) {
        if (ri <= si || ti <= li) return inf;
        if (li <= si && ti <= ri) return minimum_w(lj, rj, 0, W, k, 0);
        const int mi = (si + ti) / 2;
        return min(minimum_h(li, lj, ri, rj, si, mi, 2 * k + 1),
                   minimum_h(li, lj, ri, rj, mi, ti, 2 * k + 2));
    }
    int minimum_w(int lj, int rj, int sj, int tj, int i, int k) {
        if (rj <= sj || tj <= lj) return inf;
        if (lj <= sj && tj <= rj) return dat[i][k];
        const int mj = (sj + tj) / 2;
        return min(minimum_w(lj, rj, sj, mj, i, 2 * k + 1),
                   minimum_w(lj, rj, mj, tj, i, 2 * k + 2));
    }
};