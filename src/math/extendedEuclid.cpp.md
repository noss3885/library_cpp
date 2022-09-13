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
  bundledCode: "#line 1 \"src/math/extendedEuclid.cpp\"\n/*\r\n\u62E1\u5F35\u30E6\u30FC\
    \u30AF\u30EA\u30C3\u30C9\u4E92\u9664\u6CD5\r\n\u8A08\u7B97\u91CF O(log(m)^2)\r\
    \nax+by=gcd(a,b) \u3068\u306A\u308Bx,y\u3092\u6C42\u3081\u308B\r\nmod\u306E\u9006\
    \u5143\u3092\u6C42\u3081\u308B\r\n*/\r\n\r\nint extgcd(int a, int b, int &x, int\
    \ &y) {\r\n    if (b == 0) {\r\n        x = 1;\r\n        y = 0;\r\n        return\
    \ a;\r\n    }\r\n    else {\r\n        int d = extgcd(b, a % b, y, x);\r\n   \
    \     y -= (a / b) * x;\r\n        return d;\r\n    }\r\n}\r\n\r\nint mod_inv(int\
    \ a, int m) {  // a^-1 mod m\r\n    int a_, q;\r\n    extgcd(a, m, a_, q);\r\n\
    \    if(a_ < 0){\r\n        a_ += m;\r\n    }\r\n    return a_;\r\n}\n"
  code: "/*\r\n\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u4E92\u9664\u6CD5\r\
    \n\u8A08\u7B97\u91CF O(log(m)^2)\r\nax+by=gcd(a,b) \u3068\u306A\u308Bx,y\u3092\
    \u6C42\u3081\u308B\r\nmod\u306E\u9006\u5143\u3092\u6C42\u3081\u308B\r\n*/\r\n\r\
    \nint extgcd(int a, int b, int &x, int &y) {\r\n    if (b == 0) {\r\n        x\
    \ = 1;\r\n        y = 0;\r\n        return a;\r\n    }\r\n    else {\r\n     \
    \   int d = extgcd(b, a % b, y, x);\r\n        y -= (a / b) * x;\r\n        return\
    \ d;\r\n    }\r\n}\r\n\r\nint mod_inv(int a, int m) {  // a^-1 mod m\r\n    int\
    \ a_, q;\r\n    extgcd(a, m, a_, q);\r\n    if(a_ < 0){\r\n        a_ += m;\r\n\
    \    }\r\n    return a_;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/extendedEuclid.cpp
  requiredBy: []
  timestamp: '2019-05-27 09:11:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/extendedEuclid.cpp
layout: document
redirect_from:
- /library/src/math/extendedEuclid.cpp
- /library/src/math/extendedEuclid.cpp.html
title: src/math/extendedEuclid.cpp
---
