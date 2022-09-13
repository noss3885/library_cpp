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
  bundledCode: "#line 1 \"src/graphs/shortest_path/Bellman_Ford.cpp\"\n/*\r\n\u30D9\
    \u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\r\n\u8A08\u7B97\u91CF O(VE)\r\
    \n\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\r\n\u8CA0\u306E\u8FBA\u304C\
    \u3042\u3063\u3066\u3082\u53EF\r\n\u8CA0\u306E\u8FBA\u304C\u3042\u308B\u3068\u304D\
    V\u56DE\u4EE5\u4E0A\u66F4\u65B0\u3059\u308B\r\n*/\r\n#include <algorithm>\r\n\
    #include <vector>\r\n#include <climits>\r\nusing namespace std;\r\n\r\nconst int\
    \ MAX_V = 1000;\r\nconst int IINF = INT_MAX;\r\n\r\nstruct edge {\r\n    int from,\
    \ to, cost;\r\n    edge(int u, int v, int c) : from(u), to(v), cost(c){};\r\n\
    };  //\u8FBA\u306E\u59CB\u70B9\u3001\u7D42\u70B9\u3001\u91CD\u307F\r\n\r\nvector<edge>\
    \ es;  //\u8FBA\r\nint dmin[MAX_V];  //\u6700\u77ED\u8DDD\u96E2\r\n\r\nvoid add_edge(int\
    \ u, int v, int cost) {\r\n    es.push_back(edge(u, v, cost));\r\n}\r\n\r\n//\
    \ S\u756A\u76EE\u306E\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\
    \u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\r\nvoid shortest_path(int s) {\r\n\
    \    fill(dmin, dmin + MAX_V, IINF);\r\n    dmin[s] = 0;\r\n    while (true) {\r\
    \n        bool update = false;\r\n        for (auto &e : es) {\r\n           \
    \ if (dmin[e.from] != IINF && dmin[e.to] > dmin[e.from] + e.cost) {\r\n      \
    \          dmin[e.to] = dmin[e.from] + e.cost;\r\n                update = true;\r\
    \n            }\r\n        }\r\n        if (!update) break;\r\n    }\r\n}\n"
  code: "/*\r\n\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\r\n\u8A08\u7B97\
    \u91CF O(VE)\r\n\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\r\n\u8CA0\u306E\
    \u8FBA\u304C\u3042\u3063\u3066\u3082\u53EF\r\n\u8CA0\u306E\u8FBA\u304C\u3042\u308B\
    \u3068\u304DV\u56DE\u4EE5\u4E0A\u66F4\u65B0\u3059\u308B\r\n*/\r\n#include <algorithm>\r\
    \n#include <vector>\r\n#include <climits>\r\nusing namespace std;\r\n\r\nconst\
    \ int MAX_V = 1000;\r\nconst int IINF = INT_MAX;\r\n\r\nstruct edge {\r\n    int\
    \ from, to, cost;\r\n    edge(int u, int v, int c) : from(u), to(v), cost(c){};\r\
    \n};  //\u8FBA\u306E\u59CB\u70B9\u3001\u7D42\u70B9\u3001\u91CD\u307F\r\n\r\nvector<edge>\
    \ es;  //\u8FBA\r\nint dmin[MAX_V];  //\u6700\u77ED\u8DDD\u96E2\r\n\r\nvoid add_edge(int\
    \ u, int v, int cost) {\r\n    es.push_back(edge(u, v, cost));\r\n}\r\n\r\n//\
    \ S\u756A\u76EE\u306E\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\
    \u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\r\nvoid shortest_path(int s) {\r\n\
    \    fill(dmin, dmin + MAX_V, IINF);\r\n    dmin[s] = 0;\r\n    while (true) {\r\
    \n        bool update = false;\r\n        for (auto &e : es) {\r\n           \
    \ if (dmin[e.from] != IINF && dmin[e.to] > dmin[e.from] + e.cost) {\r\n      \
    \          dmin[e.to] = dmin[e.from] + e.cost;\r\n                update = true;\r\
    \n            }\r\n        }\r\n        if (!update) break;\r\n    }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/shortest_path/Bellman_Ford.cpp
  requiredBy: []
  timestamp: '2018-08-06 16:41:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/shortest_path/Bellman_Ford.cpp
layout: document
redirect_from:
- /library/src/graphs/shortest_path/Bellman_Ford.cpp
- /library/src/graphs/shortest_path/Bellman_Ford.cpp.html
title: src/graphs/shortest_path/Bellman_Ford.cpp
---
