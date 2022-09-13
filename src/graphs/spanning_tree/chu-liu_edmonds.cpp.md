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
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B
    - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2124
  bundledCode: "#line 1 \"src/graphs/spanning_tree/chu-liu_edmonds.cpp\"\n/*\n\u6700\
    \u5C0F\u6709\u5411\u5168\u57DF\u6728 (minimum spanning arborescence)\nChu-Liu/Edmonds'\
    \ algorithm\nO(VE)\n*/\n#include<bits/stdc++.h>\nusing namespace std;\n\nstruct\
    \ Edge\n{\n    int from, to;\n    int64_t weight;\n    Edge(){};\n    Edge(int\
    \ u, int v, int64_t w){\n        from = u;\n        to = v;\n        weight =\
    \ w;\n    };\n};\nbool operator < (const Edge &e, const Edge &f){\n    if(e.weight\
    \ != f.weight){\n        return e.weight < f.weight;\n    }\n    else if(e.from\
    \ != f.from){\n        return e.from < f.from;\n    }\n    else{\n        return\
    \ e.to < f.to;\n    }\n}\n\nbool operator > (const Edge &e, const Edge &f){\n\
    \    if(e.weight != f.weight){\n        return e.weight > f.weight;\n    }\n \
    \   else if(e.from != f.from){\n        return e.from > f.from;\n    }\n    else{\n\
    \        return e.to > f.to;\n    }\n}\n\n// \u6700\u5C0F\u6709\u5411\u5168\u57DF\
    \u6728\nstruct ChuLiu_Edmonds\n{\n    int N, root;\n    vector< vector< Edge >\
    \ > g, gr;\n    vector<bool> onCycle, visited;\n    vector< Edge > minEdge;\n\n\
    \    ChuLiu_Edmonds(){};\n    ChuLiu_Edmonds(int siz, int r){init(siz, r);}\n\
    \    void init(int siz, int r){\n        N = siz;\n        root = r;\n       \
    \ g.clear();\n        g.resize(N);\n        gr.clear();\n        gr.resize(N);\n\
    \        onCycle.resize(N);\n        visited.resize(N);\n        minEdge.resize(N);\n\
    \    }\n    void addEdge(int from, int to, int64_t weight){\n        if(from ==\
    \ to)return;\n        g[from].push_back(Edge(from, to, weight));\n        gr[to].push_back(Edge(from,\
    \ to, weight));\n    }\n\n    // \u9589\u8DEF\u3092\u7E2E\u7D04\u3057\u305F\u65B0\
    \u305F\u306A\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\u3057\u3001\u518D\u5E30\u7684\
    \u306B\u89E3\u3092\u5F97\u308B\n    int64_t rec(int v){\n        ChuLiu_Edmonds\
    \ sub(N, root);\n        auto getIndex = [&](int u){return onCycle[u] ? v : u;};\n\
    \        for(int u=0;u<N;u++){\n            for(auto &e : gr[u]){\n          \
    \      sub.addEdge(getIndex(e.from), getIndex(e.to), e.weight - (onCycle[u] ?\
    \ minEdge[u].weight : 0));\n            }\n        }\n        int64_t res = sub.build();\n\
    \        return res;\n    }\n\n    int64_t build(){\n        fill(onCycle.begin(),\
    \ onCycle.end(), false);\n\n        // \u9802\u70B9i\u3078\u306E\u8FBA\u306E\u3046\
    \u3061\u6700\u5C0F\u30B3\u30B9\u30C8\u306E\u8FBA\u3092\u5F97\u308B\n        for(int\
    \ i=0;i<N;i++){\n            if(i==root || gr[i].size()==0)continue;\n       \
    \     sort(gr[i].begin(), gr[i].end());\n            minEdge[i] = gr[i][0];\n\
    \        }\n        \n        // \u9589\u8DEF\u691C\u51FA\n        vector<int>\
    \ deg(N, 0);\n        queue<int> que;\n        for(int i=0;i<N;i++){\n       \
    \     if(i==root || gr[i].size()==0)continue;\n            deg[minEdge[i].from]++;\n\
    \        }\n        for(int i=0;i<N;i++){\n            if(i==root || gr[i].size()==0)continue;\n\
    \            if(deg[i]==0) que.push(i);\n        }\n        while(!que.empty()){\
    \  // \u51FA\u6B21\u65700\u306E\u9802\u70B9\u304B\u3089\u53D6\u308A\u9664\u304F\
    \n            int v = que.front();\n            que.pop();\n            if(gr[v].size()>0){\n\
    \                int pre = minEdge[v].from;\n                deg[pre]--;\n   \
    \             if(pre != root && deg[pre]==0) que.push(pre);\n            }\n \
    \       }\n        for(int i=0;i<N;i++){\n            if(deg[i] > 0){  // \u9589\
    \u8DEF\u304C\u3042\u308B\n                onCycle[i] = true;\n               \
    \ int pre = minEdge[i].from;\n                while(pre != i){\n             \
    \       onCycle[pre] = true;\n                    pre = minEdge[pre].from;\n \
    \               }\n                int64_t sum = 0;\n                sum += rec(i);\n\
    \                for(int j=0;j<N;j++){\n                    if(onCycle[j]) sum\
    \ += minEdge[j].weight;\n                }\n                return sum;\n    \
    \        }\n        }\n        // \u9589\u8DEF\u304C\u306A\u3044\n        int64_t\
    \ res = 0;\n        for(int i=0;i<N;i++){\n            if(i==root || gr[i].size()==0)continue;\n\
    \            res += minEdge[i].weight;\n        }\n        return res;\n    }\n\
    \    bool connected(){\n        fill(visited.begin(), visited.end(), false);\n\
    \        queue<int> que;\n        que.push(root);\n        visited[root] = true;\n\
    \        while(!que.empty()){\n            int v = que.front();\n            que.pop();\n\
    \            for(auto &e : g[v]){\n                if(!visited[e.to]){\n     \
    \               visited[e.to] = true;\n                    que.push(e.to);\n \
    \               }\n            }\n        }\n        bool res = true;\n      \
    \  for(int i=0;i<N;i++){\n            res &= visited[i];\n        }\n        return\
    \ res;\n    }\n};\n\n// VARIFY\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B\n\
    \nChuLiu_Edmonds graph;\n\nint main() {\n    int V, E, r;\n    cin >> V >> E >>\
    \ r;\n    graph.init(V, r);\n    for(int i=0;i<E;i++){\n        int u, v;\n  \
    \      int64_t w;\n        cin >> u >> v >> w;\n        graph.addEdge(u, v, w);\n\
    \    }\n    cout << graph.build() << endl;\n    return 0;\n}\n\n// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2124\n"
  code: "/*\n\u6700\u5C0F\u6709\u5411\u5168\u57DF\u6728 (minimum spanning arborescence)\n\
    Chu-Liu/Edmonds' algorithm\nO(VE)\n*/\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct Edge\n{\n    int from, to;\n    int64_t weight;\n    Edge(){};\n\
    \    Edge(int u, int v, int64_t w){\n        from = u;\n        to = v;\n    \
    \    weight = w;\n    };\n};\nbool operator < (const Edge &e, const Edge &f){\n\
    \    if(e.weight != f.weight){\n        return e.weight < f.weight;\n    }\n \
    \   else if(e.from != f.from){\n        return e.from < f.from;\n    }\n    else{\n\
    \        return e.to < f.to;\n    }\n}\n\nbool operator > (const Edge &e, const\
    \ Edge &f){\n    if(e.weight != f.weight){\n        return e.weight > f.weight;\n\
    \    }\n    else if(e.from != f.from){\n        return e.from > f.from;\n    }\n\
    \    else{\n        return e.to > f.to;\n    }\n}\n\n// \u6700\u5C0F\u6709\u5411\
    \u5168\u57DF\u6728\nstruct ChuLiu_Edmonds\n{\n    int N, root;\n    vector< vector<\
    \ Edge > > g, gr;\n    vector<bool> onCycle, visited;\n    vector< Edge > minEdge;\n\
    \n    ChuLiu_Edmonds(){};\n    ChuLiu_Edmonds(int siz, int r){init(siz, r);}\n\
    \    void init(int siz, int r){\n        N = siz;\n        root = r;\n       \
    \ g.clear();\n        g.resize(N);\n        gr.clear();\n        gr.resize(N);\n\
    \        onCycle.resize(N);\n        visited.resize(N);\n        minEdge.resize(N);\n\
    \    }\n    void addEdge(int from, int to, int64_t weight){\n        if(from ==\
    \ to)return;\n        g[from].push_back(Edge(from, to, weight));\n        gr[to].push_back(Edge(from,\
    \ to, weight));\n    }\n\n    // \u9589\u8DEF\u3092\u7E2E\u7D04\u3057\u305F\u65B0\
    \u305F\u306A\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\u3057\u3001\u518D\u5E30\u7684\
    \u306B\u89E3\u3092\u5F97\u308B\n    int64_t rec(int v){\n        ChuLiu_Edmonds\
    \ sub(N, root);\n        auto getIndex = [&](int u){return onCycle[u] ? v : u;};\n\
    \        for(int u=0;u<N;u++){\n            for(auto &e : gr[u]){\n          \
    \      sub.addEdge(getIndex(e.from), getIndex(e.to), e.weight - (onCycle[u] ?\
    \ minEdge[u].weight : 0));\n            }\n        }\n        int64_t res = sub.build();\n\
    \        return res;\n    }\n\n    int64_t build(){\n        fill(onCycle.begin(),\
    \ onCycle.end(), false);\n\n        // \u9802\u70B9i\u3078\u306E\u8FBA\u306E\u3046\
    \u3061\u6700\u5C0F\u30B3\u30B9\u30C8\u306E\u8FBA\u3092\u5F97\u308B\n        for(int\
    \ i=0;i<N;i++){\n            if(i==root || gr[i].size()==0)continue;\n       \
    \     sort(gr[i].begin(), gr[i].end());\n            minEdge[i] = gr[i][0];\n\
    \        }\n        \n        // \u9589\u8DEF\u691C\u51FA\n        vector<int>\
    \ deg(N, 0);\n        queue<int> que;\n        for(int i=0;i<N;i++){\n       \
    \     if(i==root || gr[i].size()==0)continue;\n            deg[minEdge[i].from]++;\n\
    \        }\n        for(int i=0;i<N;i++){\n            if(i==root || gr[i].size()==0)continue;\n\
    \            if(deg[i]==0) que.push(i);\n        }\n        while(!que.empty()){\
    \  // \u51FA\u6B21\u65700\u306E\u9802\u70B9\u304B\u3089\u53D6\u308A\u9664\u304F\
    \n            int v = que.front();\n            que.pop();\n            if(gr[v].size()>0){\n\
    \                int pre = minEdge[v].from;\n                deg[pre]--;\n   \
    \             if(pre != root && deg[pre]==0) que.push(pre);\n            }\n \
    \       }\n        for(int i=0;i<N;i++){\n            if(deg[i] > 0){  // \u9589\
    \u8DEF\u304C\u3042\u308B\n                onCycle[i] = true;\n               \
    \ int pre = minEdge[i].from;\n                while(pre != i){\n             \
    \       onCycle[pre] = true;\n                    pre = minEdge[pre].from;\n \
    \               }\n                int64_t sum = 0;\n                sum += rec(i);\n\
    \                for(int j=0;j<N;j++){\n                    if(onCycle[j]) sum\
    \ += minEdge[j].weight;\n                }\n                return sum;\n    \
    \        }\n        }\n        // \u9589\u8DEF\u304C\u306A\u3044\n        int64_t\
    \ res = 0;\n        for(int i=0;i<N;i++){\n            if(i==root || gr[i].size()==0)continue;\n\
    \            res += minEdge[i].weight;\n        }\n        return res;\n    }\n\
    \    bool connected(){\n        fill(visited.begin(), visited.end(), false);\n\
    \        queue<int> que;\n        que.push(root);\n        visited[root] = true;\n\
    \        while(!que.empty()){\n            int v = que.front();\n            que.pop();\n\
    \            for(auto &e : g[v]){\n                if(!visited[e.to]){\n     \
    \               visited[e.to] = true;\n                    que.push(e.to);\n \
    \               }\n            }\n        }\n        bool res = true;\n      \
    \  for(int i=0;i<N;i++){\n            res &= visited[i];\n        }\n        return\
    \ res;\n    }\n};\n\n// VARIFY\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B\n\
    \nChuLiu_Edmonds graph;\n\nint main() {\n    int V, E, r;\n    cin >> V >> E >>\
    \ r;\n    graph.init(V, r);\n    for(int i=0;i<E;i++){\n        int u, v;\n  \
    \      int64_t w;\n        cin >> u >> v >> w;\n        graph.addEdge(u, v, w);\n\
    \    }\n    cout << graph.build() << endl;\n    return 0;\n}\n\n// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2124"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/spanning_tree/chu-liu_edmonds.cpp
  requiredBy: []
  timestamp: '2019-07-08 18:28:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/spanning_tree/chu-liu_edmonds.cpp
layout: document
redirect_from:
- /library/src/graphs/spanning_tree/chu-liu_edmonds.cpp
- /library/src/graphs/spanning_tree/chu-liu_edmonds.cpp.html
title: src/graphs/spanning_tree/chu-liu_edmonds.cpp
---
