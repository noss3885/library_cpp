#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
constexpr int IINF = INT_MAX;
constexpr int MAX_N = int(1e5) + 5;

template <typename Monoid>
struct SegmentTree{
private:
    using F = function<Monoid(Monoid, Monoid)>;
    int N;
    vector<Monoid> node;
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


struct edge
{
    int from, to, d;
};


int n, q;
vector<vector<edge> > g;
vector<int> depth, vs, id;

auto funcmin = [=](P a, P b){return min(a,b);};
SegmentTree<P> rmq(funcmin,{IINF, -1});

void dfs(int v, int p, int d, int &k){
    id[v] = k;
    vs[k] = v;
    depth[k] = d;
    k++;
    for(auto e : g[v]){
        if(e.to == p) continue;
        dfs(e.to, v, d+e.d, k);
        vs[k] = v;
        depth[k] = d;
        k++;
    }
}

void init(){
    int k=0;
    depth.resize(n*2-1);
    vs.resize(2*n-1);
    id.resize(n);
    dfs(0,-1,0,k);
    vector<P> tmp;
    for(int i=0;i<k;i++){
        tmp.push_back({depth[i], vs[i]});
    }
    rmq.build(tmp);
}

int LCA(int u, int v){
    return rmq.query(min(id[u], id[v]), max(id[u], id[v])+1).second;
}

// END

// varify
// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C

int main() {
    cin >> n;
    g.resize(n);
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        for(int j=0;j<m;j++){
            int v;
            cin >> v;
            g[i].push_back({i,v,1});
        }
    }
    init();
    cin >> q;
    for(int i=0;i<q;i++){
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }
    return 0;
}
