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
  bundledCode: "#line 1 \"src/math/power.cpp\"\n/*\r\n\u7E70\u308A\u8FD4\u3057\u4E8C\
    \u4E57\u6CD5\r\n\u8A08\u7B97\u91CF O(logN)\r\nx^n \u3079\u304D\u4E57\u3092\u6C42\
    \u3081\u308B\r\n*/\r\n#include<bits/stdc++.h>\r\n\r\nint64_t power(int64_t x,\
    \ int n) { \r\n\tint64_t ans = 1;\r\n\twhile (n > 0) {\r\n\t\tif ((n & 1) == 1)\
    \ {\r\n\t\t\tans = ans * x;\r\n\t\t}\r\n\t\tx = x * x; //\u4E00\u5468\u3059\u308B\
    \u5EA6\u306Bx, x^2, x^4, x^8\u3068\u306A\u308B\r\n\t\tn >>= 1; //\u6841\u3092\u305A\
    \u3089\u3059 n = n >> 1\r\n\t}\r\n\treturn ans;\r\n}\n"
  code: "/*\r\n\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\r\n\u8A08\u7B97\u91CF O(logN)\r\
    \nx^n \u3079\u304D\u4E57\u3092\u6C42\u3081\u308B\r\n*/\r\n#include<bits/stdc++.h>\r\
    \n\r\nint64_t power(int64_t x, int n) { \r\n\tint64_t ans = 1;\r\n\twhile (n >\
    \ 0) {\r\n\t\tif ((n & 1) == 1) {\r\n\t\t\tans = ans * x;\r\n\t\t}\r\n\t\tx =\
    \ x * x; //\u4E00\u5468\u3059\u308B\u5EA6\u306Bx, x^2, x^4, x^8\u3068\u306A\u308B\
    \r\n\t\tn >>= 1; //\u6841\u3092\u305A\u3089\u3059 n = n >> 1\r\n\t}\r\n\treturn\
    \ ans;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/power.cpp
  requiredBy: []
  timestamp: '2019-06-08 22:29:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/power.cpp
layout: document
redirect_from:
- /library/src/math/power.cpp
- /library/src/math/power.cpp.html
title: src/math/power.cpp
---
