/*
セグメント木(RMQ)
計算量(構築) O(N)
計算量(クエリ) O(log(N))
区間内の最小値を求める
k番目の値を更新する
*/

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

struct SegmentTree {
    int N;
    vector<int> node;
    static const int INF = INT_MAX;

    SegmentTree(int n_){
        init(n_);
    }

    void init(int n_) {
        N = 1;
        while (N < n_) N *= 2;  // 最下段の要素数を2のべき乗にする
        node.resize(2*N-1, INF);
    }

    void init(vector<int> &dat){
        int siz = dat.size();
        N = 1;
        while (N < siz) N *= 2;
        node.resize(2*N-1, INF);
        // 最下段に値を入れたあと下から順に更新
        for(int i=0; i<siz; i++){
            node[i+N-1] = dat[i];
        }
        for(int i=N-2; i>=0; i++){
            node[i] = min(node[2*i+1], node[2*i+2]);
        }
    }

    void update(int k, int a) {
        k += N - 1; //葉の節点の番号
        node[k] = a;
        while (k > 0) { //登りながら上の要素を更新
            k = (k-1)/2;
            node[k] = min(node[k*2+1], node[k*2+2]);
        }
    }
    /*
    [a,b)の最小値を求める
    外からはquery(a,b,0,0,N)で呼ぶ
    kは節点の番号、l,rはそのk番目の節点の区間を表す
    */
    int query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)
            return INF;  //[a,b)と[l,r)に共通区間がないならINF
        if (a <= l && r <= b)
            return node[k];  //[a,b)が[l,r)を完全に含むならその節点kの値
        else {
            int vl = query(a, b, k*2+1, l, (l+r)/2);
            int vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};