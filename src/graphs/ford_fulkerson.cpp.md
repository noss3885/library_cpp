---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1163_fordfulkerson.test.cpp
    title: test/aoj/1163_fordfulkerson.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A_fordfulkerson.test.cpp
    title: test/aoj/GRL_6_A_fordfulkerson.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graphs/ford_fulkerson.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <limits>\n\ntemplate <typename T>\nstruct FordFulkerson{\n\
    \    // \u884C\u5148\u3001\u5BB9\u91CF\u3001\u9006\u8FBA\u306E\u756A\u53F7\n \
    \   struct edge{\n        int to, rev;\n        T cap;\n        edge() = default;\n\
    \        edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}\n    };\n\
    \    std::vector<std::vector<edge> > G;\n    std::vector<bool> used;\n\n    FordFulkerson()\
    \ = default;\n    FordFulkerson(int n) : G(n), used(n) {}\n    \n    void init(int\
    \ n){\n        G.clear();\n        G.resize(n);\n        used.resize(n);\n   \
    \ }\n\n    void add_edge(int from, int to, T cap, bool directed = true){\n   \
    \     G[from].emplace_back(to, cap, int(G[to].size()));\n        G[to].emplace_back(from,\
    \ directed?0:cap, int(G[from].size())-1);\n    }\n\n    // \u5897\u52A0\u8DEF\u306E\
    \u63A2\u7D22\n    T dfs(int v, int t, T f){\n        if(v == t) return f;\n  \
    \      used[v] = true;\n        for(auto &e : G[v]){\n            if(!used[e.to]\
    \ && e.cap > 0){\n                T d = dfs(e.to, t, std::min(f, e.cap));\n  \
    \              if(d > 0){\n                    e.cap -= d;\n                 \
    \   G[e.to][e.rev].cap += d;\n                    return d;\n                }\n\
    \            }\n        }\n        return 0;\n    }\n\n    T max_flow(int s, int\
    \ t, T lim){\n        T flow = 0;\n        while(1){\n            std::fill(used.begin(),\
    \ used.end(), false);\n            T f = dfs(s, t, lim);\n            if(f==0)\
    \ break;\n            flow += f;\n            lim -= f;\n        }\n        return\
    \ flow;\n    }\n    T max_flow(int s, int t){return max_flow(s, t, std::numeric_limits<T>::max()/2);}\n\
    };\n"
  code: "#include <vector>\n#include <algorithm>\n#include <limits>\n\ntemplate <typename\
    \ T>\nstruct FordFulkerson{\n    // \u884C\u5148\u3001\u5BB9\u91CF\u3001\u9006\
    \u8FBA\u306E\u756A\u53F7\n    struct edge{\n        int to, rev;\n        T cap;\n\
    \        edge() = default;\n        edge(int to, T cap, int rev) : to(to), cap(cap),\
    \ rev(rev) {}\n    };\n    std::vector<std::vector<edge> > G;\n    std::vector<bool>\
    \ used;\n\n    FordFulkerson() = default;\n    FordFulkerson(int n) : G(n), used(n)\
    \ {}\n    \n    void init(int n){\n        G.clear();\n        G.resize(n);\n\
    \        used.resize(n);\n    }\n\n    void add_edge(int from, int to, T cap,\
    \ bool directed = true){\n        G[from].emplace_back(to, cap, int(G[to].size()));\n\
    \        G[to].emplace_back(from, directed?0:cap, int(G[from].size())-1);\n  \
    \  }\n\n    // \u5897\u52A0\u8DEF\u306E\u63A2\u7D22\n    T dfs(int v, int t, T\
    \ f){\n        if(v == t) return f;\n        used[v] = true;\n        for(auto\
    \ &e : G[v]){\n            if(!used[e.to] && e.cap > 0){\n                T d\
    \ = dfs(e.to, t, std::min(f, e.cap));\n                if(d > 0){\n          \
    \          e.cap -= d;\n                    G[e.to][e.rev].cap += d;\n       \
    \             return d;\n                }\n            }\n        }\n       \
    \ return 0;\n    }\n\n    T max_flow(int s, int t, T lim){\n        T flow = 0;\n\
    \        while(1){\n            std::fill(used.begin(), used.end(), false);\n\
    \            T f = dfs(s, t, lim);\n            if(f==0) break;\n            flow\
    \ += f;\n            lim -= f;\n        }\n        return flow;\n    }\n    T\
    \ max_flow(int s, int t){return max_flow(s, t, std::numeric_limits<T>::max()/2);}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/ford_fulkerson.cpp
  requiredBy: []
  timestamp: '2020-04-17 19:22:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_A_fordfulkerson.test.cpp
  - test/aoj/1163_fordfulkerson.test.cpp
documentation_of: src/graphs/ford_fulkerson.cpp
layout: document
redirect_from:
- /library/src/graphs/ford_fulkerson.cpp
- /library/src/graphs/ford_fulkerson.cpp.html
title: src/graphs/ford_fulkerson.cpp
---
