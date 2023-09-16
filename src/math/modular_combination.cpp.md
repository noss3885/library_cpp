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
  bundledCode: "#line 1 \"src/math/modular_combination.cpp\"\n/*\r\n\u30D5\u30A7\u30EB\
    \u30DE\u30FC\u306E\u5C0F\u5B9A\u7406\u3092\u7528\u3044\u305F\u7D44\u307F\u5408\
    \u308F\u305B\u6570\r\n\u8A08\u7B97\u91CF O(N) ?\r\n*/\r\n#include <vector>\r\n\
    using namespace std;\r\n\r\nusing ll = long long int;\r\n\r\nconstexpr ll MOD\
    \ = ll(1e9 + 7);\r\n\r\nvector<ll> factrial, inverse;  // \u968E\u4E57\u3068\u9006\
    \u5143\u3092\u4FDD\u6301\r\n\r\nll mod_power(ll x, ll n) {  // \u7E70\u308A\u8FD4\
    \u3057\u4E8C\u4E57\u6CD5\r\n    x %= MOD;\r\n    ll res = 1;\r\n    while (n >\
    \ 0) {\r\n        if (n & 1) {\r\n            res = res * x % MOD;\r\n       \
    \ }\r\n        x = x * x % MOD;\r\n        n >>= 1;\r\n    }\r\n    return res;\r\
    \n}\r\n\r\nvoid init(ll n) {\r\n    if (n >= MOD) {\r\n        n = MOD - 1;\r\n\
    \    }\r\n    factrial.resize(n + 1);\r\n    inverse.resize(n + 1);\r\n    factrial[0]\
    \ = 1;\r\n    inverse[0] = 1;\r\n    for (ll i = 1; i <= n; i++) {\r\n       \
    \ factrial[i] = (factrial[i - 1] * i) % MOD;\r\n        inverse[i] = mod_power(factrial[i],\
    \ MOD - 2);\r\n    }\r\n}\r\n\r\nll nCk(ll n, ll k) {\r\n    if (n < 0 || k <\
    \ 0 || n < k) return 0;\r\n    if (n < MOD) return factrial[n] * inverse[k] %\
    \ MOD * inverse[n - k] % MOD;\r\n    // if n >= mod, use Lucas's theorem\r\n \
    \   ll res = 1;\r\n    while (n | k) {\r\n        res = res * nCk(n % MOD, k %\
    \ MOD) % MOD;\r\n        n /= MOD;\r\n        k /= MOD;\r\n    }\r\n    return\
    \ res;\r\n}\r\n"
  code: "/*\r\n\u30D5\u30A7\u30EB\u30DE\u30FC\u306E\u5C0F\u5B9A\u7406\u3092\u7528\u3044\
    \u305F\u7D44\u307F\u5408\u308F\u305B\u6570\r\n\u8A08\u7B97\u91CF O(N) ?\r\n*/\r\
    \n#include <vector>\r\nusing namespace std;\r\n\r\nusing ll = long long int;\r\
    \n\r\nconstexpr ll MOD = ll(1e9 + 7);\r\n\r\nvector<ll> factrial, inverse;  //\
    \ \u968E\u4E57\u3068\u9006\u5143\u3092\u4FDD\u6301\r\n\r\nll mod_power(ll x, ll\
    \ n) {  // \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\r\n    x %= MOD;\r\n   \
    \ ll res = 1;\r\n    while (n > 0) {\r\n        if (n & 1) {\r\n            res\
    \ = res * x % MOD;\r\n        }\r\n        x = x * x % MOD;\r\n        n >>= 1;\r\
    \n    }\r\n    return res;\r\n}\r\n\r\nvoid init(ll n) {\r\n    if (n >= MOD)\
    \ {\r\n        n = MOD - 1;\r\n    }\r\n    factrial.resize(n + 1);\r\n    inverse.resize(n\
    \ + 1);\r\n    factrial[0] = 1;\r\n    inverse[0] = 1;\r\n    for (ll i = 1; i\
    \ <= n; i++) {\r\n        factrial[i] = (factrial[i - 1] * i) % MOD;\r\n     \
    \   inverse[i] = mod_power(factrial[i], MOD - 2);\r\n    }\r\n}\r\n\r\nll nCk(ll\
    \ n, ll k) {\r\n    if (n < 0 || k < 0 || n < k) return 0;\r\n    if (n < MOD)\
    \ return factrial[n] * inverse[k] % MOD * inverse[n - k] % MOD;\r\n    // if n\
    \ >= mod, use Lucas's theorem\r\n    ll res = 1;\r\n    while (n | k) {\r\n  \
    \      res = res * nCk(n % MOD, k % MOD) % MOD;\r\n        n /= MOD;\r\n     \
    \   k /= MOD;\r\n    }\r\n    return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/modular_combination.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/modular_combination.cpp
layout: document
redirect_from:
- /library/src/math/modular_combination.cpp
- /library/src/math/modular_combination.cpp.html
title: src/math/modular_combination.cpp
---
