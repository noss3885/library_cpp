---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/segmenttree.cpp
    title: src/data_structures/segmenttree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL_2_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n#include <climits>\n#include <iostream>\n#line 1 \"src/data_structures/segmenttree.cpp\"\
    \n#include <functional>\n#include <vector>\n\ntemplate <typename Monoid>\nstruct\
    \ SegmentTree {\n  private:\n    using F = std::function<Monoid(Monoid, Monoid)>;\n\
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
    \    }\n};\n#line 5 \"test/aoj/DSL_2_A.test.cpp\"\n\nint main() {\n    auto f\
    \ = [=](int a, int b) { return std::min(a, b); };\n    SegmentTree<int> seg(f,\
    \ INT_MAX);\n    int n, q;\n    std::cin >> n >> q;\n    seg.init(n);\n    for\
    \ (int i = 0; i < q; i++) {\n        int c, x, y;\n        std::cin >> c >> x\
    \ >> y;\n        if (c) {\n            std::cout << seg.query(x, y + 1) << std::endl;\n\
    \        } else {\n            seg.update(x, y);\n        }\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n#include <climits>\n#include <iostream>\n#include \"../../src/data_structures/segmenttree.cpp\"\
    \n\nint main() {\n    auto f = [=](int a, int b) { return std::min(a, b); };\n\
    \    SegmentTree<int> seg(f, INT_MAX);\n    int n, q;\n    std::cin >> n >> q;\n\
    \    seg.init(n);\n    for (int i = 0; i < q; i++) {\n        int c, x, y;\n \
    \       std::cin >> c >> x >> y;\n        if (c) {\n            std::cout << seg.query(x,\
    \ y + 1) << std::endl;\n        } else {\n            seg.update(x, y);\n    \
    \    }\n    }\n    return 0;\n}"
  dependsOn:
  - src/data_structures/segmenttree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.test.cpp
- /verify/test/aoj/DSL_2_A.test.cpp.html
title: test/aoj/DSL_2_A.test.cpp
---
