---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graphs/ford_fulkerson.cpp
    title: src/graphs/ford_fulkerson.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163
  bundledCode: "#line 1 \"test/aoj/1163_fordfulkerson.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163\"\n#include\
    \ <iostream>\n#include <numeric>\n#line 1 \"src/graphs/ford_fulkerson.cpp\"\n\
    #include <algorithm>\n#include <limits>\n#include <vector>\n\ntemplate <typename\
    \ T>\nstruct FordFulkerson {\n    // \u884C\u5148\u3001\u5BB9\u91CF\u3001\u9006\
    \u8FBA\u306E\u756A\u53F7\n    struct edge {\n        int to, rev;\n        T cap;\n\
    \        edge() = default;\n        edge(int to, T cap, int rev) : to(to), cap(cap),\
    \ rev(rev) {}\n    };\n    std::vector<std::vector<edge> > G;\n    std::vector<bool>\
    \ used;\n\n    FordFulkerson() = default;\n    FordFulkerson(int n) : G(n), used(n)\
    \ {}\n\n    void init(int n) {\n        G.clear();\n        G.resize(n);\n   \
    \     used.resize(n);\n    }\n\n    void add_edge(int from, int to, T cap, bool\
    \ directed = true) {\n        G[from].emplace_back(to, cap, int(G[to].size()));\n\
    \        G[to].emplace_back(from, directed ? 0 : cap, int(G[from].size()) - 1);\n\
    \    }\n\n    // \u5897\u52A0\u8DEF\u306E\u63A2\u7D22\n    T dfs(int v, int t,\
    \ T f) {\n        if (v == t) return f;\n        used[v] = true;\n        for\
    \ (auto& e : G[v]) {\n            if (!used[e.to] && e.cap > 0) {\n          \
    \      T d = dfs(e.to, t, std::min(f, e.cap));\n                if (d > 0) {\n\
    \                    e.cap -= d;\n                    G[e.to][e.rev].cap += d;\n\
    \                    return d;\n                }\n            }\n        }\n\
    \        return 0;\n    }\n\n    T max_flow(int s, int t, T lim) {\n        T\
    \ flow = 0;\n        while (1) {\n            std::fill(used.begin(), used.end(),\
    \ false);\n            T f = dfs(s, t, lim);\n            if (f == 0) break;\n\
    \            flow += f;\n            lim -= f;\n        }\n        return flow;\n\
    \    }\n    T max_flow(int s, int t) { return max_flow(s, t, std::numeric_limits<T>::max()\
    \ / 2); }\n};\n#line 5 \"test/aoj/1163_fordfulkerson.test.cpp\"\n\nint main()\
    \ {\n    int n, m;\n    while (std::cin >> m >> n, m) {\n        FordFulkerson<int>\
    \ G(m + n + 2);\n        std::vector<int> a(m), b(n);\n        for (int i = 0;\
    \ i < m; i++) std::cin >> a[i];\n        for (int i = 0; i < n; i++) std::cin\
    \ >> b[i];\n        for (int i = 0; i < m; i++) {\n            for (int j = 0;\
    \ j < n; j++) {\n                if (std::gcd(a[i], b[j]) > 1) {\n           \
    \         G.add_edge(i, j + m, 1);\n                }\n            }\n       \
    \ }\n        int S = n + m, T = n + m + 1;\n        for (int i = 0; i < m; i++)\
    \ {\n            G.add_edge(S, i, 1);\n        }\n        for (int i = 0; i <\
    \ n; i++) {\n            G.add_edge(i + m, T, 1);\n        }\n        std::cout\
    \ << G.max_flow(S, T) << std::endl;\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163\"\
    \n#include <iostream>\n#include <numeric>\n#include \"../../src/graphs/ford_fulkerson.cpp\"\
    \n\nint main() {\n    int n, m;\n    while (std::cin >> m >> n, m) {\n       \
    \ FordFulkerson<int> G(m + n + 2);\n        std::vector<int> a(m), b(n);\n   \
    \     for (int i = 0; i < m; i++) std::cin >> a[i];\n        for (int i = 0; i\
    \ < n; i++) std::cin >> b[i];\n        for (int i = 0; i < m; i++) {\n       \
    \     for (int j = 0; j < n; j++) {\n                if (std::gcd(a[i], b[j])\
    \ > 1) {\n                    G.add_edge(i, j + m, 1);\n                }\n  \
    \          }\n        }\n        int S = n + m, T = n + m + 1;\n        for (int\
    \ i = 0; i < m; i++) {\n            G.add_edge(S, i, 1);\n        }\n        for\
    \ (int i = 0; i < n; i++) {\n            G.add_edge(i + m, T, 1);\n        }\n\
    \        std::cout << G.max_flow(S, T) << std::endl;\n    }\n    return 0;\n}"
  dependsOn:
  - src/graphs/ford_fulkerson.cpp
  isVerificationFile: true
  path: test/aoj/1163_fordfulkerson.test.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/1163_fordfulkerson.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/1163_fordfulkerson.test.cpp
- /verify/test/aoj/1163_fordfulkerson.test.cpp.html
title: test/aoj/1163_fordfulkerson.test.cpp
---
