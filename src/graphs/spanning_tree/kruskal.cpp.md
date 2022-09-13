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
  bundledCode: "#line 1 \"src/graphs/spanning_tree/kruskal.cpp\"\n/*\r\n\u30AF\u30E9\
    \u30B9\u30AB\u30EB\u6CD5\r\n\u8A08\u7B97\u91CF O(Elog(V))\r\n\u6700\u5C0F\u5168\
    \u57DF\u6728\u3092\u6C42\u3081\u308B\r\nUnionFind\u6728\u304C\u5FC5\u8981\r\n\
    */\r\n#include <algorithm>\r\n#include <vector>\r\n\r\nusing namespace std;\r\n\
    \r\nconst int MAX_V = 100000;\r\n\r\nstruct UnionFindTree {\r\n    int par[MAX_V];\r\
    \n    int rank[MAX_V];\r\n\r\n    void init(int n) {\r\n        for (int i = 0;\
    \ i < n; i++) {\r\n            par[i] = i;\r\n            rank[i] = 0;\r\n   \
    \     }\r\n    }\r\n\r\n    int find(int x) {\r\n        if (par[x] == x) {\r\n\
    \            return x;\r\n        } else {\r\n            return par[x] = find(par[x]);\r\
    \n        }\r\n    }\r\n\r\n    void unite(int x, int y) {\r\n        x = find(x);\r\
    \n        y = find(y);\r\n        if (x == y) return;\r\n\r\n        if (rank[x]\
    \ < rank[y]) {\r\n            par[x] = y;\r\n        } else {\r\n            par[y]\
    \ = x;\r\n            if (rank[x] == rank[y]) rank[x]++;\r\n        }\r\n    }\r\
    \n\r\n    bool same(int x, int y) { return find(x) == find(y); }\r\n};\r\n\r\n\
    struct edge {\r\n    int u, v, cost;\r\n};\r\n\r\nbool comp(const edge &e1, const\
    \ edge &e2) { return e1.cost < e2.cost; }\r\n\r\nvector<edge> es;\r\nint V, E;\r\
    \n\r\nint kruskal() {\r\n    sort(es.begin(), es.end(), comp);\r\n    UnionFindTree\
    \ a;\r\n    a.init(V);\r\n    int res = 0;\r\n    for (int i = 0; i < es.size();\
    \ i++) {\r\n        edge e = es[i];\r\n        if (!a.same(e.u, e.v)) {\r\n  \
    \          a.unite(e.u, e.v);\r\n            res += e.cost;\r\n        }\r\n \
    \   }\r\n    return res;\r\n}\n"
  code: "/*\r\n\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5\r\n\u8A08\u7B97\u91CF O(Elog(V))\r\
    \n\u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B\r\nUnionFind\u6728\u304C\
    \u5FC5\u8981\r\n*/\r\n#include <algorithm>\r\n#include <vector>\r\n\r\nusing namespace\
    \ std;\r\n\r\nconst int MAX_V = 100000;\r\n\r\nstruct UnionFindTree {\r\n    int\
    \ par[MAX_V];\r\n    int rank[MAX_V];\r\n\r\n    void init(int n) {\r\n      \
    \  for (int i = 0; i < n; i++) {\r\n            par[i] = i;\r\n            rank[i]\
    \ = 0;\r\n        }\r\n    }\r\n\r\n    int find(int x) {\r\n        if (par[x]\
    \ == x) {\r\n            return x;\r\n        } else {\r\n            return par[x]\
    \ = find(par[x]);\r\n        }\r\n    }\r\n\r\n    void unite(int x, int y) {\r\
    \n        x = find(x);\r\n        y = find(y);\r\n        if (x == y) return;\r\
    \n\r\n        if (rank[x] < rank[y]) {\r\n            par[x] = y;\r\n        }\
    \ else {\r\n            par[y] = x;\r\n            if (rank[x] == rank[y]) rank[x]++;\r\
    \n        }\r\n    }\r\n\r\n    bool same(int x, int y) { return find(x) == find(y);\
    \ }\r\n};\r\n\r\nstruct edge {\r\n    int u, v, cost;\r\n};\r\n\r\nbool comp(const\
    \ edge &e1, const edge &e2) { return e1.cost < e2.cost; }\r\n\r\nvector<edge>\
    \ es;\r\nint V, E;\r\n\r\nint kruskal() {\r\n    sort(es.begin(), es.end(), comp);\r\
    \n    UnionFindTree a;\r\n    a.init(V);\r\n    int res = 0;\r\n    for (int i\
    \ = 0; i < es.size(); i++) {\r\n        edge e = es[i];\r\n        if (!a.same(e.u,\
    \ e.v)) {\r\n            a.unite(e.u, e.v);\r\n            res += e.cost;\r\n\
    \        }\r\n    }\r\n    return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/spanning_tree/kruskal.cpp
  requiredBy: []
  timestamp: '2018-05-24 17:31:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/spanning_tree/kruskal.cpp
layout: document
redirect_from:
- /library/src/graphs/spanning_tree/kruskal.cpp
- /library/src/graphs/spanning_tree/kruskal.cpp.html
title: src/graphs/spanning_tree/kruskal.cpp
---
