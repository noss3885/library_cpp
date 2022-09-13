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
  bundledCode: "#line 1 \"src/graphs/shortest_path/warshal_floyd.cpp\"\n/*\r\n\u30EF\
    \u30FC\u30B7\u30E3\u30EB\u30FB\u30D5\u30ED\u30A4\u30C9\u6CD5\r\n\u8A08\u7B97\u91CF\
    \ O(V^3)\r\n\u5168\u70B9\u5BFE\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\
    \r\n\u8CA0\u306E\u8FBA\u304C\u3042\u3063\u3066\u3082\u53EF\r\n\u8CA0\u306E\u9589\
    \u8DEF\u304C\u3042\u308B\u3068\u304Dd[i][i]<0\u3068\u306A\u308Bi\u304C\u5B58\u5728\
    \u3059\u308B\r\n*/\r\n#include <algorithm>\r\nusing namespace std;\r\n\r\nconst\
    \ int MAX_V = 1000;\r\n\r\nint d[MAX_V][MAX_V];\r\nint V;\r\n\r\nvoid warshal_floyd()\
    \ {\r\n    for (int k = 0; k < V; k++) {\r\n        for (int i = 0; i < V; i++)\
    \ {\r\n            for (int j = 0; j < V; j++){\r\n                d[i][j] = min(d[i][j],\
    \ d[i][k] + d[k][j]);\r\n            }\r\n        }\r\n    }\r\n}\n"
  code: "/*\r\n\u30EF\u30FC\u30B7\u30E3\u30EB\u30FB\u30D5\u30ED\u30A4\u30C9\u6CD5\r\
    \n\u8A08\u7B97\u91CF O(V^3)\r\n\u5168\u70B9\u5BFE\u6700\u77ED\u7D4C\u8DEF\u3092\
    \u6C42\u3081\u308B\r\n\u8CA0\u306E\u8FBA\u304C\u3042\u3063\u3066\u3082\u53EF\r\
    \n\u8CA0\u306E\u9589\u8DEF\u304C\u3042\u308B\u3068\u304Dd[i][i]<0\u3068\u306A\u308B\
    i\u304C\u5B58\u5728\u3059\u308B\r\n*/\r\n#include <algorithm>\r\nusing namespace\
    \ std;\r\n\r\nconst int MAX_V = 1000;\r\n\r\nint d[MAX_V][MAX_V];\r\nint V;\r\n\
    \r\nvoid warshal_floyd() {\r\n    for (int k = 0; k < V; k++) {\r\n        for\
    \ (int i = 0; i < V; i++) {\r\n            for (int j = 0; j < V; j++){\r\n  \
    \              d[i][j] = min(d[i][j], d[i][k] + d[k][j]);\r\n            }\r\n\
    \        }\r\n    }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/shortest_path/warshal_floyd.cpp
  requiredBy: []
  timestamp: '2018-08-06 16:41:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/shortest_path/warshal_floyd.cpp
layout: document
redirect_from:
- /library/src/graphs/shortest_path/warshal_floyd.cpp
- /library/src/graphs/shortest_path/warshal_floyd.cpp.html
title: src/graphs/shortest_path/warshal_floyd.cpp
---
