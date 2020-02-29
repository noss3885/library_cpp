#include <bits/stdc++.h>
using namespace std;

template <typename Monoid>
struct SegmentTree{
private:
    using F = function<Monoid(Monoid, Monoid)>;
    int N{};
    vector<Monoid> node;
    F f;
    Monoid e;  // identity element

public:
    SegmentTree() = default;
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

class LCA {
private:
    using P = std::pair<int,int>;
    using CostType = int;
    const int INF = 1 << 30;
    struct edge {
        int from, to, rev;
        CostType cost;
        edge(int from, int to, int rev, CostType cost) : from(from), to(to), rev(rev), cost(cost){}
    };
    int V = 0;
    int root = 0;
    std::vector<std::vector<edge> > graph;
    std::vector<int> depth, vs, ds, us;  // ds[v]:go down to v, us[v]:go up from v

    SegmentTree<P> rmq = SegmentTree<P>([](P a, P b){return min(a,b);},P(INF,-1));
    SegmentTree<CostType> rsq = SegmentTree<CostType>([](CostType a, CostType b){return a+b;}, 0);

    void dfs(int v, int p, int d, int &idx){
        vs[idx] = v;
        depth[v] = d;
        ds[v] = idx++;
        for(auto& e : graph[v]){
            if(e.to == p) continue;
            dfs(e.to, v, d+1, idx);
            vs[idx] = v;
            idx++;
        }
        us[v] = idx;
    }

public:
    LCA() = default;
    LCA(int V, int root = 0) : V(V), graph(V), depth(V), vs(V*2-1), ds(V), us(V), root(root){}
    void init(int n, int r = 0){
        V = n;
        graph.resize(V);
        depth.resize(V);
        vs.resize(V*2-1);
        ds.resize(V);
        us.resize(V);
        root = r;
    }
    void add_edge(int from, int to, CostType cost = 1){
        graph[from].emplace_back(edge(from,to,int(graph[to].size()),cost));
        graph[to].emplace_back(edge(to,from,int(graph[from].size())-1,cost));
    }
    void build(){
        int idx = 0;
        dfs(root, -1, 0, idx);
        std::vector<P> depv(idx);
        for(int i=0;i<idx;i++){
            depv[i] = P(depth[vs[i]], vs[i]);
        }
        rmq.build(depv);
        std::vector<CostType> cstv(idx, 0);
        for(int i=0;i<V;i++){
            for(auto& e : graph[i]){
                if(depth[e.from] < depth[e.to]){
                    cstv[ds[e.to]] = e.cost;
                    cstv[us[e.to]] = -e.cost;
                }
            }
        }
        rsq.build(cstv);
    }
    int query(int u, int v){
        return rmq.query(std::min(ds[u],ds[v]), std::max(ds[u],ds[v])+1).second;
    }
    CostType dist(int u){
        return rsq.query(ds[root], ds[u]+1);
    }
    CostType dist(int u, int v){
        int w = query(u, v);
        return dist(u) + dist(v) - 2*dist(w);
    }
    void update(int v, CostType cost){
        rsq.update(ds[v], cost);
        rsq.update(us[v], -cost);
    }
};

// END

// varify
// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C

int main() {
    int n, q;
    cin >> n;
    LCA lca(n);
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int c;
            cin >> c;
            lca.add_edge(i,c);
        }
    }
    lca.build();
    cin >> q;
    for(int i=0;i<q;i++){
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }
    return 0;
}