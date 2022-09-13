---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graphs/spanning_tree/!prim.cpp\"\n/*\r\n\u30D7\u30EA\
    \u30E0\u6CD5\r\n\u8A08\u7B97\u91CF O(V^2)\r\n\u8981\u6539\u5584\u30C0\u30A4\u30AF\
    \u30B9\u30C8\u30E9\u306E\u3088\u3046\u306Bpriority_queue\u3092\u7528\u3044\u308B\
    \r\n*/\r\n#include <algorithm>\r\n\r\nusing namespace std;\r\n\r\n#define MAX_V\
    \ 10000\r\n#define INF 99999999\r\n\r\nint cost[MAX_V][MAX_V]; //u-v\r\nint mincost[MAX_V];\r\
    \nbool used[MAX_V];\r\nint V;\r\n\r\nint prim(){\r\n   for(int i=0;i<V;i++){\r\
    \n      mincost[i] = INF;\r\n      used[i] = false;\r\n   }\r\n   mincost[0]=0;\r\
    \n   int res = 0;\r\n\r\n   while(true){\r\n      int v = -1;\r\n\r\n      for(int\
    \ u=0;u<V;u++){\r\n         if(!used[u] && (v==-1 || mincost[u] < mincost[v]))\r\
    \n            v = u;\r\n      }\r\n      if(v==-1)break;\r\n      used[v]=true;\r\
    \n      res += mincost[v];\r\n\r\n      for(int u=0; u<V; u++){\r\n         mincost[u]=min(mincost[u],cost[u][v]);\r\
    \n      }\r\n   }\r\n   return res;\r\n}\n"
  code: "/*\r\n\u30D7\u30EA\u30E0\u6CD5\r\n\u8A08\u7B97\u91CF O(V^2)\r\n\u8981\u6539\
    \u5584\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u306E\u3088\u3046\u306Bpriority_queue\u3092\
    \u7528\u3044\u308B\r\n*/\r\n#include <algorithm>\r\n\r\nusing namespace std;\r\
    \n\r\n#define MAX_V 10000\r\n#define INF 99999999\r\n\r\nint cost[MAX_V][MAX_V];\
    \ //u-v\r\nint mincost[MAX_V];\r\nbool used[MAX_V];\r\nint V;\r\n\r\nint prim(){\r\
    \n   for(int i=0;i<V;i++){\r\n      mincost[i] = INF;\r\n      used[i] = false;\r\
    \n   }\r\n   mincost[0]=0;\r\n   int res = 0;\r\n\r\n   while(true){\r\n     \
    \ int v = -1;\r\n\r\n      for(int u=0;u<V;u++){\r\n         if(!used[u] && (v==-1\
    \ || mincost[u] < mincost[v]))\r\n            v = u;\r\n      }\r\n      if(v==-1)break;\r\
    \n      used[v]=true;\r\n      res += mincost[v];\r\n\r\n      for(int u=0; u<V;\
    \ u++){\r\n         mincost[u]=min(mincost[u],cost[u][v]);\r\n      }\r\n   }\r\
    \n   return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/spanning_tree/!prim.cpp
  requiredBy: []
  timestamp: '2018-05-24 17:23:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/spanning_tree/!prim.cpp
layout: document
redirect_from:
- /library/src/graphs/spanning_tree/!prim.cpp
- /library/src/graphs/spanning_tree/!prim.cpp.html
title: src/graphs/spanning_tree/!prim.cpp
---
