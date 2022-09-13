---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/BIT.cpp
    title: src/data_structures/BIT.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B_BIT.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n#include <iostream>\n#line 1 \"src/data_structures/BIT.cpp\"\n#include <vector>\r\
    \n\r\ntemplate <typename T>\r\nstruct BIT {\r\n    int N;\r\n    std::vector<T>\
    \ bit;\r\n\r\n    BIT() = default;\r\n    BIT(int n) {init(n);}\r\n    void init(int\
    \ n){\r\n        N = n;\r\n        bit.assign(n+1, 0);\r\n    }\r\n    T getSum(int\
    \ i) {  // i\u756A\u76EE\u307E\u3067\u306E\u8981\u7D20\u306E\u548C\u3092\u6C42\
    \u3081\u308B(1-index)\r\n        T sum = 0;\r\n        while (i > 0) {\r\n   \
    \         sum += bit[i];\r\n            i -= i & -i;\r\n        }\r\n        return\
    \ sum;\r\n    }\r\n    void add(int i, T x) {  // i\u756A\u76EE\u306E\u8981\u7D20\
    \u306Bx\u3092\u52A0\u7B97\r\n        while (i <= N) {\r\n            bit[i] +=\
    \ x;\r\n            i += i & -i;\r\n        }\r\n    }\r\n};\n#line 4 \"test/aoj/DSL_2_B_BIT.test.cpp\"\
    \n\nusing ll = long long int;\n\nint main() {\n    int n, q;\n    std::cin >>\
    \ n >> q;\n    BIT<ll> bit(n);\n    for(int i=0; i<q; i++){\n        ll c, x,\
    \ y;\n        std::cin >> c >> x >> y;\n        if(c){\n            std::cout\
    \ << bit.getSum(y) - bit.getSum(x-1) << std::endl;\n        }else{\n         \
    \   bit.add(x,y);\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n#include <iostream>\n#include \"../../src/data_structures/BIT.cpp\"\n\nusing\
    \ ll = long long int;\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    BIT<ll> bit(n);\n    for(int i=0; i<q; i++){\n        ll c, x, y;\n     \
    \   std::cin >> c >> x >> y;\n        if(c){\n            std::cout << bit.getSum(y)\
    \ - bit.getSum(x-1) << std::endl;\n        }else{\n            bit.add(x,y);\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn:
  - src/data_structures/BIT.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B_BIT.test.cpp
  requiredBy: []
  timestamp: '2020-04-16 22:56:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B_BIT.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B_BIT.test.cpp
- /verify/test/aoj/DSL_2_B_BIT.test.cpp.html
title: test/aoj/DSL_2_B_BIT.test.cpp
---
