#include <vector>
#include <functional>

template <typename Monoid>
struct SegmentTree{
private:
    using F = std::function<Monoid(Monoid, Monoid)>;
    int N;
    std::vector<Monoid> node;
    F f;
    Monoid e;  // identity element

public:
    SegmentTree(){}
    SegmentTree(F f, Monoid e):f(f), e(e){}
    void init(int sz){
        N = 1;
        while(N < sz) N <<= 1;
        node.assign(2*N-1, e);
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
    void update(int k, Monoid x){
        k += N-1;
        node[k] = x;
        while(k > 0){
            k = (k-1)/2;
            node[k] = f(node[2*k+1], node[2*k+2]);
        }
    }
    // [a,b)
    Monoid query(int a, int b){return query(a, b, 0, 0, N);}
    Monoid query(int a, int b, int k, int l, int r){
        if(b <= l || r <= a) return e;
        if(a <= l && r <= b) return node[k];
        Monoid vl, vr;
        vl = query(a, b, 2*k+1, l, (l+r)/2);
        vr = query(a, b, 2*k+2, (l+r)/2, r);
        return f(vl, vr);
    }
};