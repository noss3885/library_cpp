---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/union_find_tree.cpp
    title: src/data_structures/union_find_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "#line 1 \"test/aoj/DSL_1_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n#include <iostream>\n#line 1 \"src/data_structures/union_find_tree.cpp\"\n#include\
    \ <utility>\r\n#include <vector>\r\n\r\nstruct UnionFindTree {\r\n    int N;\r\
    \n    std::vector<int> par;\r\n    std::vector<int> siz;\r\n\r\n    UnionFindTree()\
    \ = default;\r\n    UnionFindTree(int n) : N(n) { init(n); }\r\n    void init(int\
    \ n) {\r\n        par.resize(n);\r\n        siz.assign(n, 1);\r\n        for (int\
    \ i = 0; i < n; i++) {\r\n            par[i] = i;\r\n        }\r\n    }\r\n  \
    \  int root(int x) {\r\n        if (par[x] == x)\r\n            return x;\r\n\
    \        else\r\n            return par[x] = root(par[x]);\r\n    }\r\n    bool\
    \ unite(int x, int y) {\r\n        x = root(x);\r\n        y = root(y);\r\n  \
    \      if (x == y) return false;\r\n        if (siz[x] < siz[y]) std::swap(x,\
    \ y);\r\n        par[y] = x;\r\n        siz[x] += siz[y];\r\n        N--;\r\n\
    \        return true;\r\n    }\r\n    bool same(int x, int y) {\r\n        return\
    \ root(x) == root(y);\r\n    }\r\n    int size(int x) {\r\n        return siz[root(x)];\r\
    \n    }\r\n    int count() {\r\n        return N;\r\n    }\r\n};\n#line 4 \"test/aoj/DSL_1_A.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    UnionFindTree g(n);\n\
    \    for (int i = 0; i < q; i++) {\n        int c, x, y;\n        std::cin >>\
    \ c >> x >> y;\n        if (c) {\n            std::cout << (g.same(x, y) ? 1 :\
    \ 0) << std::endl;\n        } else {\n            g.unite(x, y);\n        }\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n#include <iostream>\n#include \"../../src/data_structures/union_find_tree.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    UnionFindTree g(n);\n\
    \    for (int i = 0; i < q; i++) {\n        int c, x, y;\n        std::cin >>\
    \ c >> x >> y;\n        if (c) {\n            std::cout << (g.same(x, y) ? 1 :\
    \ 0) << std::endl;\n        } else {\n            g.unite(x, y);\n        }\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - src/data_structures/union_find_tree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_A.test.cpp
- /verify/test/aoj/DSL_1_A.test.cpp.html
title: test/aoj/DSL_1_A.test.cpp
---
