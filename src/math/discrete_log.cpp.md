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
    - https://atcoder.jp/contests/arc042/tasks/arc042_d
  bundledCode: "#line 1 \"src/math/discrete_log.cpp\"\n// discrete log\n// compute\
    \ x that a^x = b mod m\n//\n// baby-step giant-step algorithm\n// O(sqrt(m))\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long int;\n\
    \nll power(ll x, ll n, const ll p){\n    x %= p;\n    ll res = 1;\n    while(n\
    \ > 0){\n        if(n & 1){\n            res = res * x % p;\n        }\n     \
    \   x = x * x % p;\n        n >>= 1;\n    }\n    return res;\n}\n\n// return x,\
    \ a^x = b mod m\nll discrete_log(ll a, ll b, ll m){\n    ll h = ceil(sqrt(m)+.1);\n\
    \    unordered_map<ll,ll> table;\n    for(ll i=0,t=1;i<h;i++){\n        table[t]\
    \ = i;\n        t = t * a % m;\n    }\n    ll e = b, inv = power(a,m-1-h,m);\n\
    \    for(ll i=0;i<h;i++){\n        if(table.find(e) != table.end()){\n       \
    \     ll j = table[e];\n            return i*h+j;\n        }\n        e = e *\
    \ inv % m;\n    }\n    return -1;\n}\n\n// TEST\n// https://atcoder.jp/contests/arc042/tasks/arc042_d\n\
    \nint main(){\n    ll x, p, a, b, k;\n    cin >> x >> p >> a >> b;\n    k = b-a+1;\n\
    \    a %= p-1;\n    b %= p-1;\n    if(a==0 || a>b || k >= p-1){\n        cout\
    \ << 1 << endl;\n        return 0;\n    }\n    if(k < 1<<24){\n        ll ans\
    \ = p, tmp = power(x,a,p);\n        for(ll i=0;i<k;i++){\n            ans = min(ans,\
    \ tmp);\n            tmp = tmp * x % p;\n        }\n        cout << ans << endl;\n\
    \    }\n    else{  // baby-step giant-step\n        for(int i=1;i<p;i++){\n  \
    \          ll y = discrete_log(x,i,p);\n            if(y != p && y >= a && y <=\
    \ b){\n                cout << i << endl;\n                break;\n          \
    \  }\n        }\n    }\n    return 0;\n}\n"
  code: "// discrete log\n// compute x that a^x = b mod m\n//\n// baby-step giant-step\
    \ algorithm\n// O(sqrt(m))\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing ll = long long int;\n\nll power(ll x, ll n, const ll p){\n    x %= p;\n\
    \    ll res = 1;\n    while(n > 0){\n        if(n & 1){\n            res = res\
    \ * x % p;\n        }\n        x = x * x % p;\n        n >>= 1;\n    }\n    return\
    \ res;\n}\n\n// return x, a^x = b mod m\nll discrete_log(ll a, ll b, ll m){\n\
    \    ll h = ceil(sqrt(m)+.1);\n    unordered_map<ll,ll> table;\n    for(ll i=0,t=1;i<h;i++){\n\
    \        table[t] = i;\n        t = t * a % m;\n    }\n    ll e = b, inv = power(a,m-1-h,m);\n\
    \    for(ll i=0;i<h;i++){\n        if(table.find(e) != table.end()){\n       \
    \     ll j = table[e];\n            return i*h+j;\n        }\n        e = e *\
    \ inv % m;\n    }\n    return -1;\n}\n\n// TEST\n// https://atcoder.jp/contests/arc042/tasks/arc042_d\n\
    \nint main(){\n    ll x, p, a, b, k;\n    cin >> x >> p >> a >> b;\n    k = b-a+1;\n\
    \    a %= p-1;\n    b %= p-1;\n    if(a==0 || a>b || k >= p-1){\n        cout\
    \ << 1 << endl;\n        return 0;\n    }\n    if(k < 1<<24){\n        ll ans\
    \ = p, tmp = power(x,a,p);\n        for(ll i=0;i<k;i++){\n            ans = min(ans,\
    \ tmp);\n            tmp = tmp * x % p;\n        }\n        cout << ans << endl;\n\
    \    }\n    else{  // baby-step giant-step\n        for(int i=1;i<p;i++){\n  \
    \          ll y = discrete_log(x,i,p);\n            if(y != p && y >= a && y <=\
    \ b){\n                cout << i << endl;\n                break;\n          \
    \  }\n        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/discrete_log.cpp
  requiredBy: []
  timestamp: '2019-10-18 13:29:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/discrete_log.cpp
layout: document
redirect_from:
- /library/src/math/discrete_log.cpp
- /library/src/math/discrete_log.cpp.html
title: src/math/discrete_log.cpp
---
