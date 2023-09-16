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
  bundledCode: "#line 1 \"src/graphs/coordinate_compression.cpp\"\n/*\r\n\u5EA7\u6A19\
    \u5727\u7E2E\r\n\u8A08\u7B97\u91CF: \u521D\u671F\u69CB\u7BC9 O(NlogN), \u5727\u7E2E\
    \ O(logN), \u5C55\u958B O(1)\r\n\u5EA7\u6A19\u306E\u7BC4\u56F2\u304C\u5E83\u3044\
    \u3068\u304D\u5EA7\u6A19\u306E\u5927\u5C0F\u3084\u4F4D\u7F6E\u95A2\u4FC2\u3092\
    \u7DAD\u6301\u3057\u306A\u304C\u3089\u7BC4\u56F2\u3092\u72ED\u3081\u308B\r\n*/\r\
    \n#include <algorithm>\r\n#include <map>\r\n#include <vector>\r\nusing namespace\
    \ std;\r\n\r\nvoid compress(vector<int>& x, map<int, int>& zip, vector<int>& unzip)\
    \ {\r\n    sort(x.begin(), x.end());\r\n    x.erase(unique(x.begin(), x.end()),\
    \ x.end());\r\n    unzip.resize(x.size());\r\n    for (int i = 0; i < x.size();\
    \ i++) {\r\n        zip[x[i]] = i;\r\n        unzip[i] = x[i];\r\n    }\r\n}\r\
    \n"
  code: "/*\r\n\u5EA7\u6A19\u5727\u7E2E\r\n\u8A08\u7B97\u91CF: \u521D\u671F\u69CB\u7BC9\
    \ O(NlogN), \u5727\u7E2E O(logN), \u5C55\u958B O(1)\r\n\u5EA7\u6A19\u306E\u7BC4\
    \u56F2\u304C\u5E83\u3044\u3068\u304D\u5EA7\u6A19\u306E\u5927\u5C0F\u3084\u4F4D\
    \u7F6E\u95A2\u4FC2\u3092\u7DAD\u6301\u3057\u306A\u304C\u3089\u7BC4\u56F2\u3092\
    \u72ED\u3081\u308B\r\n*/\r\n#include <algorithm>\r\n#include <map>\r\n#include\
    \ <vector>\r\nusing namespace std;\r\n\r\nvoid compress(vector<int>& x, map<int,\
    \ int>& zip, vector<int>& unzip) {\r\n    sort(x.begin(), x.end());\r\n    x.erase(unique(x.begin(),\
    \ x.end()), x.end());\r\n    unzip.resize(x.size());\r\n    for (int i = 0; i\
    \ < x.size(); i++) {\r\n        zip[x[i]] = i;\r\n        unzip[i] = x[i];\r\n\
    \    }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/coordinate_compression.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/coordinate_compression.cpp
layout: document
redirect_from:
- /library/src/graphs/coordinate_compression.cpp
- /library/src/graphs/coordinate_compression.cpp.html
title: src/graphs/coordinate_compression.cpp
---
