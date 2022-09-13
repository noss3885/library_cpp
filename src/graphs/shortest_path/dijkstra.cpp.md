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
  bundledCode: "#line 1 \"src/graphs/shortest_path/dijkstra.cpp\"\n/*\r\n\u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\u6CD5\r\n\u8A08\u7B97\u91CF O(Elog(V))\r\n\u6700\u77ED\
    \u7D4C\u8DEF\u3092\u6C42\u3081\u308B\r\n\u8CA0\u306E\u8FBA\u304C\u3042\u308B\u3068\
    \u304D\u306F\u4F7F\u3048\u306A\u3044\r\n*/\r\n\r\n#include <functional>\r\n#include\
    \ <queue>\r\n#include <utility>\r\n#include <vector>\r\n#include <climits>\r\n\
    \r\nusing namespace std;\r\ntypedef pair<int, int> P;  // first\u306F\u6700\u77ED\
    \u8DDD\u96E2,second\u306F\u9802\u70B9\u306E\u756A\u53F7\r\n\r\nconst int MAX_V\
    \ = int(1e5 + 5);\r\nconst int IINF = INT_MAX;\r\n\r\nstruct edge {\r\n    int\
    \ from, to, cost;\r\n    edge(int u, int v, int c) : from(u), to(v), cost(c){};\r\
    \n};\r\n\r\nvector<edge> G[MAX_V];\r\nint dmin[MAX_V];\r\n\r\nvoid add_edge(int\
    \ u, int v, int cost) {\r\n    G[u].push_back(edge(u, v, cost));\r\n    G[v].push_back(edge(v,\
    \ u, cost));\r\n}\r\n\r\nvoid dijkstra(int s) {\r\n    priority_queue<P, vector<P>,\
    \ greater<P> > que;  //\u5C0F\u3055\u3044\u3082\u306E\u304B\u3089\u53D6\u308A\u51FA\
    \u3059\r\n    fill(dmin, dmin + MAX_V, IINF);\r\n    dmin[s] = 0;\r\n    que.push(P(0,\
    \ s));\r\n\r\n    while (!que.empty()) {\r\n        P p = que.top();\r\n     \
    \   que.pop();\r\n        int v = p.second;\r\n        if (dmin[v] < p.first)\
    \ continue;\r\n        for (auto &e : G[v]) {\r\n            if (dmin[e.to] >\
    \ dmin[v] + e.cost) {\r\n                dmin[e.to] = dmin[v] + e.cost;\r\n  \
    \              que.push(P(dmin[e.to], e.to));\r\n            }\r\n        }\r\n\
    \    }\r\n}\n"
  code: "/*\r\n\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\r\n\u8A08\u7B97\u91CF O(Elog(V))\r\
    \n\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\r\n\u8CA0\u306E\u8FBA\u304C\
    \u3042\u308B\u3068\u304D\u306F\u4F7F\u3048\u306A\u3044\r\n*/\r\n\r\n#include <functional>\r\
    \n#include <queue>\r\n#include <utility>\r\n#include <vector>\r\n#include <climits>\r\
    \n\r\nusing namespace std;\r\ntypedef pair<int, int> P;  // first\u306F\u6700\u77ED\
    \u8DDD\u96E2,second\u306F\u9802\u70B9\u306E\u756A\u53F7\r\n\r\nconst int MAX_V\
    \ = int(1e5 + 5);\r\nconst int IINF = INT_MAX;\r\n\r\nstruct edge {\r\n    int\
    \ from, to, cost;\r\n    edge(int u, int v, int c) : from(u), to(v), cost(c){};\r\
    \n};\r\n\r\nvector<edge> G[MAX_V];\r\nint dmin[MAX_V];\r\n\r\nvoid add_edge(int\
    \ u, int v, int cost) {\r\n    G[u].push_back(edge(u, v, cost));\r\n    G[v].push_back(edge(v,\
    \ u, cost));\r\n}\r\n\r\nvoid dijkstra(int s) {\r\n    priority_queue<P, vector<P>,\
    \ greater<P> > que;  //\u5C0F\u3055\u3044\u3082\u306E\u304B\u3089\u53D6\u308A\u51FA\
    \u3059\r\n    fill(dmin, dmin + MAX_V, IINF);\r\n    dmin[s] = 0;\r\n    que.push(P(0,\
    \ s));\r\n\r\n    while (!que.empty()) {\r\n        P p = que.top();\r\n     \
    \   que.pop();\r\n        int v = p.second;\r\n        if (dmin[v] < p.first)\
    \ continue;\r\n        for (auto &e : G[v]) {\r\n            if (dmin[e.to] >\
    \ dmin[v] + e.cost) {\r\n                dmin[e.to] = dmin[v] + e.cost;\r\n  \
    \              que.push(P(dmin[e.to], e.to));\r\n            }\r\n        }\r\n\
    \    }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/shortest_path/dijkstra.cpp
  requiredBy: []
  timestamp: '2018-08-06 16:41:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/shortest_path/dijkstra.cpp
layout: document
redirect_from:
- /library/src/graphs/shortest_path/dijkstra.cpp
- /library/src/graphs/shortest_path/dijkstra.cpp.html
title: src/graphs/shortest_path/dijkstra.cpp
---
