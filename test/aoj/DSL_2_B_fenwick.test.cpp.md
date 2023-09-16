---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/fenwick_tree.cpp
    title: src/data_structures/fenwick_tree.cpp
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
  bundledCode: "#line 1 \"test/aoj/DSL_2_B_fenwick.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\n#include <iostream>\n\
    #line 1 \"src/data_structures/fenwick_tree.cpp\"\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nstruct FenwickTree {\r\n    int len;\r\n    std::vector<T> node;\r\
    \n\r\n    FenwickTree() = default;\r\n    FenwickTree(int n) : len(n), node(n,\
    \ 0) {}\r\n    void init(int n) {\r\n        len = n;\r\n        node.assign(n,\
    \ 0);\r\n    }\r\n    // sum data[0,i)\r\n    T sum(int i) {\r\n        T res(0);\r\
    \n        for (int k = i; k > 0; k -= k & -k) {\r\n            res += node[k -\
    \ 1];\r\n        }\r\n        return res;\r\n    }\r\n    // add x to data[i]\r\
    \n    void add(int i, T x) {\r\n        for (int k = i + 1; k <= len; k += k &\
    \ -k) {\r\n            node[k - 1] += x;\r\n        }\r\n    }\r\n};\n#line 4\
    \ \"test/aoj/DSL_2_B_fenwick.test.cpp\"\n\nusing ll = long long int;\n\nint main()\
    \ {\n    int n, q;\n    std::cin >> n >> q;\n    FenwickTree<ll> fenwick(n);\n\
    \    for (int i = 0; i < q; i++) {\n        ll c, x, y;\n        std::cin >> c\
    \ >> x >> y;\n        if (c) {\n            std::cout << fenwick.sum(y) - fenwick.sum(x\
    \ - 1) << std::endl;\n        } else {\n            fenwick.add(x - 1, y);\n \
    \       }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n#include <iostream>\n#include \"../../src/data_structures/fenwick_tree.cpp\"\
    \n\nusing ll = long long int;\n\nint main() {\n    int n, q;\n    std::cin >>\
    \ n >> q;\n    FenwickTree<ll> fenwick(n);\n    for (int i = 0; i < q; i++) {\n\
    \        ll c, x, y;\n        std::cin >> c >> x >> y;\n        if (c) {\n   \
    \         std::cout << fenwick.sum(y) - fenwick.sum(x - 1) << std::endl;\n   \
    \     } else {\n            fenwick.add(x - 1, y);\n        }\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - src/data_structures/fenwick_tree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B_fenwick.test.cpp
  requiredBy: []
  timestamp: '2023-09-16 12:25:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B_fenwick.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B_fenwick.test.cpp
- /verify/test/aoj/DSL_2_B_fenwick.test.cpp.html
title: test/aoj/DSL_2_B_fenwick.test.cpp
---
