/*
セグメント木(RMQ)
計算量(構築) O(N)
計算量(クエリ) O(log(N))
区間内の最小値を求める
k番目の値を更新する
*/

#include <bits/stdc++.h>
using namespace std;

// BEGIN
struct SegmentTree {
    int N;
    vector<int> node;
    const int INF = INT_MAX;

    SegmentTree(){}
    SegmentTree(int n_){
        init(n_);
    }

    void init(int siz){
        N = 1;
        while (N < siz) N *= 2;  // 最下段の要素数を2のべき乗にする
        node.resize(2*N-1, INF);
    }

    void build(vector<int> &dat){
        int siz = dat.size();
        for(int i=0; i<siz; i++){
            node[i+N-1] = dat[i];
        }
        for(int i=N-2; i>=0; i--){  // 最下段に値を入れたあと下から順に更新
            node[i] = min(node[2*i+1], node[2*i+2]);
        }
    }

    void update(int k, int a) {
        k += N - 1; // 最下段最左の節点の番号
        node[k] = a;
        while (k > 0) { //登りながら上の要素を更新
            k = (k-1)/2;
            node[k] = min(node[k*2+1], node[k*2+2]);
        }
    }
    /*
    [a,b)の最小値を求める
    外からはgetMin(a,b)で呼ぶ
    kは節点の番号、l,rはそのk番目の節点の区間を表す
    */
    int getMin(int a, int b) {return getMin(a, b, 0, 0, N);}
    int getMin(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)
            return INF;  //[a,b)と[l,r)に共通区間がないならINF
        if (a <= l && r <= b)
            return node[k];  //[a,b)が[l,r)を完全に含むならその節点kの値
        else {
            int vl = getMin(a, b, k*2+1, l, (l+r)/2);
            int vr = getMin(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};
// END

// varified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
int main() {
    int n, q;
    cin >> n >> q;
    SegmentTree rmq;
    rmq.init(n);
    for(int i=0;i<q;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a) cout << rmq.getMin(b, c+1) << endl;
        else rmq.update(b, c);
    }
    return 0;
}
