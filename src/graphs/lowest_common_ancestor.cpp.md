---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segmenttree.cpp
    title: src/data_structures/segmenttree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667.test.cpp
    title: test/aoj/2667.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graphs/lowest_common_ancestor.cpp\"\n#include <vector>\n\
    #line 2 \"src/data_structures/segmenttree.cpp\"\n#include <functional>\n\ntemplate\
    \ <typename Monoid>\nstruct SegmentTree{\nprivate:\n    using F = std::function<Monoid(Monoid,\
    \ Monoid)>;\n    int N;\n    std::vector<Monoid> node;\n    F f;\n    Monoid e;\
    \  // identity element\n\npublic:\n    SegmentTree(){}\n    SegmentTree(F f, Monoid\
    \ e):f(f), e(e){}\n    void init(int sz){\n        N = 1;\n        while(N < sz)\
    \ N <<= 1;\n        node.assign(2*N-1, e);\n    }\n    void build(std::vector<Monoid>&\
    \ v){\n        int sz = int(v.size());\n        init(sz);\n        for(int i=0;\
    \ i<sz; i++){\n            node[i+N-1] = v[i];\n        }\n        for(int i=N-2;\
    \ i>=0; i--){\n            node[i] = f(node[i*2+1], node[i*2+2]);\n        }\n\
    \    }\n    void update(int k, Monoid x){\n        k += N-1;\n        node[k]\
    \ = x;\n        while(k > 0){\n            k = (k-1)/2;\n            node[k] =\
    \ f(node[2*k+1], node[2*k+2]);\n        }\n    }\n    // [a,b)\n    Monoid query(int\
    \ a, int b){return query(a, b, 0, 0, N);}\n    Monoid query(int a, int b, int\
    \ k, int l, int r){\n        if(b <= l || r <= a) return e;\n        if(a <= l\
    \ && r <= b) return node[k];\n        Monoid vl, vr;\n        vl = query(a, b,\
    \ 2*k+1, l, (l+r)/2);\n        vr = query(a, b, 2*k+2, (l+r)/2, r);\n        return\
    \ f(vl, vr);\n    }\n};\n#line 3 \"src/graphs/lowest_common_ancestor.cpp\"\n\n\
    struct LCA {\n    using P = std::pair<int,int>;\n    using CostType = int;\n \
    \   const int INF = 1 << 30;\n    struct edge {\n        int from, to, rev;\n\
    \        CostType cost;\n        edge(int from, int to, int rev, CostType cost)\
    \ : from(from), to(to), rev(rev), cost(cost){}\n    };\n    int V = 0;\n    int\
    \ root = 0;\n    std::vector<std::vector<edge> > graph;\n    std::vector<int>\
    \ depth, vs, ds, us;  // ds[v]:go down to v, us[v]:go up from v\n\nprivate:\n\
    \    SegmentTree<P> rmq = SegmentTree<P>([](P a, P b){return min(a,b);},P(INF,-1));\n\
    \    SegmentTree<CostType> rsq = SegmentTree<CostType>([](CostType a, CostType\
    \ b){return a+b;}, 0);\n\n    void dfs(int v, int p, int d, int &idx){\n     \
    \   vs[idx] = v;\n        depth[v] = d;\n        ds[v] = idx++;\n        for(auto&\
    \ e : graph[v]){\n            if(e.to == p) continue;\n            dfs(e.to, v,\
    \ d+1, idx);\n            vs[idx] = v;\n            idx++;\n        }\n      \
    \  us[v] = idx;\n    }\n\npublic:\n    LCA() = default;\n    LCA(int V, int root\
    \ = 0) : V(V), graph(V), depth(V), vs(V*2-1), ds(V), us(V), root(root){}\n   \
    \ void init(int n, int r = 0){\n        V = n;\n        graph.resize(V);\n   \
    \     depth.resize(V);\n        vs.resize(V*2-1);\n        ds.resize(V);\n   \
    \     us.resize(V);\n        root = r;\n    }\n    void add_edge(int from, int\
    \ to, CostType cost = 1){\n        graph[from].emplace_back(edge(from,to,int(graph[to].size()),cost));\n\
    \        graph[to].emplace_back(edge(to,from,int(graph[from].size())-1,cost));\n\
    \    }\n    void build(){\n        int idx = 0;\n        dfs(root, -1, 0, idx);\n\
    \        std::vector<P> depv(idx);\n        for(int i=0;i<idx;i++){\n        \
    \    depv[i] = P(depth[vs[i]], vs[i]);\n        }\n        rmq.build(depv);\n\
    \        std::vector<CostType> cstv(idx, 0);\n        for(int i=0;i<V;i++){\n\
    \            for(auto& e : graph[i]){\n                if(depth[e.from] < depth[e.to]){\n\
    \                    cstv[ds[e.to]] = e.cost;\n                    cstv[us[e.to]]\
    \ = -e.cost;\n                }\n            }\n        }\n        rsq.build(cstv);\n\
    \    }\n    int query(int u, int v){\n        return rmq.query(std::min(ds[u],ds[v]),\
    \ std::max(ds[u],ds[v])+1).second;\n    }\n    CostType dist(int u){\n       \
    \ return rsq.query(ds[root], ds[u]+1);\n    }\n    CostType dist(int u, int v){\n\
    \        int w = query(u, v);\n        return dist(u) + dist(v) - 2*dist(w);\n\
    \    }\n    void update(int v, CostType cost){\n        rsq.update(ds[v], cost);\n\
    \        rsq.update(us[v], -cost);\n    }\n};\n"
  code: "#include <vector>\n#include \"../data_structures/segmenttree.cpp\"\n\nstruct\
    \ LCA {\n    using P = std::pair<int,int>;\n    using CostType = int;\n    const\
    \ int INF = 1 << 30;\n    struct edge {\n        int from, to, rev;\n        CostType\
    \ cost;\n        edge(int from, int to, int rev, CostType cost) : from(from),\
    \ to(to), rev(rev), cost(cost){}\n    };\n    int V = 0;\n    int root = 0;\n\
    \    std::vector<std::vector<edge> > graph;\n    std::vector<int> depth, vs, ds,\
    \ us;  // ds[v]:go down to v, us[v]:go up from v\n\nprivate:\n    SegmentTree<P>\
    \ rmq = SegmentTree<P>([](P a, P b){return min(a,b);},P(INF,-1));\n    SegmentTree<CostType>\
    \ rsq = SegmentTree<CostType>([](CostType a, CostType b){return a+b;}, 0);\n\n\
    \    void dfs(int v, int p, int d, int &idx){\n        vs[idx] = v;\n        depth[v]\
    \ = d;\n        ds[v] = idx++;\n        for(auto& e : graph[v]){\n           \
    \ if(e.to == p) continue;\n            dfs(e.to, v, d+1, idx);\n            vs[idx]\
    \ = v;\n            idx++;\n        }\n        us[v] = idx;\n    }\n\npublic:\n\
    \    LCA() = default;\n    LCA(int V, int root = 0) : V(V), graph(V), depth(V),\
    \ vs(V*2-1), ds(V), us(V), root(root){}\n    void init(int n, int r = 0){\n  \
    \      V = n;\n        graph.resize(V);\n        depth.resize(V);\n        vs.resize(V*2-1);\n\
    \        ds.resize(V);\n        us.resize(V);\n        root = r;\n    }\n    void\
    \ add_edge(int from, int to, CostType cost = 1){\n        graph[from].emplace_back(edge(from,to,int(graph[to].size()),cost));\n\
    \        graph[to].emplace_back(edge(to,from,int(graph[from].size())-1,cost));\n\
    \    }\n    void build(){\n        int idx = 0;\n        dfs(root, -1, 0, idx);\n\
    \        std::vector<P> depv(idx);\n        for(int i=0;i<idx;i++){\n        \
    \    depv[i] = P(depth[vs[i]], vs[i]);\n        }\n        rmq.build(depv);\n\
    \        std::vector<CostType> cstv(idx, 0);\n        for(int i=0;i<V;i++){\n\
    \            for(auto& e : graph[i]){\n                if(depth[e.from] < depth[e.to]){\n\
    \                    cstv[ds[e.to]] = e.cost;\n                    cstv[us[e.to]]\
    \ = -e.cost;\n                }\n            }\n        }\n        rsq.build(cstv);\n\
    \    }\n    int query(int u, int v){\n        return rmq.query(std::min(ds[u],ds[v]),\
    \ std::max(ds[u],ds[v])+1).second;\n    }\n    CostType dist(int u){\n       \
    \ return rsq.query(ds[root], ds[u]+1);\n    }\n    CostType dist(int u, int v){\n\
    \        int w = query(u, v);\n        return dist(u) + dist(v) - 2*dist(w);\n\
    \    }\n    void update(int v, CostType cost){\n        rsq.update(ds[v], cost);\n\
    \        rsq.update(us[v], -cost);\n    }\n};"
  dependsOn:
  - src/data_structures/segmenttree.cpp
  isVerificationFile: false
  path: src/graphs/lowest_common_ancestor.cpp
  requiredBy: []
  timestamp: '2020-04-17 13:36:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_C.test.cpp
  - test/aoj/2667.test.cpp
documentation_of: src/graphs/lowest_common_ancestor.cpp
layout: document
redirect_from:
- /library/src/graphs/lowest_common_ancestor.cpp
- /library/src/graphs/lowest_common_ancestor.cpp.html
title: src/graphs/lowest_common_ancestor.cpp
---
