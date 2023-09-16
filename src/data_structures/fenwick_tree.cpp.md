---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B_fenwick.test.cpp
    title: test/aoj/DSL_2_B_fenwick.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data_structures/fenwick_tree.cpp\"\n#include <vector>\r\
    \n\r\ntemplate <typename T>\r\nstruct FenwickTree {\r\n    int len;\r\n    std::vector<T>\
    \ node;\r\n\r\n    FenwickTree() = default;\r\n    FenwickTree(int n) : len(n),\
    \ node(n, 0) {}\r\n    void init(int n) {\r\n        len = n;\r\n        node.assign(n,\
    \ 0);\r\n    }\r\n    // sum data[0,i)\r\n    T sum(int i) {\r\n        T res(0);\r\
    \n        for (int k = i; k > 0; k -= k & -k) {\r\n            res += node[k -\
    \ 1];\r\n        }\r\n        return res;\r\n    }\r\n    // add x to data[i]\r\
    \n    void add(int i, T x) {\r\n        for (int k = i + 1; k <= len; k += k &\
    \ -k) {\r\n            node[k - 1] += x;\r\n        }\r\n    }\r\n};\n"
  code: "#include <vector>\r\n\r\ntemplate <typename T>\r\nstruct FenwickTree {\r\n\
    \    int len;\r\n    std::vector<T> node;\r\n\r\n    FenwickTree() = default;\r\
    \n    FenwickTree(int n) : len(n), node(n, 0) {}\r\n    void init(int n) {\r\n\
    \        len = n;\r\n        node.assign(n, 0);\r\n    }\r\n    // sum data[0,i)\r\
    \n    T sum(int i) {\r\n        T res(0);\r\n        for (int k = i; k > 0; k\
    \ -= k & -k) {\r\n            res += node[k - 1];\r\n        }\r\n        return\
    \ res;\r\n    }\r\n    // add x to data[i]\r\n    void add(int i, T x) {\r\n \
    \       for (int k = i + 1; k <= len; k += k & -k) {\r\n            node[k - 1]\
    \ += x;\r\n        }\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/fenwick_tree.cpp
  requiredBy: []
  timestamp: '2023-09-16 12:24:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B_fenwick.test.cpp
documentation_of: src/data_structures/fenwick_tree.cpp
layout: document
redirect_from:
- /library/src/data_structures/fenwick_tree.cpp
- /library/src/data_structures/fenwick_tree.cpp.html
title: src/data_structures/fenwick_tree.cpp
---
