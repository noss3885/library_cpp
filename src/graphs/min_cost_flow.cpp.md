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
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
  bundledCode: "#line 1 \"src/graphs/min_cost_flow.cpp\"\n/*\n\u6700\u5C0F\u8CBB\u7528\
    \u6D41\nO(FElogV)\n*/\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntypedef\
    \ pair<int, int> P;\nconstexpr int IINF = INT_MAX;\n\n// BEGIN\n\nstruct edge{\n\
    \    int to, cap, cost, rev;\n};\n\nvector<vector<edge> > G;\nvector<int> h, dist,\
    \ prevv, preve;\n\nvoid add_edge(int from, int to, int cap, int cost){\n    G[from].push_back((edge){to,\
    \ cap, cost, int(G[to].size())});\n    G[to].push_back((edge){from, 0, -cost,\
    \ int(G[from].size())-1});\n}\n\n// \u6700\u5C0F\u8CBB\u7528\u6D41\nint min_cost_flow(int\
    \ s, int t, int f){\n    h.resize(G.size());\n    dist.resize(G.size());\n   \
    \ prevv.resize(G.size());\n    preve.resize(G.size());\n    int res = 0;\n   \
    \ fill(h.begin(), h.end(), 0);\n    while(f > 0){\n        priority_queue<P, vector<P>,\
    \ greater<P> > que;\n        fill(dist.begin(), dist.end(), IINF);\n        dist[s]\
    \ = 0;\n        que.push({0,s});\n        while(!que.empty()){\n            P\
    \ p = que.top();\n            que.pop();\n            int v = p.second;\n    \
    \        if(dist[v] < p.first) continue;\n            for(int i=0;i<int(G[v].size());i++){\n\
    \                auto &e = G[v][i];\n                if(e.cap > 0 && dist[e.to]\
    \ > dist[v] + e.cost + h[v] - h[e.to]){\n                    dist[e.to] = dist[v]\
    \ + e.cost + h[v] - h[e.to];\n                    prevv[e.to] = v;\n         \
    \           preve[e.to] = i;\n                    que.push({dist[e.to], e.to});\n\
    \                }\n            }\n        }\n        if(dist[t] == IINF){\n \
    \           return -1;\n        }\n        for(int v=0; v<G.size(); v++) h[v]\
    \ += dist[v];\n        int d = f;\n        for(int v=t; v!=s; v=prevv[v]){\n \
    \           d = min(d, G[prevv[v]][preve[v]].cap);\n        }\n        f -= d;\n\
    \        res += d*h[t];\n        for(int v=t; v!=s; v=prevv[v]){\n           \
    \ auto &e = G[prevv[v]][preve[v]];\n            e.cap -= d;\n            G[v][e.rev].cap\
    \ += d;\n        }\n    }\n    return res;\n}\n\n// END\n\n// TEST\n// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\n\
    int main() {\n    int V, E, F;\n    cin >> V >> E >> F;\n    G.resize(V);\n  \
    \  for(int i=0;i<E;i++){\n        int u, v, c, d;\n        cin >> u >> v >> c\
    \ >> d;\n        add_edge(u, v, c, d);\n    }\n    cout << min_cost_flow(0, V-1,\
    \ F) << endl;\n    return 0;\n}\n"
  code: "/*\n\u6700\u5C0F\u8CBB\u7528\u6D41\nO(FElogV)\n*/\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntypedef pair<int, int> P;\nconstexpr int IINF = INT_MAX;\n\
    \n// BEGIN\n\nstruct edge{\n    int to, cap, cost, rev;\n};\n\nvector<vector<edge>\
    \ > G;\nvector<int> h, dist, prevv, preve;\n\nvoid add_edge(int from, int to,\
    \ int cap, int cost){\n    G[from].push_back((edge){to, cap, cost, int(G[to].size())});\n\
    \    G[to].push_back((edge){from, 0, -cost, int(G[from].size())-1});\n}\n\n//\
    \ \u6700\u5C0F\u8CBB\u7528\u6D41\nint min_cost_flow(int s, int t, int f){\n  \
    \  h.resize(G.size());\n    dist.resize(G.size());\n    prevv.resize(G.size());\n\
    \    preve.resize(G.size());\n    int res = 0;\n    fill(h.begin(), h.end(), 0);\n\
    \    while(f > 0){\n        priority_queue<P, vector<P>, greater<P> > que;\n \
    \       fill(dist.begin(), dist.end(), IINF);\n        dist[s] = 0;\n        que.push({0,s});\n\
    \        while(!que.empty()){\n            P p = que.top();\n            que.pop();\n\
    \            int v = p.second;\n            if(dist[v] < p.first) continue;\n\
    \            for(int i=0;i<int(G[v].size());i++){\n                auto &e = G[v][i];\n\
    \                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){\n\
    \                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];\n       \
    \             prevv[e.to] = v;\n                    preve[e.to] = i;\n       \
    \             que.push({dist[e.to], e.to});\n                }\n            }\n\
    \        }\n        if(dist[t] == IINF){\n            return -1;\n        }\n\
    \        for(int v=0; v<G.size(); v++) h[v] += dist[v];\n        int d = f;\n\
    \        for(int v=t; v!=s; v=prevv[v]){\n            d = min(d, G[prevv[v]][preve[v]].cap);\n\
    \        }\n        f -= d;\n        res += d*h[t];\n        for(int v=t; v!=s;\
    \ v=prevv[v]){\n            auto &e = G[prevv[v]][preve[v]];\n            e.cap\
    \ -= d;\n            G[v][e.rev].cap += d;\n        }\n    }\n    return res;\n\
    }\n\n// END\n\n// TEST\n// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\n\
    int main() {\n    int V, E, F;\n    cin >> V >> E >> F;\n    G.resize(V);\n  \
    \  for(int i=0;i<E;i++){\n        int u, v, c, d;\n        cin >> u >> v >> c\
    \ >> d;\n        add_edge(u, v, c, d);\n    }\n    cout << min_cost_flow(0, V-1,\
    \ F) << endl;\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/min_cost_flow.cpp
  requiredBy: []
  timestamp: '2019-08-26 15:49:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/min_cost_flow.cpp
layout: document
redirect_from:
- /library/src/graphs/min_cost_flow.cpp
- /library/src/graphs/min_cost_flow.cpp.html
title: src/graphs/min_cost_flow.cpp
---
