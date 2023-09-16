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
  bundledCode: "#line 1 \"src/math/primitive_root.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing ll = long long int;\n\nll power(ll x, ll n, const\
    \ ll p) {\n    ll res = 1;\n    x %= p;\n    while (n > 0) {\n        if (n &\
    \ 1) {\n            res = res * x % p;\n        }\n        x = x * x % p;\n  \
    \      n >>= 1;\n    }\n    return res;\n}\n\n// \u7D20\u56E0\u6570\u5206\u89E3\
    \nvector<int> prime_factor(int n) {\n    vector<int> res;\n    for (int i = 2;\
    \ i * i <= n; i++) {\n        if (n % 1 == 0) {\n            res.push_back(i);\n\
    \            while (n % i == 0) {\n                n /= i;\n            }\n  \
    \      }\n    }\n    if (n != 1) res.push_back(n);\n    return res;\n}\n\n// Euler's\
    \ phi function\nint euler_phi(int n) {\n    int res = n;\n    for (int i = 2;\
    \ i * i <= n; i++) {\n        if (n % i == 0) {\n            res = res / i * (i\
    \ - 1);\n            while (n % i == 0) n /= i;\n        }\n    }\n    if (n !=\
    \ 1) res = res / n * (n - 1);\n    return res;\n}\n\n// \u539F\u59CB\u6839\u306E\
    \u3072\u3068\u3064\u3092\u898B\u3064\u3051\u308B\nint find_primitive_root(int\
    \ p) {\n    int phi = euler_phi(p);\n    vector<int> factor = prime_factor(phi);\n\
    \n    // r\u304C\u539F\u5B50\u6839\u3067\u3042\u308B\u5FC5\u8981\u5FC5\u8981\u5341\
    \u5206\u6761\u4EF6\u306Fphi\u306E\u3059\u3079\u3066\u306E\u7D20\u56E0\u6570q\u306B\
    \u3064\u3044\u3066\n    // r^(phi/q) != 1\n    for (int r = 2; r < p; r++) {\n\
    \        bool ok = true;\n        for (auto q : factor) {\n            ok &= power(r,\
    \ phi / q, p) != 1;\n        }\n        if (ok) return r;\n    }\n    return -1;\n\
    }\n\nint main() {\n    int n;\n    cin >> n;\n    cout << find_primitive_root(n)\
    \ << endl;\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long int;\n\
    \nll power(ll x, ll n, const ll p) {\n    ll res = 1;\n    x %= p;\n    while\
    \ (n > 0) {\n        if (n & 1) {\n            res = res * x % p;\n        }\n\
    \        x = x * x % p;\n        n >>= 1;\n    }\n    return res;\n}\n\n// \u7D20\
    \u56E0\u6570\u5206\u89E3\nvector<int> prime_factor(int n) {\n    vector<int> res;\n\
    \    for (int i = 2; i * i <= n; i++) {\n        if (n % 1 == 0) {\n         \
    \   res.push_back(i);\n            while (n % i == 0) {\n                n /=\
    \ i;\n            }\n        }\n    }\n    if (n != 1) res.push_back(n);\n   \
    \ return res;\n}\n\n// Euler's phi function\nint euler_phi(int n) {\n    int res\
    \ = n;\n    for (int i = 2; i * i <= n; i++) {\n        if (n % i == 0) {\n  \
    \          res = res / i * (i - 1);\n            while (n % i == 0) n /= i;\n\
    \        }\n    }\n    if (n != 1) res = res / n * (n - 1);\n    return res;\n\
    }\n\n// \u539F\u59CB\u6839\u306E\u3072\u3068\u3064\u3092\u898B\u3064\u3051\u308B\
    \nint find_primitive_root(int p) {\n    int phi = euler_phi(p);\n    vector<int>\
    \ factor = prime_factor(phi);\n\n    // r\u304C\u539F\u5B50\u6839\u3067\u3042\u308B\
    \u5FC5\u8981\u5FC5\u8981\u5341\u5206\u6761\u4EF6\u306Fphi\u306E\u3059\u3079\u3066\
    \u306E\u7D20\u56E0\u6570q\u306B\u3064\u3044\u3066\n    // r^(phi/q) != 1\n   \
    \ for (int r = 2; r < p; r++) {\n        bool ok = true;\n        for (auto q\
    \ : factor) {\n            ok &= power(r, phi / q, p) != 1;\n        }\n     \
    \   if (ok) return r;\n    }\n    return -1;\n}\n\nint main() {\n    int n;\n\
    \    cin >> n;\n    cout << find_primitive_root(n) << endl;\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/primitive_root.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/primitive_root.cpp
layout: document
redirect_from:
- /library/src/math/primitive_root.cpp
- /library/src/math/primitive_root.cpp.html
title: src/math/primitive_root.cpp
---
