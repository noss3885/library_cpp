---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graphs/lowest_common_ancestor.cpp
    title: src/graphs/lowest_common_ancestor.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667.test.cpp
    title: test/aoj/2667.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data_structures/segmenttree.cpp\"\n#include <functional>\n\
    #include <vector>\n\ntemplate <typename Monoid>\nstruct SegmentTree {\n  private:\n\
    \    using F = std::function<Monoid(Monoid, Monoid)>;\n    int N;\n    std::vector<Monoid>\
    \ node;\n    F f;\n    Monoid e;  // identity element\n\n  public:\n    SegmentTree()\
    \ {}\n    SegmentTree(F f, Monoid e) : f(f), e(e) {}\n    void init(int sz) {\n\
    \        N = 1;\n        while (N < sz) N <<= 1;\n        node.assign(2 * N -\
    \ 1, e);\n    }\n    void build(std::vector<Monoid>& v) {\n        int sz = int(v.size());\n\
    \        init(sz);\n        for (int i = 0; i < sz; i++) {\n            node[i\
    \ + N - 1] = v[i];\n        }\n        for (int i = N - 2; i >= 0; i--) {\n  \
    \          node[i] = f(node[i * 2 + 1], node[i * 2 + 2]);\n        }\n    }\n\
    \    void update(int k, Monoid x) {\n        k += N - 1;\n        node[k] = x;\n\
    \        while (k > 0) {\n            k = (k - 1) / 2;\n            node[k] =\
    \ f(node[2 * k + 1], node[2 * k + 2]);\n        }\n    }\n    // [a,b)\n    Monoid\
    \ query(int a, int b) { return query(a, b, 0, 0, N); }\n    Monoid query(int a,\
    \ int b, int k, int l, int r) {\n        if (b <= l || r <= a) return e;\n   \
    \     if (a <= l && r <= b) return node[k];\n        Monoid vl, vr;\n        vl\
    \ = query(a, b, 2 * k + 1, l, (l + r) / 2);\n        vr = query(a, b, 2 * k +\
    \ 2, (l + r) / 2, r);\n        return f(vl, vr);\n    }\n};\n"
  code: "#include <functional>\n#include <vector>\n\ntemplate <typename Monoid>\n\
    struct SegmentTree {\n  private:\n    using F = std::function<Monoid(Monoid, Monoid)>;\n\
    \    int N;\n    std::vector<Monoid> node;\n    F f;\n    Monoid e;  // identity\
    \ element\n\n  public:\n    SegmentTree() {}\n    SegmentTree(F f, Monoid e) :\
    \ f(f), e(e) {}\n    void init(int sz) {\n        N = 1;\n        while (N < sz)\
    \ N <<= 1;\n        node.assign(2 * N - 1, e);\n    }\n    void build(std::vector<Monoid>&\
    \ v) {\n        int sz = int(v.size());\n        init(sz);\n        for (int i\
    \ = 0; i < sz; i++) {\n            node[i + N - 1] = v[i];\n        }\n      \
    \  for (int i = N - 2; i >= 0; i--) {\n            node[i] = f(node[i * 2 + 1],\
    \ node[i * 2 + 2]);\n        }\n    }\n    void update(int k, Monoid x) {\n  \
    \      k += N - 1;\n        node[k] = x;\n        while (k > 0) {\n          \
    \  k = (k - 1) / 2;\n            node[k] = f(node[2 * k + 1], node[2 * k + 2]);\n\
    \        }\n    }\n    // [a,b)\n    Monoid query(int a, int b) { return query(a,\
    \ b, 0, 0, N); }\n    Monoid query(int a, int b, int k, int l, int r) {\n    \
    \    if (b <= l || r <= a) return e;\n        if (a <= l && r <= b) return node[k];\n\
    \        Monoid vl, vr;\n        vl = query(a, b, 2 * k + 1, l, (l + r) / 2);\n\
    \        vr = query(a, b, 2 * k + 2, (l + r) / 2, r);\n        return f(vl, vr);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/segmenttree.cpp
  requiredBy:
  - src/graphs/lowest_common_ancestor.cpp
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2667.test.cpp
  - test/aoj/DSL_2_A.test.cpp
  - test/aoj/GRL_5_C.test.cpp
documentation_of: src/data_structures/segmenttree.cpp
layout: document
redirect_from:
- /library/src/data_structures/segmenttree.cpp
- /library/src/data_structures/segmenttree.cpp.html
title: src/data_structures/segmenttree.cpp
---
