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
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"src/data_structures/RMQ.cpp\"\n/*\r\n\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728(RMQ)\r\n\u8A08\u7B97\u91CF(\u69CB\u7BC9) O(N)\r\n\u8A08\u7B97\u91CF\
    (\u30AF\u30A8\u30EA) O(log(N))\r\n\u533A\u9593\u5185\u306E\u6700\u5C0F\u5024\u3092\
    \u6C42\u3081\u308B\r\nk\u756A\u76EE\u306E\u5024\u3092\u66F4\u65B0\u3059\u308B\r\
    \n*/\r\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n// BEGIN\r\
    \nstruct SegmentTree {\r\n    int N;\r\n    vector<int> node;\r\n    const int\
    \ INF = INT_MAX;\r\n\r\n    SegmentTree(){}\r\n    SegmentTree(int n_){\r\n  \
    \      init(n_);\r\n    }\r\n\r\n    void init(int siz){\r\n        N = 1;\r\n\
    \        while (N < siz) N *= 2;  // \u6700\u4E0B\u6BB5\u306E\u8981\u7D20\u6570\
    \u30922\u306E\u3079\u304D\u4E57\u306B\u3059\u308B\r\n        node.resize(2*N-1,\
    \ INF);\r\n    }\r\n\r\n    void build(vector<int> &dat){\r\n        int siz =\
    \ dat.size();\r\n        for(int i=0; i<siz; i++){\r\n            node[i+N-1]\
    \ = dat[i];\r\n        }\r\n        for(int i=N-2; i>=0; i--){  // \u6700\u4E0B\
    \u6BB5\u306B\u5024\u3092\u5165\u308C\u305F\u3042\u3068\u4E0B\u304B\u3089\u9806\
    \u306B\u66F4\u65B0\r\n            node[i] = min(node[2*i+1], node[2*i+2]);\r\n\
    \        }\r\n    }\r\n\r\n    void update(int k, int a) {\r\n        k += N -\
    \ 1; // \u6700\u4E0B\u6BB5\u6700\u5DE6\u306E\u7BC0\u70B9\u306E\u756A\u53F7\r\n\
    \        node[k] = a;\r\n        while (k > 0) { //\u767B\u308A\u306A\u304C\u3089\
    \u4E0A\u306E\u8981\u7D20\u3092\u66F4\u65B0\r\n            k = (k-1)/2;\r\n   \
    \         node[k] = min(node[k*2+1], node[k*2+2]);\r\n        }\r\n    }\r\n \
    \   /*\r\n    [a,b)\u306E\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\r\n    \u5916\
    \u304B\u3089\u306FgetMin(a,b)\u3067\u547C\u3076\r\n    k\u306F\u7BC0\u70B9\u306E\
    \u756A\u53F7\u3001l,r\u306F\u305D\u306Ek\u756A\u76EE\u306E\u7BC0\u70B9\u306E\u533A\
    \u9593\u3092\u8868\u3059\r\n    */\r\n    int getMin(int a, int b) {return getMin(a,\
    \ b, 0, 0, N);}\r\n    int getMin(int a, int b, int k, int l, int r) {\r\n   \
    \     if (r <= a || b <= l)\r\n            return INF;  //[a,b)\u3068[l,r)\u306B\
    \u5171\u901A\u533A\u9593\u304C\u306A\u3044\u306A\u3089INF\r\n        if (a <=\
    \ l && r <= b)\r\n            return node[k];  //[a,b)\u304C[l,r)\u3092\u5B8C\u5168\
    \u306B\u542B\u3080\u306A\u3089\u305D\u306E\u7BC0\u70B9k\u306E\u5024\r\n      \
    \  else {\r\n            int vl = getMin(a, b, k*2+1, l, (l+r)/2);\r\n       \
    \     int vr = getMin(a, b, k*2+2, (l+r)/2, r);\r\n            return min(vl,\
    \ vr);\r\n        }\r\n    }\r\n};\r\n// END\r\n\r\n// varified\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\r\
    \nint main() {\r\n    int n, q;\r\n    cin >> n >> q;\r\n    SegmentTree rmq;\r\
    \n    rmq.init(n);\r\n    for(int i=0;i<q;i++){\r\n        int a, b, c;\r\n  \
    \      cin >> a >> b >> c;\r\n        if(a) cout << rmq.getMin(b, c+1) << endl;\r\
    \n        else rmq.update(b, c);\r\n    }\r\n    return 0;\r\n}\r\n"
  code: "/*\r\n\u30BB\u30B0\u30E1\u30F3\u30C8\u6728(RMQ)\r\n\u8A08\u7B97\u91CF(\u69CB\
    \u7BC9) O(N)\r\n\u8A08\u7B97\u91CF(\u30AF\u30A8\u30EA) O(log(N))\r\n\u533A\u9593\
    \u5185\u306E\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\r\nk\u756A\u76EE\u306E\u5024\
    \u3092\u66F4\u65B0\u3059\u308B\r\n*/\r\n\r\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\n// BEGIN\r\nstruct SegmentTree {\r\n    int N;\r\n   \
    \ vector<int> node;\r\n    const int INF = INT_MAX;\r\n\r\n    SegmentTree(){}\r\
    \n    SegmentTree(int n_){\r\n        init(n_);\r\n    }\r\n\r\n    void init(int\
    \ siz){\r\n        N = 1;\r\n        while (N < siz) N *= 2;  // \u6700\u4E0B\u6BB5\
    \u306E\u8981\u7D20\u6570\u30922\u306E\u3079\u304D\u4E57\u306B\u3059\u308B\r\n\
    \        node.resize(2*N-1, INF);\r\n    }\r\n\r\n    void build(vector<int> &dat){\r\
    \n        int siz = dat.size();\r\n        for(int i=0; i<siz; i++){\r\n     \
    \       node[i+N-1] = dat[i];\r\n        }\r\n        for(int i=N-2; i>=0; i--){\
    \  // \u6700\u4E0B\u6BB5\u306B\u5024\u3092\u5165\u308C\u305F\u3042\u3068\u4E0B\
    \u304B\u3089\u9806\u306B\u66F4\u65B0\r\n            node[i] = min(node[2*i+1],\
    \ node[2*i+2]);\r\n        }\r\n    }\r\n\r\n    void update(int k, int a) {\r\
    \n        k += N - 1; // \u6700\u4E0B\u6BB5\u6700\u5DE6\u306E\u7BC0\u70B9\u306E\
    \u756A\u53F7\r\n        node[k] = a;\r\n        while (k > 0) { //\u767B\u308A\
    \u306A\u304C\u3089\u4E0A\u306E\u8981\u7D20\u3092\u66F4\u65B0\r\n            k\
    \ = (k-1)/2;\r\n            node[k] = min(node[k*2+1], node[k*2+2]);\r\n     \
    \   }\r\n    }\r\n    /*\r\n    [a,b)\u306E\u6700\u5C0F\u5024\u3092\u6C42\u3081\
    \u308B\r\n    \u5916\u304B\u3089\u306FgetMin(a,b)\u3067\u547C\u3076\r\n    k\u306F\
    \u7BC0\u70B9\u306E\u756A\u53F7\u3001l,r\u306F\u305D\u306Ek\u756A\u76EE\u306E\u7BC0\
    \u70B9\u306E\u533A\u9593\u3092\u8868\u3059\r\n    */\r\n    int getMin(int a,\
    \ int b) {return getMin(a, b, 0, 0, N);}\r\n    int getMin(int a, int b, int k,\
    \ int l, int r) {\r\n        if (r <= a || b <= l)\r\n            return INF;\
    \  //[a,b)\u3068[l,r)\u306B\u5171\u901A\u533A\u9593\u304C\u306A\u3044\u306A\u3089\
    INF\r\n        if (a <= l && r <= b)\r\n            return node[k];  //[a,b)\u304C\
    [l,r)\u3092\u5B8C\u5168\u306B\u542B\u3080\u306A\u3089\u305D\u306E\u7BC0\u70B9\
    k\u306E\u5024\r\n        else {\r\n            int vl = getMin(a, b, k*2+1, l,\
    \ (l+r)/2);\r\n            int vr = getMin(a, b, k*2+2, (l+r)/2, r);\r\n     \
    \       return min(vl, vr);\r\n        }\r\n    }\r\n};\r\n// END\r\n\r\n// varified\r\
    \n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\r\nint main()\
    \ {\r\n    int n, q;\r\n    cin >> n >> q;\r\n    SegmentTree rmq;\r\n    rmq.init(n);\r\
    \n    for(int i=0;i<q;i++){\r\n        int a, b, c;\r\n        cin >> a >> b >>\
    \ c;\r\n        if(a) cout << rmq.getMin(b, c+1) << endl;\r\n        else rmq.update(b,\
    \ c);\r\n    }\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/RMQ.cpp
  requiredBy: []
  timestamp: '2019-05-27 15:19:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structures/RMQ.cpp
layout: document
redirect_from:
- /library/src/data_structures/RMQ.cpp
- /library/src/data_structures/RMQ.cpp.html
title: src/data_structures/RMQ.cpp
---
