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
  bundledCode: "#line 1 \"src/DP/LIS.cpp\"\n/*\r\nLIS \u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217\r\nO(NlogN)\r\n*/\r\n#include <algorithm>\r\n#include <vector>\r\n\
    using namespace std;\r\n\r\nconst int IINF = INT_MAX;\r\nint n;\r\nvector<int>\
    \ a, dp;\r\n\r\nint lis() {\r\n    dp.resize(n+1,IINF);\r\n    for (int i = 0;\
    \ i < n; i++) {\r\n        *lower_bound(dp.begin(),dp.end(),a[i]) = a[i];\r\n\
    \    }\r\n    return lower_bound(dp.begin(),dp.end(),IINF) - dp.begin();\r\n}\n"
  code: "/*\r\nLIS \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\r\nO(NlogN)\r\n*/\r\n\
    #include <algorithm>\r\n#include <vector>\r\nusing namespace std;\r\n\r\nconst\
    \ int IINF = INT_MAX;\r\nint n;\r\nvector<int> a, dp;\r\n\r\nint lis() {\r\n \
    \   dp.resize(n+1,IINF);\r\n    for (int i = 0; i < n; i++) {\r\n        *lower_bound(dp.begin(),dp.end(),a[i])\
    \ = a[i];\r\n    }\r\n    return lower_bound(dp.begin(),dp.end(),IINF) - dp.begin();\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: src/DP/LIS.cpp
  requiredBy: []
  timestamp: '2018-08-29 14:55:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DP/LIS.cpp
layout: document
redirect_from:
- /library/src/DP/LIS.cpp
- /library/src/DP/LIS.cpp.html
title: src/DP/LIS.cpp
---
