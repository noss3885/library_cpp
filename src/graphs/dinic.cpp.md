---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graphs/dinic.cpp\"\n#include <algorithm>\n#include <limits>\n\
    #include <queue>\n#include <vector>\n\ntemplate <typename T>\nstruct Dinic {\n\
    \    // \u884C\u5148\u3001\u5BB9\u91CF\u3001\u9006\u8FBA\u306E\u756A\u53F7\n \
    \   struct edge {\n        int to, rev;\n        T cap;\n        edge() = default;\n\
    \        edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}\n    };\n\
    \    std::vector<std::vector<edge> > G;\n    std::vector<int> level, iter;\n\n\
    \    Dinic() = default;\n    Dinic(int n) : G(n), level(n), iter(n) {}\n\n   \
    \ T inf = std::numeric_limits<T>::max() / 2;\n\n    void init(int n) {\n     \
    \   G.clear();\n        G.resize(n);\n        level.resize(n);\n        iter.resize(n);\n\
    \    }\n\n    void add_edge(int from, int to, T cap, bool directed = true) {\n\
    \        G[from].emplace_back(to, cap, int(G[to].size()));\n        G[to].emplace_back(from,\
    \ directed ? 0 : cap, int(G[from].size()) - 1);\n    }\n\n    void bfs(int s)\
    \ {\n        std::fill(level.begin(), level.end(), -1);\n        std::queue<int>\
    \ que;\n        level[s] = 0;\n        que.push(s);\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            for\
    \ (edge& e : G[v]) {\n                if (e.cap > 0 && level[e.to] < 0) {\n  \
    \                  level[e.to] = level[v] + 1;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n    }\n\n    // \u5897\u52A0\u8DEF\
    \u306E\u63A2\u7D22\n    T dfs(int v, int t, T f) {\n        if (v == t) return\
    \ f;\n        for (int& i = iter[v]; i < int(G[v].size()); i++) {\n          \
    \  edge& e = G[v][i];\n            if (e.cap > 0 && level[v] < level[e.to]) {\n\
    \                T d = dfs(e.to, t, std::min(f, e.cap));\n                if (d\
    \ > 0) {\n                    e.cap -= d;\n                    G[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n\n    T max_flow(int s, int t, T lim) {\n \
    \       T flow = 0;\n        while (1) {\n            bfs(s);\n            if\
    \ (level[t] < 0) break;\n            std::fill(iter.begin(), iter.end(), 0);\n\
    \            T f;\n            while ((f = dfs(s, t, lim)) > 0) {\n          \
    \      flow += f;\n                lim -= f;\n            }\n        }\n     \
    \   return flow;\n    }\n    T max_flow(int s, int t) { return max_flow(s, t,\
    \ inf); }\n};\n"
  code: "#include <algorithm>\n#include <limits>\n#include <queue>\n#include <vector>\n\
    \ntemplate <typename T>\nstruct Dinic {\n    // \u884C\u5148\u3001\u5BB9\u91CF\
    \u3001\u9006\u8FBA\u306E\u756A\u53F7\n    struct edge {\n        int to, rev;\n\
    \        T cap;\n        edge() = default;\n        edge(int to, T cap, int rev)\
    \ : to(to), cap(cap), rev(rev) {}\n    };\n    std::vector<std::vector<edge> >\
    \ G;\n    std::vector<int> level, iter;\n\n    Dinic() = default;\n    Dinic(int\
    \ n) : G(n), level(n), iter(n) {}\n\n    T inf = std::numeric_limits<T>::max()\
    \ / 2;\n\n    void init(int n) {\n        G.clear();\n        G.resize(n);\n \
    \       level.resize(n);\n        iter.resize(n);\n    }\n\n    void add_edge(int\
    \ from, int to, T cap, bool directed = true) {\n        G[from].emplace_back(to,\
    \ cap, int(G[to].size()));\n        G[to].emplace_back(from, directed ? 0 : cap,\
    \ int(G[from].size()) - 1);\n    }\n\n    void bfs(int s) {\n        std::fill(level.begin(),\
    \ level.end(), -1);\n        std::queue<int> que;\n        level[s] = 0;\n   \
    \     que.push(s);\n        while (!que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            for (edge& e : G[v]) {\n                if\
    \ (e.cap > 0 && level[e.to] < 0) {\n                    level[e.to] = level[v]\
    \ + 1;\n                    que.push(e.to);\n                }\n            }\n\
    \        }\n    }\n\n    // \u5897\u52A0\u8DEF\u306E\u63A2\u7D22\n    T dfs(int\
    \ v, int t, T f) {\n        if (v == t) return f;\n        for (int& i = iter[v];\
    \ i < int(G[v].size()); i++) {\n            edge& e = G[v][i];\n            if\
    \ (e.cap > 0 && level[v] < level[e.to]) {\n                T d = dfs(e.to, t,\
    \ std::min(f, e.cap));\n                if (d > 0) {\n                    e.cap\
    \ -= d;\n                    G[e.to][e.rev].cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\n\
    \    T max_flow(int s, int t, T lim) {\n        T flow = 0;\n        while (1)\
    \ {\n            bfs(s);\n            if (level[t] < 0) break;\n            std::fill(iter.begin(),\
    \ iter.end(), 0);\n            T f;\n            while ((f = dfs(s, t, lim)) >\
    \ 0) {\n                flow += f;\n                lim -= f;\n            }\n\
    \        }\n        return flow;\n    }\n    T max_flow(int s, int t) { return\
    \ max_flow(s, t, inf); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/dinic.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/dinic.cpp
layout: document
redirect_from:
- /library/src/graphs/dinic.cpp
- /library/src/graphs/dinic.cpp.html
title: src/graphs/dinic.cpp
---
