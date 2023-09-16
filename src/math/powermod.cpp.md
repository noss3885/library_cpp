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
  bundledCode: "#line 1 \"src/math/powermod.cpp\"\n// x^n \u3079\u304D\u4E57 \u8A08\
    \u7B97\u91CFO(logN)\r\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\r\n\r\n#include\
    \ <bits/stdc++.h>\r\n\r\ntypedef long long ll;\r\nll MOD = 1000000007;\r\n\r\n\
    ll power(ll x, ll n) {\r\n    x %= MOD;\r\n    ll ans = 1;\r\n    while (n > 0)\
    \ {\r\n        if (n & 1) {\r\n            ans = ans * x % MOD;\r\n        }\r\
    \n        x = x * x % MOD;  // \u4E00\u5468\u3059\u308B\u5EA6\u306Bx, x^2, x^4,\
    \ x^8\u3068\u306A\u308B\r\n        n >>= 1;          // \u6841\u3092\u305A\u3089\
    \u3059 n = n >> 1\r\n    }\r\n    return ans;\r\n}\n"
  code: "// x^n \u3079\u304D\u4E57 \u8A08\u7B97\u91CFO(logN)\r\n// \u7E70\u308A\u8FD4\
    \u3057\u4E8C\u4E57\u6CD5\r\n\r\n#include <bits/stdc++.h>\r\n\r\ntypedef long long\
    \ ll;\r\nll MOD = 1000000007;\r\n\r\nll power(ll x, ll n) {\r\n    x %= MOD;\r\
    \n    ll ans = 1;\r\n    while (n > 0) {\r\n        if (n & 1) {\r\n         \
    \   ans = ans * x % MOD;\r\n        }\r\n        x = x * x % MOD;  // \u4E00\u5468\
    \u3059\u308B\u5EA6\u306Bx, x^2, x^4, x^8\u3068\u306A\u308B\r\n        n >>= 1;\
    \          // \u6841\u3092\u305A\u3089\u3059 n = n >> 1\r\n    }\r\n    return\
    \ ans;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/powermod.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/powermod.cpp
layout: document
redirect_from:
- /library/src/math/powermod.cpp
- /library/src/math/powermod.cpp.html
title: src/math/powermod.cpp
---
