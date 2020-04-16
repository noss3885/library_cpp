#include <vector>
#include <functional>

template <typename Monoid, typename OperatorMonoid>
struct LazySegmentTree{
private:
    using F = std::function<Monoid(Monoid, Monoid)>;  // 要素と要素を結合させる関数
    using G = std::function<Monoid(Monoid, OperatorMonoid)>;  // 要素に作用素を作用させる関数
    using H = std::function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;  // 作用素と作用素を結合させる関数
    using P = std::function<OperatorMonoid(OperatorMonoid, int)>;  // 作用素を作用させる区間の長さによって変化させる関数
    int N;
    std::vector<Monoid> node;
    std::vector<OperatorMonoid> lazy;
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
    void build(std::vector<Monoid>& v){
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