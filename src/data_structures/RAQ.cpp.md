---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"src/data_structures/RAQ.cpp\"\n#include <iostream>\r\n#include\
    \ <vector>\r\nusing namespace std;\r\n\r\ntemplate <typename Monoid>\r\nstruct\
    \ LazySegmentTree{\r\nprivate:\r\n    int N;\r\n    vector<Monoid> node, lazy;\r\
    \n\r\npublic:\r\n    LazySegmentTree(int sz = 0){\r\n        init(sz);\r\n   \
    \ }\r\n    void init(int sz){\r\n        N = 1;\r\n        while(N < sz) N <<=\
    \ 1;\r\n        node.resize(2*N-1,0);\r\n        lazy.resize(2*N-1,0);\r\n\r\n\
    \    }\r\n    void build(vector<Monoid>& v){\r\n        int sz = int(v.size());\r\
    \n        init(sz);\r\n        for(int i=0; i<sz; i++){\r\n            node[i+N-1]\
    \ = v[i];\r\n        }\r\n        for(int i=N-2; i>=0; i--){\r\n            node[i]\
    \ = node[i*2+1] + node[i*2+2];\r\n        }\r\n    }\r\n    // node[k]\r\n   \
    \ void eval(int k){\r\n        if(lazy[k] != 0){\r\n            node[k] += lazy[k];\r\
    \n            if(k < N-1){ // \u6700\u4E0B\u6BB5\u3067\u306A\u3044\u3068\u304D\
    \r\n                lazy[2*k+1] += lazy[k] / 2;\r\n                lazy[2*k+2]\
    \ += lazy[k] / 2;\r\n            }\r\n            lazy[k] = 0;\r\n        }\r\n\
    \    }\r\n    // [a,b)\r\n    void add(int a, int b, Monoid x){add(a, b, x, 0,\
    \ 0, N);}\r\n    void add(int a, int b, Monoid x, int k, int l, int r){\r\n  \
    \      if(b <= l || r <= a) return;\r\n        eval(k);\r\n        if(a <= l &&\
    \ r <= b){\r\n            lazy[k] += x * (r-l);\r\n        }\r\n        else{\r\
    \n            add(a, b, x, 2*k+1, l, (l+r)/2);\r\n            add(a, b, x, 2*k+2,\
    \ (l+r)/2, r);\r\n            node[k] = node[2*k+1] + node[2*k+2];\r\n       \
    \ }\r\n    }\r\n    // [a,b)\r\n    Monoid getSum(int a, int b){return getSum(a,\
    \ b, 0, 0, N);}\r\n    Monoid getSum(int a, int b, int k, int l, int r){\r\n \
    \       if(b <= l || r <= a) return 0;\r\n        eval(k);\r\n        if(a <=\
    \ l && r <= b) return node[k];\r\n        Monoid vl, vr;\r\n        vl = getSum(a,\
    \ b, 2*k+1, l, (l+r)/2);\r\n        vr = getSum(a, b, 2*k+2, (l+r)/2, r);\r\n\
    \        return vl + vr;\r\n    }\r\n};\r\n\r\n\r\n// varify\r\ntypedef long long\
    \ ll;\r\n\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\r\
    \nint main() {\r\n    int n, q;\r\n    cin >> n >> q;\r\n    LazySegmentTree<ll>\
    \ seg(n);\r\n    for(int i=0;i<q;i++){\r\n        int c;\r\n        cin >> c;\r\
    \n        if(c == 0){\r\n            ll s, t, x;\r\n            cin >> s >> t\
    \ >> x;\r\n            seg.add(s-1,t,x);\r\n        }\r\n        else{\r\n   \
    \         int s;\r\n            cin >> s;\r\n            cout << seg.getSum(s-1,s)\
    \ << endl;\r\n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#include <iostream>\r\n#include <vector>\r\nusing namespace std;\r\n\r\n\
    template <typename Monoid>\r\nstruct LazySegmentTree{\r\nprivate:\r\n    int N;\r\
    \n    vector<Monoid> node, lazy;\r\n\r\npublic:\r\n    LazySegmentTree(int sz\
    \ = 0){\r\n        init(sz);\r\n    }\r\n    void init(int sz){\r\n        N =\
    \ 1;\r\n        while(N < sz) N <<= 1;\r\n        node.resize(2*N-1,0);\r\n  \
    \      lazy.resize(2*N-1,0);\r\n\r\n    }\r\n    void build(vector<Monoid>& v){\r\
    \n        int sz = int(v.size());\r\n        init(sz);\r\n        for(int i=0;\
    \ i<sz; i++){\r\n            node[i+N-1] = v[i];\r\n        }\r\n        for(int\
    \ i=N-2; i>=0; i--){\r\n            node[i] = node[i*2+1] + node[i*2+2];\r\n \
    \       }\r\n    }\r\n    // node[k]\r\n    void eval(int k){\r\n        if(lazy[k]\
    \ != 0){\r\n            node[k] += lazy[k];\r\n            if(k < N-1){ // \u6700\
    \u4E0B\u6BB5\u3067\u306A\u3044\u3068\u304D\r\n                lazy[2*k+1] += lazy[k]\
    \ / 2;\r\n                lazy[2*k+2] += lazy[k] / 2;\r\n            }\r\n   \
    \         lazy[k] = 0;\r\n        }\r\n    }\r\n    // [a,b)\r\n    void add(int\
    \ a, int b, Monoid x){add(a, b, x, 0, 0, N);}\r\n    void add(int a, int b, Monoid\
    \ x, int k, int l, int r){\r\n        if(b <= l || r <= a) return;\r\n       \
    \ eval(k);\r\n        if(a <= l && r <= b){\r\n            lazy[k] += x * (r-l);\r\
    \n        }\r\n        else{\r\n            add(a, b, x, 2*k+1, l, (l+r)/2);\r\
    \n            add(a, b, x, 2*k+2, (l+r)/2, r);\r\n            node[k] = node[2*k+1]\
    \ + node[2*k+2];\r\n        }\r\n    }\r\n    // [a,b)\r\n    Monoid getSum(int\
    \ a, int b){return getSum(a, b, 0, 0, N);}\r\n    Monoid getSum(int a, int b,\
    \ int k, int l, int r){\r\n        if(b <= l || r <= a) return 0;\r\n        eval(k);\r\
    \n        if(a <= l && r <= b) return node[k];\r\n        Monoid vl, vr;\r\n \
    \       vl = getSum(a, b, 2*k+1, l, (l+r)/2);\r\n        vr = getSum(a, b, 2*k+2,\
    \ (l+r)/2, r);\r\n        return vl + vr;\r\n    }\r\n};\r\n\r\n\r\n// varify\r\
    \ntypedef long long ll;\r\n\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\r\
    \nint main() {\r\n    int n, q;\r\n    cin >> n >> q;\r\n    LazySegmentTree<ll>\
    \ seg(n);\r\n    for(int i=0;i<q;i++){\r\n        int c;\r\n        cin >> c;\r\
    \n        if(c == 0){\r\n            ll s, t, x;\r\n            cin >> s >> t\
    \ >> x;\r\n            seg.add(s-1,t,x);\r\n        }\r\n        else{\r\n   \
    \         int s;\r\n            cin >> s;\r\n            cout << seg.getSum(s-1,s)\
    \ << endl;\r\n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/RAQ.cpp
  requiredBy: []
  timestamp: '2019-05-27 15:28:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structures/RAQ.cpp
layout: document
redirect_from:
- /library/src/data_structures/RAQ.cpp
- /library/src/data_structures/RAQ.cpp.html
title: src/data_structures/RAQ.cpp
---
