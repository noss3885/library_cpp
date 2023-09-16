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
  bundledCode: "#line 1 \"src/data_structures/rolling_hash.cpp\"\n#include <bits/stdc++.h>\r\
    \ntypedef long long ll;\r\n\r\nconstexpr int M = 2;\r\nconstexpr ll MODS[M] =\
    \ {ll(1e9 + 7), ll(1e9 + 9)};\r\n\r\nstruct RollingHash {\r\n    std::vector<std::vector<ll>\
    \ > powb, rhash;\r\n    int N;\r\n    void build(const std::string& str, const\
    \ ll base = ll(1e5 + 7)) {\r\n        N = str.size();\r\n        powb.resize(M);\r\
    \n        rhash.resize(M);\r\n        for (int k = 0; k < M; k++) {\r\n      \
    \      powb[k].resize(N + 1);\r\n            rhash[k].resize(N + 1);\r\n     \
    \       powb[k][0] = 1;\r\n            rhash[k][0] = 0;\r\n            for (int\
    \ i = 0; i < N; i++) {\r\n                rhash[k][i + 1] = (rhash[k][i] * base\
    \ + str[i]) % MODS[k];\r\n                powb[k][i + 1] = powb[k][i] * base %\
    \ MODS[k];\r\n            }\r\n        }\r\n    }\r\n\r\n    //[l,r)\r\n    ll\
    \ get_hash(int k, int l, int r) { return (rhash[k][r] - rhash[k][l] * powb[k][r\
    \ - l] % MODS[k] + MODS[k]) % MODS[k]; }\r\n\r\n    bool match(int l1, int r1,\
    \ int l2, int r2) {\r\n        bool res = true;\r\n        for (int k = 0; k <\
    \ M; k++) {\r\n            res &= get_hash(k, l1, r1) == get_hash(k, l2, r2);\r\
    \n        }\r\n        return res;\r\n    }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\ntypedef long long ll;\r\n\r\nconstexpr int M\
    \ = 2;\r\nconstexpr ll MODS[M] = {ll(1e9 + 7), ll(1e9 + 9)};\r\n\r\nstruct RollingHash\
    \ {\r\n    std::vector<std::vector<ll> > powb, rhash;\r\n    int N;\r\n    void\
    \ build(const std::string& str, const ll base = ll(1e5 + 7)) {\r\n        N =\
    \ str.size();\r\n        powb.resize(M);\r\n        rhash.resize(M);\r\n     \
    \   for (int k = 0; k < M; k++) {\r\n            powb[k].resize(N + 1);\r\n  \
    \          rhash[k].resize(N + 1);\r\n            powb[k][0] = 1;\r\n        \
    \    rhash[k][0] = 0;\r\n            for (int i = 0; i < N; i++) {\r\n       \
    \         rhash[k][i + 1] = (rhash[k][i] * base + str[i]) % MODS[k];\r\n     \
    \           powb[k][i + 1] = powb[k][i] * base % MODS[k];\r\n            }\r\n\
    \        }\r\n    }\r\n\r\n    //[l,r)\r\n    ll get_hash(int k, int l, int r)\
    \ { return (rhash[k][r] - rhash[k][l] * powb[k][r - l] % MODS[k] + MODS[k]) %\
    \ MODS[k]; }\r\n\r\n    bool match(int l1, int r1, int l2, int r2) {\r\n     \
    \   bool res = true;\r\n        for (int k = 0; k < M; k++) {\r\n            res\
    \ &= get_hash(k, l1, r1) == get_hash(k, l2, r2);\r\n        }\r\n        return\
    \ res;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/rolling_hash.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structures/rolling_hash.cpp
layout: document
redirect_from:
- /library/src/data_structures/rolling_hash.cpp
- /library/src/data_structures/rolling_hash.cpp.html
title: src/data_structures/rolling_hash.cpp
---
