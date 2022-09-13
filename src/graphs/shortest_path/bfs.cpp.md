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
  bundledCode: "#line 1 \"src/graphs/shortest_path/bfs.cpp\"\n/*\r\n\u5E45\u512A\u5148\
    \u63A2\u7D22\r\n\u8A08\u7B97\u91CF O(HW)\r\n\u30B0\u30EA\u30C3\u30C9\u72B6\u306E\
    \u8FF7\u8DEF\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\r\n*/\r\n\r\
    \n#include <string>\r\n#include <queue>\r\nusing namespace std;\r\n\r\nconst int\
    \ IINF = 10000;\r\n\r\nqueue<int> px, py;\r\nint h, w, sx, sy, gx, gy, d[50][50],\
    \ dx[4] = {0, 1, 0, -1},\r\n                                     dy[4] = {1, 0,\
    \ -1, 0};\r\nstring s[50];\r\n\r\nint bfs() {\r\n    for (int i = 0; i < h; i++)\
    \ {\r\n        for (int j = 0; j < w; j++) {\r\n            d[i][j] = IINF;\r\n\
    \        }\r\n    }\r\n    px.push(sx - 1);\r\n    py.push(sy - 1);\r\n    d[sy][sx]\
    \ = 0;\r\n\r\n    while (px.size()) {\r\n        int x = px.front(), y = py.front();\r\
    \n        px.pop();\r\n        py.pop();\r\n        if (x == gx && y == gy) {\r\
    \n            return d[y][x];\r\n        }\r\n        for (int i = 0; i < 4; i++)\
    \ {\r\n            int nx = x + dx[i], ny = y + dy[i];\r\n            if (nx <\
    \ 0 || nx >= w )continue;\r\n            if (ny < 0 || ny <= h )continue;\r\n\
    \            if (s[ny][nx] == '.' && d[ny][nx] == IINF) {\r\n                d[ny][nx]\
    \ = d[y][x] + 1;\r\n                px.push(nx);\r\n                py.push(ny);\r\
    \n            }\r\n        }\r\n    }\r\n    return IINF;\r\n}\n"
  code: "/*\r\n\u5E45\u512A\u5148\u63A2\u7D22\r\n\u8A08\u7B97\u91CF O(HW)\r\n\u30B0\
    \u30EA\u30C3\u30C9\u72B6\u306E\u8FF7\u8DEF\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\
    \u6C42\u3081\u308B\r\n*/\r\n\r\n#include <string>\r\n#include <queue>\r\nusing\
    \ namespace std;\r\n\r\nconst int IINF = 10000;\r\n\r\nqueue<int> px, py;\r\n\
    int h, w, sx, sy, gx, gy, d[50][50], dx[4] = {0, 1, 0, -1},\r\n              \
    \                       dy[4] = {1, 0, -1, 0};\r\nstring s[50];\r\n\r\nint bfs()\
    \ {\r\n    for (int i = 0; i < h; i++) {\r\n        for (int j = 0; j < w; j++)\
    \ {\r\n            d[i][j] = IINF;\r\n        }\r\n    }\r\n    px.push(sx - 1);\r\
    \n    py.push(sy - 1);\r\n    d[sy][sx] = 0;\r\n\r\n    while (px.size()) {\r\n\
    \        int x = px.front(), y = py.front();\r\n        px.pop();\r\n        py.pop();\r\
    \n        if (x == gx && y == gy) {\r\n            return d[y][x];\r\n       \
    \ }\r\n        for (int i = 0; i < 4; i++) {\r\n            int nx = x + dx[i],\
    \ ny = y + dy[i];\r\n            if (nx < 0 || nx >= w )continue;\r\n        \
    \    if (ny < 0 || ny <= h )continue;\r\n            if (s[ny][nx] == '.' && d[ny][nx]\
    \ == IINF) {\r\n                d[ny][nx] = d[y][x] + 1;\r\n                px.push(nx);\r\
    \n                py.push(ny);\r\n            }\r\n        }\r\n    }\r\n    return\
    \ IINF;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/shortest_path/bfs.cpp
  requiredBy: []
  timestamp: '2018-08-06 16:41:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/shortest_path/bfs.cpp
layout: document
redirect_from:
- /library/src/graphs/shortest_path/bfs.cpp
- /library/src/graphs/shortest_path/bfs.cpp.html
title: src/graphs/shortest_path/bfs.cpp
---
