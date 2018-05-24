/*
セグメント木(RMQ)
計算量(構築) O(N)
計算量(クエリ) O(log(N))
区間内の最小値を求める
k番目の値を更新する
*/

#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT32_MAX;

struct SegmentTree {
    static const int MAX_N = 1 << 17;
    int N, dat[2 * MAX_N - 1];

    void init(int n_) {
        N = 1;
        while (N < n_)
            N *= 2; //要素数を2のべき乗にする
        for (int i = 0; i < 2 * N - 1; i++)
            dat[i] = INF;
    }

    void update(int k, int a) {
        k += N - 1; //葉の節点の番号
        dat[k] = a;
        while (k > 0) { //登りながら上の要素を更新
            k = (k - 1) / 2;
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    /*
    [a,b)の最小値を求める
    外からはquery(a,b,0,0,N)で呼ぶ
    kは節点の番号、l,rはそのk番目の節点の区間を表す
    */
    int query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)
            return INF; //[a,b)と[l,r)に共通区間がないならINF
        if (a <= l && r <= b)
            return dat[k]; //[a,b)が[l,r)を完全に含むならその節点kの値
        else {
            int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
};