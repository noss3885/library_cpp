---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2748.test.cpp
    title: test/aoj/2748.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_4_A_SCC.test.cpp
    title: test/aoj/GRL_4_A_SCC.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graphs/strongly_connected_components.cpp\"\n#include\
    \ <algorithm>\r\n#include <stack>\r\n#include <vector>\r\n\r\nstruct SCC {\r\n\
    \    int N, p;\r\n    std::vector<std::vector<int> > g, gr, g2i, t, tr;\r\n  \
    \  std::vector<bool> visited;\r\n    std::vector<int> i2g;\r\n    std::stack<int>\
    \ order;\r\n\r\n    SCC() {}\r\n    SCC(int n) { init(n); }\r\n    void init(int\
    \ n) {\r\n        N = n;\r\n        g.clear();\r\n        g.resize(N);\r\n   \
    \     gr.clear();\r\n        gr.resize(N);\r\n        visited.resize(N);\r\n \
    \       i2g.resize(N);\r\n    }\r\n    void add_edge(int u, int v) {\r\n     \
    \   g[u].emplace_back(v);\r\n        gr[v].emplace_back(u);\r\n    }\r\n\r\n \
    \   void dfs(int x) {\r\n        if (visited[x]) return;\r\n        visited[x]\
    \ = true;\r\n        for (int i : g[x]) dfs(i);\r\n        order.push(x);\r\n\
    \    }\r\n\r\n    void rdfs(int x, int k) {\r\n        if (visited[x]) return;\r\
    \n        visited[x] = true;\r\n        i2g[x] = k;\r\n        for (int i : gr[x])\
    \ rdfs(i, k);\r\n    }\r\n\r\n    void build() {\r\n        std::fill(visited.begin(),\
    \ visited.end(), false);\r\n        std::fill(i2g.begin(), i2g.end(), -1);\r\n\
    \        for (int i = 0; i < N; i++) dfs(i);\r\n        p = 0;\r\n        std::fill(visited.begin(),\
    \ visited.end(), false);\r\n        while (!order.empty()) {\r\n            int\
    \ idx = order.top();\r\n            order.pop();\r\n            if (!visited[idx])\
    \ rdfs(idx, p++);\r\n        }\r\n        g2i.clear();\r\n        g2i.resize(p);\r\
    \n        for (int i = 0; i < N; i++) {\r\n            g2i[i2g[i]].push_back(i);\r\
    \n        }\r\n        t.resize(p);\r\n        tr.resize(p);\r\n        for (int\
    \ i = 0; i < N; i++) {\r\n            for (auto& to : g[i]) {\r\n            \
    \    int x = i2g[i], y = i2g[to];\r\n                if (x == y) continue;\r\n\
    \                t[x].push_back(y);\r\n                tr[y].push_back(x);\r\n\
    \            }\r\n        }\r\n        for (int i = 0; i < p; i++) {\r\n     \
    \       sort(t[i].begin(), t[i].end());\r\n            t[i].erase(unique(t[i].begin(),\
    \ t[i].end()), t[i].end());\r\n            sort(tr[i].begin(), tr[i].end());\r\
    \n            tr[i].erase(unique(tr[i].begin(), tr[i].end()), tr[i].end());\r\n\
    \        }\r\n    }\r\n    int count() const { return p; }\r\n    int operator[](int\
    \ k) const { return i2g[k]; }\r\n};\r\n\r\nstruct TwoSAT {\r\n    int N;\r\n \
    \   SCC scc;\r\n    std::vector<int> v;\r\n    TwoSAT() = default;\r\n    TwoSAT(int\
    \ n) : N(n), scc(n * 2) {}\r\n    void init(int n) {\r\n        N = n;\r\n   \
    \     scc.init(N * 2);\r\n    }\r\n    int neg(int a) { return (a + N) % (N *\
    \ 2); }\r\n    void add_edge(int a, int b) {\r\n        scc.add_edge(a, b);\r\n\
    \    }\r\n    void add_if(int a, int b) {\r\n        // a -> b <=> !b -> !a\r\n\
    \        add_edge(a, b);\r\n        add_edge(neg(b), neg(a));\r\n    }\r\n   \
    \ void add_iff(int a, int b) {\r\n        // (a <=> b) <=> a -> b and b -> a\r\
    \n        add_if(a, b);\r\n        add_if(b, a);\r\n    }\r\n    void add_or(int\
    \ a, int b) {\r\n        // a or b <=> !a -> b and !b -> a\r\n        add_if(neg(a),\
    \ b);\r\n    }\r\n    void add_nand(int a, int b) {\r\n        // a nand b <=>\
    \ a -> !b and b -> !a\r\n        add_if(a, neg(b));\r\n    }\r\n    void add_xor(int\
    \ a, int b) {\r\n        add_nand(a, b);\r\n        add_or(a, b);\r\n    }\r\n\
    \    void set_true(int a) {\r\n        // a <=> !a -> a\r\n        add_edge(neg(a),\
    \ a);\r\n    }\r\n    void set_false(int a) {\r\n        // !a <=> a -> !a\r\n\
    \        add_edge(a, neg(a));\r\n    }\r\n    bool build() {\r\n        scc.build();\r\
    \n        bool ok = true;\r\n        for (int i = 0; i < N; i++) {\r\n       \
    \     ok &= scc.i2g[i] != scc.i2g[neg(i)];\r\n        }\r\n        if (ok) {\r\
    \n            for (int i = 0; i < N; i++) {\r\n                v.push_back(scc[i]\
    \ > scc[neg(i)]);\r\n            }\r\n        }\r\n        return ok;\r\n    }\r\
    \n    int operator[](int k) const { return v[k]; };\r\n};\r\n"
  code: "#include <algorithm>\r\n#include <stack>\r\n#include <vector>\r\n\r\nstruct\
    \ SCC {\r\n    int N, p;\r\n    std::vector<std::vector<int> > g, gr, g2i, t,\
    \ tr;\r\n    std::vector<bool> visited;\r\n    std::vector<int> i2g;\r\n    std::stack<int>\
    \ order;\r\n\r\n    SCC() {}\r\n    SCC(int n) { init(n); }\r\n    void init(int\
    \ n) {\r\n        N = n;\r\n        g.clear();\r\n        g.resize(N);\r\n   \
    \     gr.clear();\r\n        gr.resize(N);\r\n        visited.resize(N);\r\n \
    \       i2g.resize(N);\r\n    }\r\n    void add_edge(int u, int v) {\r\n     \
    \   g[u].emplace_back(v);\r\n        gr[v].emplace_back(u);\r\n    }\r\n\r\n \
    \   void dfs(int x) {\r\n        if (visited[x]) return;\r\n        visited[x]\
    \ = true;\r\n        for (int i : g[x]) dfs(i);\r\n        order.push(x);\r\n\
    \    }\r\n\r\n    void rdfs(int x, int k) {\r\n        if (visited[x]) return;\r\
    \n        visited[x] = true;\r\n        i2g[x] = k;\r\n        for (int i : gr[x])\
    \ rdfs(i, k);\r\n    }\r\n\r\n    void build() {\r\n        std::fill(visited.begin(),\
    \ visited.end(), false);\r\n        std::fill(i2g.begin(), i2g.end(), -1);\r\n\
    \        for (int i = 0; i < N; i++) dfs(i);\r\n        p = 0;\r\n        std::fill(visited.begin(),\
    \ visited.end(), false);\r\n        while (!order.empty()) {\r\n            int\
    \ idx = order.top();\r\n            order.pop();\r\n            if (!visited[idx])\
    \ rdfs(idx, p++);\r\n        }\r\n        g2i.clear();\r\n        g2i.resize(p);\r\
    \n        for (int i = 0; i < N; i++) {\r\n            g2i[i2g[i]].push_back(i);\r\
    \n        }\r\n        t.resize(p);\r\n        tr.resize(p);\r\n        for (int\
    \ i = 0; i < N; i++) {\r\n            for (auto& to : g[i]) {\r\n            \
    \    int x = i2g[i], y = i2g[to];\r\n                if (x == y) continue;\r\n\
    \                t[x].push_back(y);\r\n                tr[y].push_back(x);\r\n\
    \            }\r\n        }\r\n        for (int i = 0; i < p; i++) {\r\n     \
    \       sort(t[i].begin(), t[i].end());\r\n            t[i].erase(unique(t[i].begin(),\
    \ t[i].end()), t[i].end());\r\n            sort(tr[i].begin(), tr[i].end());\r\
    \n            tr[i].erase(unique(tr[i].begin(), tr[i].end()), tr[i].end());\r\n\
    \        }\r\n    }\r\n    int count() const { return p; }\r\n    int operator[](int\
    \ k) const { return i2g[k]; }\r\n};\r\n\r\nstruct TwoSAT {\r\n    int N;\r\n \
    \   SCC scc;\r\n    std::vector<int> v;\r\n    TwoSAT() = default;\r\n    TwoSAT(int\
    \ n) : N(n), scc(n * 2) {}\r\n    void init(int n) {\r\n        N = n;\r\n   \
    \     scc.init(N * 2);\r\n    }\r\n    int neg(int a) { return (a + N) % (N *\
    \ 2); }\r\n    void add_edge(int a, int b) {\r\n        scc.add_edge(a, b);\r\n\
    \    }\r\n    void add_if(int a, int b) {\r\n        // a -> b <=> !b -> !a\r\n\
    \        add_edge(a, b);\r\n        add_edge(neg(b), neg(a));\r\n    }\r\n   \
    \ void add_iff(int a, int b) {\r\n        // (a <=> b) <=> a -> b and b -> a\r\
    \n        add_if(a, b);\r\n        add_if(b, a);\r\n    }\r\n    void add_or(int\
    \ a, int b) {\r\n        // a or b <=> !a -> b and !b -> a\r\n        add_if(neg(a),\
    \ b);\r\n    }\r\n    void add_nand(int a, int b) {\r\n        // a nand b <=>\
    \ a -> !b and b -> !a\r\n        add_if(a, neg(b));\r\n    }\r\n    void add_xor(int\
    \ a, int b) {\r\n        add_nand(a, b);\r\n        add_or(a, b);\r\n    }\r\n\
    \    void set_true(int a) {\r\n        // a <=> !a -> a\r\n        add_edge(neg(a),\
    \ a);\r\n    }\r\n    void set_false(int a) {\r\n        // !a <=> a -> !a\r\n\
    \        add_edge(a, neg(a));\r\n    }\r\n    bool build() {\r\n        scc.build();\r\
    \n        bool ok = true;\r\n        for (int i = 0; i < N; i++) {\r\n       \
    \     ok &= scc.i2g[i] != scc.i2g[neg(i)];\r\n        }\r\n        if (ok) {\r\
    \n            for (int i = 0; i < N; i++) {\r\n                v.push_back(scc[i]\
    \ > scc[neg(i)]);\r\n            }\r\n        }\r\n        return ok;\r\n    }\r\
    \n    int operator[](int k) const { return v[k]; };\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/strongly_connected_components.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_4_A_SCC.test.cpp
  - test/aoj/2748.test.cpp
documentation_of: src/graphs/strongly_connected_components.cpp
layout: document
redirect_from:
- /library/src/graphs/strongly_connected_components.cpp
- /library/src/graphs/strongly_connected_components.cpp.html
title: src/graphs/strongly_connected_components.cpp
---
