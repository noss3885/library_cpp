---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B_BIT.test.cpp
    title: test/aoj/DSL_2_B_BIT.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data_structures/BIT.cpp\"\n#include <vector>\r\n\r\n\
    template <typename T>\r\nstruct BIT {\r\n    int N;\r\n    std::vector<T> bit;\r\
    \n\r\n    BIT() = default;\r\n    BIT(int n) {init(n);}\r\n    void init(int n){\r\
    \n        N = n;\r\n        bit.assign(n+1, 0);\r\n    }\r\n    T getSum(int i)\
    \ {  // i\u756A\u76EE\u307E\u3067\u306E\u8981\u7D20\u306E\u548C\u3092\u6C42\u3081\
    \u308B(1-index)\r\n        T sum = 0;\r\n        while (i > 0) {\r\n         \
    \   sum += bit[i];\r\n            i -= i & -i;\r\n        }\r\n        return\
    \ sum;\r\n    }\r\n    void add(int i, T x) {  // i\u756A\u76EE\u306E\u8981\u7D20\
    \u306Bx\u3092\u52A0\u7B97\r\n        while (i <= N) {\r\n            bit[i] +=\
    \ x;\r\n            i += i & -i;\r\n        }\r\n    }\r\n};\n"
  code: "#include <vector>\r\n\r\ntemplate <typename T>\r\nstruct BIT {\r\n    int\
    \ N;\r\n    std::vector<T> bit;\r\n\r\n    BIT() = default;\r\n    BIT(int n)\
    \ {init(n);}\r\n    void init(int n){\r\n        N = n;\r\n        bit.assign(n+1,\
    \ 0);\r\n    }\r\n    T getSum(int i) {  // i\u756A\u76EE\u307E\u3067\u306E\u8981\
    \u7D20\u306E\u548C\u3092\u6C42\u3081\u308B(1-index)\r\n        T sum = 0;\r\n\
    \        while (i > 0) {\r\n            sum += bit[i];\r\n            i -= i &\
    \ -i;\r\n        }\r\n        return sum;\r\n    }\r\n    void add(int i, T x)\
    \ {  // i\u756A\u76EE\u306E\u8981\u7D20\u306Bx\u3092\u52A0\u7B97\r\n        while\
    \ (i <= N) {\r\n            bit[i] += x;\r\n            i += i & -i;\r\n     \
    \   }\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/BIT.cpp
  requiredBy: []
  timestamp: '2020-04-16 22:56:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B_BIT.test.cpp
documentation_of: src/data_structures/BIT.cpp
layout: document
redirect_from:
- /library/src/data_structures/BIT.cpp
- /library/src/data_structures/BIT.cpp.html
title: src/data_structures/BIT.cpp
---
