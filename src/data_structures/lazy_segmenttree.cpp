#include <bits/stdc++.h>
using namespace std;

// BEGIN

template <typename Monoid, typename OperatorMonoid>
struct LazySegmentTree{
private:
    using F = function<Monoid(Monoid, Monoid)>;  // 要素と要素を結合させる関数
    using G = function<Monoid(Monoid, OperatorMonoid)>;  // 要素に作用素を作用させる関数
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;  // 作用素と作用素を結合させる関数
    using P = function<OperatorMonoid(OperatorMonoid, int)>;  // 作用素を作用させる区間の長さによって変化させる関数
    int N;
    vector<Monoid> node;
    vector<OperatorMonoid> lazy;
    F f;
    G g;
    H h;
    P p;
    Monoid e;  // identity element
    OperatorMonoid oe;  // identity element

public:
    LazySegmentTree(){}
    LazySegmentTree(F f, G g, H h, Monoid e, OperatorMonoid oe, P p=[](OperatorMonoid a, int b){return a;}):f(f), g(g), h(h), e(e), oe(oe), p(p){}
    void init(int sz){
        N = 1;
        while(N < sz) N <<= 1;
        node.assign(2*N-1, e);
        lazy.assign(2*N-1, oe);
    }
    void build(vector<Monoid>& v){
        int sz = int(v.size());
        init(sz);
        for(int i=0; i<sz; i++){
            node[i+N-1] = v[i];
        }
        for(int i=N-2; i>=0; i--){
            node[i] = f(node[i*2+1], node[i*2+2]);
        }
    }
    void eval(int k, int len){
        if(lazy[k] != oe){
            node[k] = g(node[k], p(lazy[k], len));
            if(k < N-1){
                lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
                lazy[2*k+2] = h(lazy[2*k+2], lazy[k]);
            }
            lazy[k] = oe;
        }
    }
    Monoid update(int a, int b, OperatorMonoid x){return update(a, b, x, 0, 0, N);}
    Monoid update(int a, int b, OperatorMonoid x, int k, int l, int r){
        eval(k, r-l);
        if(b <= l || r <= a) return node[k];
        if(a <= l && r <= b){
            lazy[k] = h(lazy[k], x);
            return g(node[k], p(lazy[k], r-l));
        }
        return node[k] = f(update(a,b,x,2*k+1,l,(l+r)/2), update(a,b,x,k*2+2,(l+r)/2,r));
    }
    // [a,b)
    Monoid query(int a, int b){return query(a, b, 0, 0, N);}
    Monoid query(int a, int b, int k, int l, int r){
        eval(k, r-l);
        if(b <= l || r <= a) return e;
        if(a <= l && r <= b) return node[k];
        Monoid vl, vr;
        vl = query(a, b, 2*k+1, l, (l+r)/2);
        vr = query(a, b, 2*k+2, (l+r)/2, r);
        return f(vl, vr);
    }
};

// END

// TEST
typedef long long ll;

// RMQ & RUQ
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
void DSL_2_F(){
    int n, q;
    cin >> n >> q;
    auto f = [=](int a, int b){return min(a,b);};
    auto g = [=](int a, int b){return (b>=0 ? b : a);};
    LazySegmentTree<int, int> seg(f,g,g,INT_MAX,-1);
    seg.init(n);
    for(int i=0;i<q;i++){
        int c, s, t;
        cin >> c >> s >> t;
        if(c==0){
            int x;
            cin >> x;
            seg.update(s, t+1, x);
        }
        else{
            cout << seg.query(s,t+1) << endl;
        }
    }
}

// RSQ & RAQ
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
void DSL_2_G(){
    int n, q;
    cin >> n >> q;
    auto f = [=](ll a, ll b){return a+b;};
    auto p = [=](ll a, int b){return a*b;};
    LazySegmentTree<ll, ll> seg(f,f,f,0,0,p);
    seg.init(n);
    for(int i=0;i<q;i++){
        int c, s, t;
        cin >> c >> s >> t;
        if(c==0){
            ll x;
            cin >> x;
            seg.update(s-1, t, x);
        }
        else{
            cout << seg.query(s-1,t) << endl;
        }
    }
}

// RMQ & RAQ
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
void DSL_2_H(){
    int n, q;
    cin >> n >> q;
    auto f = [=](ll a, ll b){return min(a,b);};
    auto g = [=](ll a, ll b){return a+b;};
    LazySegmentTree<ll, ll> seg(f,g,g,INT_MAX,0);
    vector<ll> v;
    v.assign(n, 0);
    seg.build(v);
    for(int i=0;i<q;i++){
        int c, s, t;
        cin >> c >> s >> t;
        if(c==0){
            ll x;
            cin >> x;
            seg.update(s, t+1, x);
        }
        else{
            cout << seg.query(s,t+1) << endl;
        }
    }
}

// RSQ & RUQ
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
void DSL_2_I(){
    int n, q;
    ll INF = INT_MAX;
    cin >> n >> q;
    auto f = [=](ll a, ll b){return a+b;};
    auto g = [=](ll a, ll b){return (b!=INF?b:a);};
    auto p = [=](ll a, int b){return a*b;};
    LazySegmentTree<ll, ll> seg(f,g,g,0,INF,p);
    seg.init(n);
    for(int i=0;i<q;i++){
        int c, s, t;
        cin >> c >> s >> t;
        if(c==0){
            ll x;
            cin >> x;
            seg.update(s, t+1, x);
        }
        else{
            cout << seg.query(s,t+1) << endl;
        }
    }
}