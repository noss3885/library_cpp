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
  bundledCode: "#line 1 \"src/data_structures/rolling_hashing64.cpp\"\n/*\r\n\u30ED\
    \u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5(2^64)\r\n\u9023\u7D9A\u3059\u308B\
    \u90E8\u5206\u6587\u5B57\u5217\u306E\u6BD4\u8F03\u3092\u9AD8\u901F\u306B\u884C\
    \u3048\u308B\u3002\r\nunsigned long long \u3092\u4F7F\u3063\u3066\u3044\u308B\u306E\
    \u3067\r\n\u7C21\u6F54\u3067\u9AD8\u901F\u3060\u304C\u885D\u7A81\u304C\u8D77\u304D\
    \u3084\u3059\u3044\u3002\r\n\u69CB\u7BC9 O(N)\r\n\u5224\u5B9A O(1)\r\n*/\r\n\r\
    \n#include <string>\r\n#include <vector>\r\nusing namespace std;\r\n\r\ntypedef\
    \ long long ll;\r\ntypedef unsigned long long ull;\r\n\r\nvector<ull> powb, rhash;\r\
    \n\r\nvoid rolling_hash(string str, ull base = ull(1e9 + 7)) {\r\n    int N =\
    \ str.size();\r\n    powb.resize(N + 1);\r\n    rhash.resize(N + 1);\r\n    powb[0]\
    \ = 1;\r\n    rhash[0] = 0;\r\n    for (int i = 0; i < N; i++) {\r\n        rhash[i\
    \ + 1] = str[i] + rhash[i] * base;\r\n        powb[i + 1] = powb[i] * base;\r\n\
    \    }\r\n}\r\n\r\n//[l,r)\r\null get_hash(int l, int r) { return rhash[r] - rhash[l]\
    \ * powb[r - l]; }\r\n"
  code: "/*\r\n\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5(2^64)\r\n\u9023\
    \u7D9A\u3059\u308B\u90E8\u5206\u6587\u5B57\u5217\u306E\u6BD4\u8F03\u3092\u9AD8\
    \u901F\u306B\u884C\u3048\u308B\u3002\r\nunsigned long long \u3092\u4F7F\u3063\u3066\
    \u3044\u308B\u306E\u3067\r\n\u7C21\u6F54\u3067\u9AD8\u901F\u3060\u304C\u885D\u7A81\
    \u304C\u8D77\u304D\u3084\u3059\u3044\u3002\r\n\u69CB\u7BC9 O(N)\r\n\u5224\u5B9A\
    \ O(1)\r\n*/\r\n\r\n#include <string>\r\n#include <vector>\r\nusing namespace\
    \ std;\r\n\r\ntypedef long long ll;\r\ntypedef unsigned long long ull;\r\n\r\n\
    vector<ull> powb, rhash;\r\n\r\nvoid rolling_hash(string str, ull base = ull(1e9\
    \ + 7)) {\r\n    int N = str.size();\r\n    powb.resize(N + 1);\r\n    rhash.resize(N\
    \ + 1);\r\n    powb[0] = 1;\r\n    rhash[0] = 0;\r\n    for (int i = 0; i < N;\
    \ i++) {\r\n        rhash[i + 1] = str[i] + rhash[i] * base;\r\n        powb[i\
    \ + 1] = powb[i] * base;\r\n    }\r\n}\r\n\r\n//[l,r)\r\null get_hash(int l, int\
    \ r) { return rhash[r] - rhash[l] * powb[r - l]; }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/rolling_hashing64.cpp
  requiredBy: []
  timestamp: '2018-06-03 16:26:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structures/rolling_hashing64.cpp
layout: document
redirect_from:
- /library/src/data_structures/rolling_hashing64.cpp
- /library/src/data_structures/rolling_hashing64.cpp.html
title: src/data_structures/rolling_hashing64.cpp
---
