---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/lazy_segmenttree.cpp
    title: src/data_structures/lazy_segmenttree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
  bundledCode: "#line 1 \"test/aoj/DSL_2_I.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n#include <climits>\n#include <iostream>\n#line 1 \"src/data_structures/lazy_segmenttree.cpp\"\
    \n#include <functional>\n#include <vector>\n\ntemplate <typename Monoid, typename\
    \ OperatorMonoid>\nstruct LazySegmentTree {\n  private:\n    using F = std::function<Monoid(Monoid,\
    \ Monoid)>;                          // \u8981\u7D20\u3068\u8981\u7D20\u3092\u7D50\
    \u5408\u3055\u305B\u308B\u95A2\u6570\n    using G = std::function<Monoid(Monoid,\
    \ OperatorMonoid)>;                  // \u8981\u7D20\u306B\u4F5C\u7528\u7D20\u3092\
    \u4F5C\u7528\u3055\u305B\u308B\u95A2\u6570\n    using H = std::function<OperatorMonoid(OperatorMonoid,\
    \ OperatorMonoid)>;  // \u4F5C\u7528\u7D20\u3068\u4F5C\u7528\u7D20\u3092\u7D50\
    \u5408\u3055\u305B\u308B\u95A2\u6570\n    using P = std::function<OperatorMonoid(OperatorMonoid,\
    \ int)>;             // \u4F5C\u7528\u7D20\u3092\u4F5C\u7528\u3055\u305B\u308B\
    \u533A\u9593\u306E\u9577\u3055\u306B\u3088\u3063\u3066\u5909\u5316\u3055\u305B\
    \u308B\u95A2\u6570\n    int N;\n    std::vector<Monoid> node;\n    std::vector<OperatorMonoid>\
    \ lazy;\n    F f;\n    G g;\n    H h;\n    P p;\n    Monoid e;           // identity\
    \ element\n    OperatorMonoid oe;  // identity element\n\n  public:\n    LazySegmentTree()\
    \ {}\n    LazySegmentTree(\n        F f,\n        G g,\n        H h,\n       \
    \ Monoid e,\n        OperatorMonoid oe,\n        P p = [](OperatorMonoid a, int\
    \ b) { return a; }) : f(f), g(g), h(h), e(e), oe(oe), p(p) {}\n    void init(int\
    \ sz) {\n        N = 1;\n        while (N < sz) N <<= 1;\n        node.assign(2\
    \ * N - 1, e);\n        lazy.assign(2 * N - 1, oe);\n    }\n    void build(std::vector<Monoid>&\
    \ v) {\n        int sz = int(v.size());\n        init(sz);\n        for (int i\
    \ = 0; i < sz; i++) {\n            node[i + N - 1] = v[i];\n        }\n      \
    \  for (int i = N - 2; i >= 0; i--) {\n            node[i] = f(node[i * 2 + 1],\
    \ node[i * 2 + 2]);\n        }\n    }\n    void eval(int k, int len) {\n     \
    \   if (lazy[k] != oe) {\n            node[k] = g(node[k], p(lazy[k], len));\n\
    \            if (k < N - 1) {\n                lazy[2 * k + 1] = h(lazy[2 * k\
    \ + 1], lazy[k]);\n                lazy[2 * k + 2] = h(lazy[2 * k + 2], lazy[k]);\n\
    \            }\n            lazy[k] = oe;\n        }\n    }\n    Monoid update(int\
    \ a, int b, OperatorMonoid x) { return update(a, b, x, 0, 0, N); }\n    Monoid\
    \ update(int a, int b, OperatorMonoid x, int k, int l, int r) {\n        eval(k,\
    \ r - l);\n        if (b <= l || r <= a) return node[k];\n        if (a <= l &&\
    \ r <= b) {\n            lazy[k] = h(lazy[k], x);\n            return g(node[k],\
    \ p(lazy[k], r - l));\n        }\n        return node[k] = f(update(a, b, x, 2\
    \ * k + 1, l, (l + r) / 2), update(a, b, x, k * 2 + 2, (l + r) / 2, r));\n   \
    \ }\n    // [a,b)\n    Monoid query(int a, int b) { return query(a, b, 0, 0, N);\
    \ }\n    Monoid query(int a, int b, int k, int l, int r) {\n        eval(k, r\
    \ - l);\n        if (b <= l || r <= a) return e;\n        if (a <= l && r <= b)\
    \ return node[k];\n        Monoid vl, vr;\n        vl = query(a, b, 2 * k + 1,\
    \ l, (l + r) / 2);\n        vr = query(a, b, 2 * k + 2, (l + r) / 2, r);\n   \
    \     return f(vl, vr);\n    }\n};\n#line 5 \"test/aoj/DSL_2_I.test.cpp\"\n\n\
    using ll = long long int;\n\n// RSQ & RUQ\nint main() {\n    int n, q;\n    ll\
    \ INF = INT_MAX;\n    std::cin >> n >> q;\n    auto f = [=](ll a, ll b) { return\
    \ a + b; };\n    auto g = [=](ll a, ll b) { return (b != INF ? b : a); };\n  \
    \  auto p = [=](ll a, int b) { return a * b; };\n    LazySegmentTree<ll, ll> seg(f,\
    \ g, g, 0, INF, p);\n    seg.init(n);\n    for (int i = 0; i < q; i++) {\n   \
    \     int c, s, t;\n        std::cin >> c >> s >> t;\n        if (c == 0) {\n\
    \            ll x;\n            std::cin >> x;\n            seg.update(s, t +\
    \ 1, x);\n        } else {\n            std::cout << seg.query(s, t + 1) << std::endl;\n\
    \        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n#include <climits>\n#include <iostream>\n#include \"../../src/data_structures/lazy_segmenttree.cpp\"\
    \n\nusing ll = long long int;\n\n// RSQ & RUQ\nint main() {\n    int n, q;\n \
    \   ll INF = INT_MAX;\n    std::cin >> n >> q;\n    auto f = [=](ll a, ll b) {\
    \ return a + b; };\n    auto g = [=](ll a, ll b) { return (b != INF ? b : a);\
    \ };\n    auto p = [=](ll a, int b) { return a * b; };\n    LazySegmentTree<ll,\
    \ ll> seg(f, g, g, 0, INF, p);\n    seg.init(n);\n    for (int i = 0; i < q; i++)\
    \ {\n        int c, s, t;\n        std::cin >> c >> s >> t;\n        if (c ==\
    \ 0) {\n            ll x;\n            std::cin >> x;\n            seg.update(s,\
    \ t + 1, x);\n        } else {\n            std::cout << seg.query(s, t + 1) <<\
    \ std::endl;\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - src/data_structures/lazy_segmenttree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_I.test.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_I.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_I.test.cpp
- /verify/test/aoj/DSL_2_I.test.cpp.html
title: test/aoj/DSL_2_I.test.cpp
---
