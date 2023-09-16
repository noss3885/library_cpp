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
  bundledCode: "#line 1 \"src/graphs/lowlink.cpp\"\n/*\nlowlink\n\u95A2\u7BC0\u70B9\
    \u3001\u6A4B\u3092\u6C42\u3081\u308B\nO(V+E)\n*/\n\n#include <bits/stdc++.h>\n\
    using namespace std;\ntypedef pair<int, int> P;\n\nvector<vector<int> > g;\nvector<int>\
    \ ord, low;\nvector<bool> is_articulation;\nvector<P> bridges;\n\nvoid dfs(int\
    \ u, int par, int& k) {\n    ord[u] = k;\n    k++;\n    low[u] = ord[u];\n   \
    \ int cnt = 0;\n    for (auto v : g[u]) {\n        // dfs\u306E\u5B50\u30CE\u30FC\
    \u30C9\u3078\u79FB\u52D5\n        if (ord[v] == -1) {\n            cnt++;\n  \
    \          dfs(v, u, k);\n            low[u] = min(low[u], low[v]);\n        \
    \    if (par != -1 && ord[u] <= low[v]) {\n                is_articulation[u]\
    \ = true;\n            }\n            if (ord[u] < low[v]) {\n               \
    \ bridges.push_back(make_pair(min(u, v), max(u, v)));\n            }\n       \
    \ }\n        // dfs\u6728\u306E\u5F8C\u9000\u8FBA\u3092\u79FB\u52D5\n        else\
    \ if (v != par)\n            low[u] = min(low[u], ord[v]);\n    }\n    if (par\
    \ == -1) {\n        is_articulation[u] = cnt >= 2;  // \u6839\u306Fdfs\u6728\u306E\
    \u6B21\u6570\u304C2\u4EE5\u4E0A\u306A\u3089\u3070\u95A2\u7BC0\u70B9\n    }\n}\n\
    \nvoid lowlink() {\n    ord.resize(g.size(), -1);\n    low.resize(g.size());\n\
    \    is_articulation.resize(g.size(), false);\n    int k = 0;\n    dfs(0, -1,\
    \ k);\n}\n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    g.resize(n);\n\
    \    for (int i = 0; i < m; i++) {\n        int a, b;\n        cin >> a >> b;\n\
    \        g[a].push_back(b);\n        g[b].push_back(a);\n    }\n    return 0;\n\
    }\n"
  code: "/*\nlowlink\n\u95A2\u7BC0\u70B9\u3001\u6A4B\u3092\u6C42\u3081\u308B\nO(V+E)\n\
    */\n\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef pair<int, int> P;\n\
    \nvector<vector<int> > g;\nvector<int> ord, low;\nvector<bool> is_articulation;\n\
    vector<P> bridges;\n\nvoid dfs(int u, int par, int& k) {\n    ord[u] = k;\n  \
    \  k++;\n    low[u] = ord[u];\n    int cnt = 0;\n    for (auto v : g[u]) {\n \
    \       // dfs\u306E\u5B50\u30CE\u30FC\u30C9\u3078\u79FB\u52D5\n        if (ord[v]\
    \ == -1) {\n            cnt++;\n            dfs(v, u, k);\n            low[u]\
    \ = min(low[u], low[v]);\n            if (par != -1 && ord[u] <= low[v]) {\n \
    \               is_articulation[u] = true;\n            }\n            if (ord[u]\
    \ < low[v]) {\n                bridges.push_back(make_pair(min(u, v), max(u, v)));\n\
    \            }\n        }\n        // dfs\u6728\u306E\u5F8C\u9000\u8FBA\u3092\u79FB\
    \u52D5\n        else if (v != par)\n            low[u] = min(low[u], ord[v]);\n\
    \    }\n    if (par == -1) {\n        is_articulation[u] = cnt >= 2;  // \u6839\
    \u306Fdfs\u6728\u306E\u6B21\u6570\u304C2\u4EE5\u4E0A\u306A\u3089\u3070\u95A2\u7BC0\
    \u70B9\n    }\n}\n\nvoid lowlink() {\n    ord.resize(g.size(), -1);\n    low.resize(g.size());\n\
    \    is_articulation.resize(g.size(), false);\n    int k = 0;\n    dfs(0, -1,\
    \ k);\n}\n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    g.resize(n);\n\
    \    for (int i = 0; i < m; i++) {\n        int a, b;\n        cin >> a >> b;\n\
    \        g[a].push_back(b);\n        g[b].push_back(a);\n    }\n    return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/lowlink.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/lowlink.cpp
layout: document
redirect_from:
- /library/src/graphs/lowlink.cpp
- /library/src/graphs/lowlink.cpp.html
title: src/graphs/lowlink.cpp
---
