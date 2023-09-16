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
  bundledCode: "#line 1 \"src/math/Lagrange_interpolation.cpp\"\n/*\nLagrange interpolation\
    \ polynomial\nx = 0,1,2,...N\nO(N)\n*/\n#include <vector>\nusing namespace std;\n\
    \ntypedef long long ll;\nconstexpr ll MOD = 998244353;\n\nll power(ll x, ll n)\
    \ {\n    x %= MOD;\n    ll res = 1;\n    while (n > 0) {\n        if (n & 1) {\n\
    \            res = res * x % MOD;\n            res %= MOD;\n        }\n      \
    \  x = x * x % MOD;\n        n >>= 1;\n    }\n    return res;\n}\n\nll mod_inv(ll\
    \ x) {\n    return power(x, MOD - 2);\n}\n\n// calclate P(t) from (0,P(0)),(1,P(1)),...,(N,P(N))\n\
    ll interpolate(vector<ll> y, ll t) {\n    ll n = ll(y.size()) - 1, q = 1, res\
    \ = 0;\n    if (t <= n) return y[t];\n    for (ll i = 0; i <= n; i++) {\n    \
    \    q *= t - i;\n        q = (q % MOD + MOD) % MOD;\n    }\n    vector<ll> fac(n\
    \ + 1), inv(n + 1);\n    fac[0] = 1;\n    inv[0] = 1;\n    for (ll i = 0; i <\
    \ n; i++) {\n        fac[i + 1] = fac[i] * (i + 1) % MOD;\n        inv[i + 1]\
    \ = mod_inv(fac[i + 1]);\n    }\n    for (int i = 0; i <= n; i++) {\n        ll\
    \ tmp = y[i] * q % MOD * inv[i] % MOD * inv[n - i] % MOD * mod_inv(t - i);\n \
    \       if ((n - i) & 1)\n            res -= tmp;\n        else\n            res\
    \ += tmp;\n        res = (res % MOD + MOD) % MOD;\n    }\n    return res;\n}\n"
  code: "/*\nLagrange interpolation polynomial\nx = 0,1,2,...N\nO(N)\n*/\n#include\
    \ <vector>\nusing namespace std;\n\ntypedef long long ll;\nconstexpr ll MOD =\
    \ 998244353;\n\nll power(ll x, ll n) {\n    x %= MOD;\n    ll res = 1;\n    while\
    \ (n > 0) {\n        if (n & 1) {\n            res = res * x % MOD;\n        \
    \    res %= MOD;\n        }\n        x = x * x % MOD;\n        n >>= 1;\n    }\n\
    \    return res;\n}\n\nll mod_inv(ll x) {\n    return power(x, MOD - 2);\n}\n\n\
    // calclate P(t) from (0,P(0)),(1,P(1)),...,(N,P(N))\nll interpolate(vector<ll>\
    \ y, ll t) {\n    ll n = ll(y.size()) - 1, q = 1, res = 0;\n    if (t <= n) return\
    \ y[t];\n    for (ll i = 0; i <= n; i++) {\n        q *= t - i;\n        q = (q\
    \ % MOD + MOD) % MOD;\n    }\n    vector<ll> fac(n + 1), inv(n + 1);\n    fac[0]\
    \ = 1;\n    inv[0] = 1;\n    for (ll i = 0; i < n; i++) {\n        fac[i + 1]\
    \ = fac[i] * (i + 1) % MOD;\n        inv[i + 1] = mod_inv(fac[i + 1]);\n    }\n\
    \    for (int i = 0; i <= n; i++) {\n        ll tmp = y[i] * q % MOD * inv[i]\
    \ % MOD * inv[n - i] % MOD * mod_inv(t - i);\n        if ((n - i) & 1)\n     \
    \       res -= tmp;\n        else\n            res += tmp;\n        res = (res\
    \ % MOD + MOD) % MOD;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/Lagrange_interpolation.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/Lagrange_interpolation.cpp
layout: document
redirect_from:
- /library/src/math/Lagrange_interpolation.cpp
- /library/src/math/Lagrange_interpolation.cpp.html
title: src/math/Lagrange_interpolation.cpp
---
