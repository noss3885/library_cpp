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
  bundledCode: "#line 1 \"src/math/combination.cpp\"\n/*\r\n\u7D44\u307F\u5408\u308F\
    \u305B\u6570\u8A08\u7B97 (\u518D\u5E30)\r\n\u8A08\u7B97\u91CFO(N)\r\n*/\r\n\r\n\
    typedef long long ll;\r\n\r\nll nCk(ll n, ll k) {\r\n    if (k == 0)\r\n     \
    \   return 1;\r\n    else\r\n        return nCk(n, k - 1) * (n - k + 1) / k;\r\
    \n}\n"
  code: "/*\r\n\u7D44\u307F\u5408\u308F\u305B\u6570\u8A08\u7B97 (\u518D\u5E30)\r\n\
    \u8A08\u7B97\u91CFO(N)\r\n*/\r\n\r\ntypedef long long ll;\r\n\r\nll nCk(ll n,\
    \ ll k) {\r\n    if (k == 0)\r\n        return 1;\r\n    else\r\n        return\
    \ nCk(n, k - 1) * (n - k + 1) / k;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/combination.cpp
  requiredBy: []
  timestamp: '2019-06-08 22:21:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/combination.cpp
layout: document
redirect_from:
- /library/src/math/combination.cpp
- /library/src/math/combination.cpp.html
title: src/math/combination.cpp
---
