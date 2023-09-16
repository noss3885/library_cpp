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
  bundledCode: "#line 1 \"src/math/fibonacci_matrix.cpp\"\n/*\r\nfibonacci with matrix\r\
    \nO(logN)\r\n*/\r\n\r\n#include <iostream>\r\n#include <vector>\r\nusing namespace\
    \ std;\r\n\r\ntypedef long long ll;\r\ntypedef vector<vector<ll> > mat;\r\nconst\
    \ ll MOD = ll(1e9 + 7);\r\n\r\nmat init(mat m, int xlen, int ylen) {\r\n    m.resize(xlen);\r\
    \n    for (int i = 0; i < xlen; i++) {\r\n        m[i].resize(ylen);\r\n     \
    \   for (int j = 0; j < ylen; j++) {\r\n            m[i][j] = 0;\r\n        }\r\
    \n    }\r\n    return m;\r\n}\r\n\r\nmat mul(mat a, mat b) {\r\n    mat c;\r\n\
    \    c = init(c, a.size(), b[0].size());\r\n    for (int i = 0; i < a.size();\
    \ i++) {\r\n        for (int k = 0; k < b.size(); k++) {\r\n            for (int\
    \ j = 0; j < b[0].size(); j++) {\r\n                c[i][j] = (c[i][j] + a[i][k]\
    \ * b[k][j]) % MOD;\r\n            }\r\n        }\r\n    }\r\n    return c;\r\n\
    }\r\n\r\nmat pow(mat a, ll n) {\r\n    mat b;\r\n    b = init(b, a.size(), a.size());\r\
    \n    for (int i = 0; i < a.size(); i++) {\r\n        b[i][i] = 1;\r\n    }\r\n\
    \    while (n > 0) {\r\n        if (n & 1) b = mul(a, b);\r\n        a = mul(a,\
    \ a);\r\n        n >>= 1;\r\n    }\r\n    return b;\r\n}\r\n\r\nll fibo(ll n)\
    \ {\r\n    mat a;\r\n    a.resize(2);\r\n    a[0].resize(2);\r\n    a[1].resize(2);\r\
    \n    a[0][0] = 1;\r\n    a[0][1] = 1;\r\n    a[1][0] = 1;\r\n    a[1][1] = 0;\r\
    \n    a = pow(a, n);\r\n    return a[0][0] % MOD;\r\n}\r\n\r\n//--test--//\r\n\
    \r\nint main() {\r\n    ll n;\r\n    cin >> n;\r\n    cout << fibo(n) << endl;\r\
    \n    return 0;\r\n}\r\n"
  code: "/*\r\nfibonacci with matrix\r\nO(logN)\r\n*/\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\nusing namespace std;\r\n\r\ntypedef long long ll;\r\ntypedef\
    \ vector<vector<ll> > mat;\r\nconst ll MOD = ll(1e9 + 7);\r\n\r\nmat init(mat\
    \ m, int xlen, int ylen) {\r\n    m.resize(xlen);\r\n    for (int i = 0; i < xlen;\
    \ i++) {\r\n        m[i].resize(ylen);\r\n        for (int j = 0; j < ylen; j++)\
    \ {\r\n            m[i][j] = 0;\r\n        }\r\n    }\r\n    return m;\r\n}\r\n\
    \r\nmat mul(mat a, mat b) {\r\n    mat c;\r\n    c = init(c, a.size(), b[0].size());\r\
    \n    for (int i = 0; i < a.size(); i++) {\r\n        for (int k = 0; k < b.size();\
    \ k++) {\r\n            for (int j = 0; j < b[0].size(); j++) {\r\n          \
    \      c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;\r\n            }\r\n   \
    \     }\r\n    }\r\n    return c;\r\n}\r\n\r\nmat pow(mat a, ll n) {\r\n    mat\
    \ b;\r\n    b = init(b, a.size(), a.size());\r\n    for (int i = 0; i < a.size();\
    \ i++) {\r\n        b[i][i] = 1;\r\n    }\r\n    while (n > 0) {\r\n        if\
    \ (n & 1) b = mul(a, b);\r\n        a = mul(a, a);\r\n        n >>= 1;\r\n   \
    \ }\r\n    return b;\r\n}\r\n\r\nll fibo(ll n) {\r\n    mat a;\r\n    a.resize(2);\r\
    \n    a[0].resize(2);\r\n    a[1].resize(2);\r\n    a[0][0] = 1;\r\n    a[0][1]\
    \ = 1;\r\n    a[1][0] = 1;\r\n    a[1][1] = 0;\r\n    a = pow(a, n);\r\n    return\
    \ a[0][0] % MOD;\r\n}\r\n\r\n//--test--//\r\n\r\nint main() {\r\n    ll n;\r\n\
    \    cin >> n;\r\n    cout << fibo(n) << endl;\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/fibonacci_matrix.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/fibonacci_matrix.cpp
layout: document
redirect_from:
- /library/src/math/fibonacci_matrix.cpp
- /library/src/math/fibonacci_matrix.cpp.html
title: src/math/fibonacci_matrix.cpp
---
