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
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
  bundledCode: "#line 1 \"src/data_structures/sqrt_decomposition.cpp\"\n/*\n\u5E73\
    \u65B9\u5206\u5272\nRSQ,RAQ,RUQ\u304C\u53EF\u80FD\n*/\n#include <iostream>\n#include\
    \ <vector>\n#include <climits>\nusing namespace std;\n\ntypedef long long ll;\n\
    \nstruct SqrtDecomposition {\n    const ll sqrtN = 512;\n    const ll INF = LONG_LONG_MAX;\n\
    \    ll N, K;\n    vector<ll> data;\n    vector<ll> bucketSum, bucketAdd, bucketMin;\n\
    \    vector<bool> lazyFlag;\n    vector<ll> lazyUpdate;\n    SqrtDecomposition(ll\
    \ n = 0LL, ll x = 0LL) : N(n) {\n        K = (N + sqrtN - 1) / sqrtN;\n      \
    \  data.assign(K*sqrtN, x);\n        bucketSum.assign(K, x*sqrtN);\n        bucketAdd.assign(K,\
    \ 0ll);\n        bucketMin.assign(K, x);\n        lazyFlag.assign(K, false);\n\
    \        lazyUpdate.assign(K, x);\n    }\n    void init(ll n, ll x = 0LL){\n \
    \       N = n;\n        K = (N + sqrtN - 1) / sqrtN;\n        data.assign(K*sqrtN,\
    \ x);\n        bucketSum.assign(K, x*sqrtN);\n        bucketAdd.assign(K, 0ll);\n\
    \        bucketMin.assign(K, x);\n        lazyFlag.assign(K, false);\n       \
    \ lazyUpdate.assign(K, x);\n    }\n    void eval(ll k) {\n        if (lazyFlag[k])\
    \ {\n            lazyFlag[k] = false;\n            for (ll i = k * sqrtN; i <\
    \ (k + 1) * sqrtN; ++i) {\n                data[i] = lazyUpdate[k];\n        \
    \    }\n        }\n    }\n    // [s, t)\n    void add(ll s, ll t, ll x) {\n  \
    \      for (ll k = 0; k < K; ++k) {\n            ll l = k * sqrtN, r = (k + 1)\
    \ * sqrtN;\n            if (r <= s || t <= l) continue;\n            if (s <=\
    \ l && r <= t) {\n                bucketSum[k] += x * sqrtN;\n               \
    \ bucketAdd[k] += x;\n                bucketMin[k] += x;\n            } else {\n\
    \                eval(k);\n                for (ll i = max(s, l); i < min(t, r);\
    \ ++i) {\n                    data[i] += x;\n                    bucketSum[k]\
    \ += x;\n                }\n                ll &minVal = bucketMin[k] = INF;\n\
    \                for (ll i = l; i < r; ++i) {\n                    minVal = min(minVal,\
    \ data[i] + bucketAdd[k]);\n                }\n            }\n        }\n    }\n\
    \    // [s, t)\n    void update(ll s, ll t, ll x) {\n        for (ll k = 0; k\
    \ < K; ++k) {\n            ll l = k * sqrtN, r = (k + 1) * sqrtN;\n          \
    \  if (r <= s || t <= l) continue;\n            if (s <= l && r <= t) {\n    \
    \            bucketSum[k] = x * sqrtN;\n                bucketAdd[k] = 0ll;\n\
    \                bucketMin[k] = x;\n                lazyFlag[k] = true;\n    \
    \            lazyUpdate[k] = x;\n            } else {\n                eval(k);\n\
    \                for (ll i = l; i < r; ++i) {\n                    data[i] = data[i]\
    \ + bucketAdd[k];\n                }\n                bucketAdd[k] = 0LL;\n  \
    \              for (ll i = max(s, l); i < min(t, r); ++i) {\n                \
    \    data[i] = x;\n                }\n                ll &sumVal = bucketSum[k]\
    \ = 0ll;\n                ll &minVal = bucketMin[k] = INF;\n                for\
    \ (ll i = l; i < r; ++i) {\n                    sumVal = sumVal + data[i];\n \
    \                   minVal = min(minVal, data[i]);\n                }\n      \
    \      }\n        }\n    }\n    // [s, t)\n    ll getSum(ll s, ll t) {\n     \
    \   ll sumVal = 0;\n        for (ll k = 0; k < K; ++k) {\n            ll l = k\
    \ * sqrtN, r = (k + 1) * sqrtN;\n            if (r <= s || t <= l) continue;\n\
    \            if (s <= l && r <= t) {\n                sumVal = sumVal + bucketSum[k];\n\
    \            } else {\n                eval(k);\n                for (ll i = max(s,\
    \ l); i < min(t, r); ++i) {\n                    sumVal = sumVal + data[i] + bucketAdd[k];\n\
    \                }\n            }\n        }\n        return sumVal;\n    }\n\
    \    // [s, t)\n    ll getMin(ll s, ll t){\n        ll minVal = INF;\n       \
    \ for(ll k = 0; k < K; ++k){\n            ll l = k*sqrtN, r = (k+1)*sqrtN;\n \
    \           if(r <= s || t <= l) continue;\n            if(s <= l && r <= t){\n\
    \                minVal = min(minVal, bucketMin[k]);\n            } else {\n \
    \               eval(k);\n                for(ll i = max(s,l); i < min(t,r); ++i){\n\
    \                    minVal = min(minVal, data[i] + bucketAdd[k]);\n         \
    \       }\n            }\n        }\n        return minVal;\n    }\n};\n\n\n//\
    \ varify\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\n\
    void DSL_2_D(){\n    int n, q;\n    cin >> n >> q;\n    SqrtDecomposition ruq(n,\
    \ (1LL<<31)-1);\n    for(int i=0; i<q; i++){\n        int c;\n        cin >> c;\n\
    \        if(c){\n            int k;\n            cin >> k;\n            cout <<\
    \ ruq.getSum(k,k+1) << endl;\n        }\n        else{\n            int s, t,\
    \ x;\n            cin >> s >> t >> x;\n            ruq.update(s,t+1,x);\n    \
    \    }\n    }\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\n\
    void DSL_2_E(){\n    int n, q;\n    cin >> n >> q;\n    SqrtDecomposition ruq(n);\n\
    \    for(int i=0; i<q; i++){\n        int c;\n        cin >> c;\n        if(c){\n\
    \            int k;\n            cin >> k;\n            cout << ruq.getSum(k,k+1)\
    \ << endl;\n        }\n        else{\n            int s, t, x;\n            cin\
    \ >> s >> t >> x;\n            ruq.add(s,t+1,x);\n        }\n    }\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\n\
    void DSL_2_G(){\n    int n, q;\n    cin >> n >> q;\n    SqrtDecomposition ruq(n);\n\
    \    for(int i=0; i<q; i++){\n        int c;\n        cin >> c;\n        if(c){\n\
    \            int s, t;\n            cin >> s >> t;\n            cout << ruq.getSum(s,t+1)\
    \ << endl;\n        }\n        else{\n            int s, t, x;\n            cin\
    \ >> s >> t >> x;\n            ruq.add(s,t+1,x);\n        }\n    }\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\n\
    void DSL_2_I(){\n    int n, q;\n    cin >> n >> q;\n    SqrtDecomposition ruq(n);\n\
    \    for(int i=0; i<q; i++){\n        int c;\n        cin >> c;\n        if(c){\n\
    \            int s, t;\n            cin >> s >> t;\n            cout << ruq.getSum(s,t+1)\
    \ << endl;\n        }\n        else{\n            int s, t, x;\n            cin\
    \ >> s >> t >> x;\n            ruq.update(s,t+1,x);\n        }\n    }\n}\n\nint\
    \ main(){\n    //DSL_2_D();\n    //DSL_2_E();\n    //DSL_2_G();\n    //DSL_2_I();\n\
    \    return 0;\n}\n"
  code: "/*\n\u5E73\u65B9\u5206\u5272\nRSQ,RAQ,RUQ\u304C\u53EF\u80FD\n*/\n#include\
    \ <iostream>\n#include <vector>\n#include <climits>\nusing namespace std;\n\n\
    typedef long long ll;\n\nstruct SqrtDecomposition {\n    const ll sqrtN = 512;\n\
    \    const ll INF = LONG_LONG_MAX;\n    ll N, K;\n    vector<ll> data;\n    vector<ll>\
    \ bucketSum, bucketAdd, bucketMin;\n    vector<bool> lazyFlag;\n    vector<ll>\
    \ lazyUpdate;\n    SqrtDecomposition(ll n = 0LL, ll x = 0LL) : N(n) {\n      \
    \  K = (N + sqrtN - 1) / sqrtN;\n        data.assign(K*sqrtN, x);\n        bucketSum.assign(K,\
    \ x*sqrtN);\n        bucketAdd.assign(K, 0ll);\n        bucketMin.assign(K, x);\n\
    \        lazyFlag.assign(K, false);\n        lazyUpdate.assign(K, x);\n    }\n\
    \    void init(ll n, ll x = 0LL){\n        N = n;\n        K = (N + sqrtN - 1)\
    \ / sqrtN;\n        data.assign(K*sqrtN, x);\n        bucketSum.assign(K, x*sqrtN);\n\
    \        bucketAdd.assign(K, 0ll);\n        bucketMin.assign(K, x);\n        lazyFlag.assign(K,\
    \ false);\n        lazyUpdate.assign(K, x);\n    }\n    void eval(ll k) {\n  \
    \      if (lazyFlag[k]) {\n            lazyFlag[k] = false;\n            for (ll\
    \ i = k * sqrtN; i < (k + 1) * sqrtN; ++i) {\n                data[i] = lazyUpdate[k];\n\
    \            }\n        }\n    }\n    // [s, t)\n    void add(ll s, ll t, ll x)\
    \ {\n        for (ll k = 0; k < K; ++k) {\n            ll l = k * sqrtN, r = (k\
    \ + 1) * sqrtN;\n            if (r <= s || t <= l) continue;\n            if (s\
    \ <= l && r <= t) {\n                bucketSum[k] += x * sqrtN;\n            \
    \    bucketAdd[k] += x;\n                bucketMin[k] += x;\n            } else\
    \ {\n                eval(k);\n                for (ll i = max(s, l); i < min(t,\
    \ r); ++i) {\n                    data[i] += x;\n                    bucketSum[k]\
    \ += x;\n                }\n                ll &minVal = bucketMin[k] = INF;\n\
    \                for (ll i = l; i < r; ++i) {\n                    minVal = min(minVal,\
    \ data[i] + bucketAdd[k]);\n                }\n            }\n        }\n    }\n\
    \    // [s, t)\n    void update(ll s, ll t, ll x) {\n        for (ll k = 0; k\
    \ < K; ++k) {\n            ll l = k * sqrtN, r = (k + 1) * sqrtN;\n          \
    \  if (r <= s || t <= l) continue;\n            if (s <= l && r <= t) {\n    \
    \            bucketSum[k] = x * sqrtN;\n                bucketAdd[k] = 0ll;\n\
    \                bucketMin[k] = x;\n                lazyFlag[k] = true;\n    \
    \            lazyUpdate[k] = x;\n            } else {\n                eval(k);\n\
    \                for (ll i = l; i < r; ++i) {\n                    data[i] = data[i]\
    \ + bucketAdd[k];\n                }\n                bucketAdd[k] = 0LL;\n  \
    \              for (ll i = max(s, l); i < min(t, r); ++i) {\n                \
    \    data[i] = x;\n                }\n                ll &sumVal = bucketSum[k]\
    \ = 0ll;\n                ll &minVal = bucketMin[k] = INF;\n                for\
    \ (ll i = l; i < r; ++i) {\n                    sumVal = sumVal + data[i];\n \
    \                   minVal = min(minVal, data[i]);\n                }\n      \
    \      }\n        }\n    }\n    // [s, t)\n    ll getSum(ll s, ll t) {\n     \
    \   ll sumVal = 0;\n        for (ll k = 0; k < K; ++k) {\n            ll l = k\
    \ * sqrtN, r = (k + 1) * sqrtN;\n            if (r <= s || t <= l) continue;\n\
    \            if (s <= l && r <= t) {\n                sumVal = sumVal + bucketSum[k];\n\
    \            } else {\n                eval(k);\n                for (ll i = max(s,\
    \ l); i < min(t, r); ++i) {\n                    sumVal = sumVal + data[i] + bucketAdd[k];\n\
    \                }\n            }\n        }\n        return sumVal;\n    }\n\
    \    // [s, t)\n    ll getMin(ll s, ll t){\n        ll minVal = INF;\n       \
    \ for(ll k = 0; k < K; ++k){\n            ll l = k*sqrtN, r = (k+1)*sqrtN;\n \
    \           if(r <= s || t <= l) continue;\n            if(s <= l && r <= t){\n\
    \                minVal = min(minVal, bucketMin[k]);\n            } else {\n \
    \               eval(k);\n                for(ll i = max(s,l); i < min(t,r); ++i){\n\
    \                    minVal = min(minVal, data[i] + bucketAdd[k]);\n         \
    \       }\n            }\n        }\n        return minVal;\n    }\n};\n\n\n//\
    \ varify\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\n\
    void DSL_2_D(){\n    int n, q;\n    cin >> n >> q;\n    SqrtDecomposition ruq(n,\
    \ (1LL<<31)-1);\n    for(int i=0; i<q; i++){\n        int c;\n        cin >> c;\n\
    \        if(c){\n            int k;\n            cin >> k;\n            cout <<\
    \ ruq.getSum(k,k+1) << endl;\n        }\n        else{\n            int s, t,\
    \ x;\n            cin >> s >> t >> x;\n            ruq.update(s,t+1,x);\n    \
    \    }\n    }\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\n\
    void DSL_2_E(){\n    int n, q;\n    cin >> n >> q;\n    SqrtDecomposition ruq(n);\n\
    \    for(int i=0; i<q; i++){\n        int c;\n        cin >> c;\n        if(c){\n\
    \            int k;\n            cin >> k;\n            cout << ruq.getSum(k,k+1)\
    \ << endl;\n        }\n        else{\n            int s, t, x;\n            cin\
    \ >> s >> t >> x;\n            ruq.add(s,t+1,x);\n        }\n    }\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\n\
    void DSL_2_G(){\n    int n, q;\n    cin >> n >> q;\n    SqrtDecomposition ruq(n);\n\
    \    for(int i=0; i<q; i++){\n        int c;\n        cin >> c;\n        if(c){\n\
    \            int s, t;\n            cin >> s >> t;\n            cout << ruq.getSum(s,t+1)\
    \ << endl;\n        }\n        else{\n            int s, t, x;\n            cin\
    \ >> s >> t >> x;\n            ruq.add(s,t+1,x);\n        }\n    }\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\n\
    void DSL_2_I(){\n    int n, q;\n    cin >> n >> q;\n    SqrtDecomposition ruq(n);\n\
    \    for(int i=0; i<q; i++){\n        int c;\n        cin >> c;\n        if(c){\n\
    \            int s, t;\n            cin >> s >> t;\n            cout << ruq.getSum(s,t+1)\
    \ << endl;\n        }\n        else{\n            int s, t, x;\n            cin\
    \ >> s >> t >> x;\n            ruq.update(s,t+1,x);\n        }\n    }\n}\n\nint\
    \ main(){\n    //DSL_2_D();\n    //DSL_2_E();\n    //DSL_2_G();\n    //DSL_2_I();\n\
    \    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/sqrt_decomposition.cpp
  requiredBy: []
  timestamp: '2019-03-21 11:39:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structures/sqrt_decomposition.cpp
layout: document
redirect_from:
- /library/src/data_structures/sqrt_decomposition.cpp
- /library/src/data_structures/sqrt_decomposition.cpp.html
title: src/data_structures/sqrt_decomposition.cpp
---
