---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data_structures/union_find_tree.cpp\"\n#include <utility>\r\
    \n#include <vector>\r\n\r\nstruct UnionFindTree {\r\n    int N;\r\n    std::vector<int>\
    \ par;\r\n    std::vector<int> siz;\r\n\r\n    UnionFindTree() = default;\r\n\
    \    UnionFindTree(int n) : N(n) {init(n);}\r\n    void init(int n) {\r\n    \
    \    par.resize(n);\r\n        siz.assign(n,1);\r\n        for (int i = 0; i <\
    \ n; i++) {\r\n            par[i] = i;\r\n        }\r\n    }\r\n    int root(int\
    \ x) {\r\n        if (par[x] == x) return x;\r\n        else return par[x] = root(par[x]);\r\
    \n    }\r\n    bool unite(int x, int y) {\r\n        x = root(x);\r\n        y\
    \ = root(y);\r\n        if (x == y) return false;\r\n        if (siz[x] < siz[y])\
    \ std::swap(x, y);\r\n        par[y] = x;\r\n        siz[x] += siz[y];\r\n   \
    \     N--;\r\n        return true;\r\n    }\r\n    bool same(int x, int y) {\r\
    \n        return root(x) == root(y);\r\n    }\r\n    int size(int x) {\r\n   \
    \     return siz[root(x)];\r\n    }\r\n    int count(){\r\n        return N;\r\
    \n    }\r\n};\n"
  code: "#include <utility>\r\n#include <vector>\r\n\r\nstruct UnionFindTree {\r\n\
    \    int N;\r\n    std::vector<int> par;\r\n    std::vector<int> siz;\r\n\r\n\
    \    UnionFindTree() = default;\r\n    UnionFindTree(int n) : N(n) {init(n);}\r\
    \n    void init(int n) {\r\n        par.resize(n);\r\n        siz.assign(n,1);\r\
    \n        for (int i = 0; i < n; i++) {\r\n            par[i] = i;\r\n       \
    \ }\r\n    }\r\n    int root(int x) {\r\n        if (par[x] == x) return x;\r\n\
    \        else return par[x] = root(par[x]);\r\n    }\r\n    bool unite(int x,\
    \ int y) {\r\n        x = root(x);\r\n        y = root(y);\r\n        if (x ==\
    \ y) return false;\r\n        if (siz[x] < siz[y]) std::swap(x, y);\r\n      \
    \  par[y] = x;\r\n        siz[x] += siz[y];\r\n        N--;\r\n        return\
    \ true;\r\n    }\r\n    bool same(int x, int y) {\r\n        return root(x) ==\
    \ root(y);\r\n    }\r\n    int size(int x) {\r\n        return siz[root(x)];\r\
    \n    }\r\n    int count(){\r\n        return N;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/union_find_tree.cpp
  requiredBy: []
  timestamp: '2020-04-16 22:41:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_1_A.test.cpp
documentation_of: src/data_structures/union_find_tree.cpp
layout: document
redirect_from:
- /library/src/data_structures/union_find_tree.cpp
- /library/src/data_structures/union_find_tree.cpp.html
title: src/data_structures/union_find_tree.cpp
---
