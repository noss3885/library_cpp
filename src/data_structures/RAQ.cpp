

template <typename Monoid>
struct LazySegmentTree{
private:
    int N;
    vector<Monoid> node, lazy;

public:
    LazySegmentTree(int sz = 0){
        init(sz);
    }
    void init(int sz){
        N = 1;
        while(N < sz) N <<= 1;
        node.resize(2*N-1,0);
        lazy.resize(2*N-1,0);

    }
    void build(vector<Monoid>& v){
        int sz = int(v.size());
        init(sz);
        for(int i=0; i<sz; i++){
            node[i+N-1] = v[i];
        }
        for(int i=N-2; i>=0; i--){
            node[i] = node[i*2+1] + node[i*2+2];
        }
    }
    // node[k]
    void eval(int k){
        if(lazy[k] != 0){
            node[k] += lazy[k];
            if(k < N-1){ // 最下段でないとき
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }
    // [a,b)
    void add(int a, int b, Monoid x){add(a, b, x, 0, 0, N);}
    void add(int a, int b, Monoid x, int k, int l, int r){
        if(b <= l || r <= a) return;
        eval(k);
        if(a <= l && r <= b){
            lazy[k] += x * (r-l);
        }
        else{
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }
    // [a,b)
    Monoid getSum(int a, int b){return getSum(a, b, 0, 0, N);}
    Monoid getSum(int a, int b, int k, int l, int r){
        if(b <= l || r <= a) return 0;
        eval(k);
        if(a <= l && r <= b) return node[k];
        Monoid vl, vr;
        vl = getSum(a, b, 2*k+1, l, (l+r)/2);
        vr = getSum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};