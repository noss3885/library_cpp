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
  bundledCode: "#line 1 \"src/math/euler_phi.cpp\"\n// Euler's phi function\n// O(sqrt(n))\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\nint euler_phi(int n){\n   \
    \ int res = n;\n    for(int i=2;i*i<=n;i++){\n        if(n%i == 0){\n        \
    \    res = res/i * (i-1);\n            while(n%i==0) n /= i;\n        }\n    }\n\
    \    if(n != 1) res = res/n *(n-1);\n    return res;\n}\n\nvector<int> euler_table;\n\
    \n// O(n)\nvoid build_euler_phi(int n){\n    euler_table.resize(n+1);\n    for(int\
    \ i=0;i<=n;i++) euler_table[i] = i;\n    for(int i=2;i<=n;i++){\n        if(euler_table[i]\
    \ == i){\n            for(int j=i;j<=n;j+=i){\n                euler_table[j]\
    \ = euler_table[j]/i*(i-1);\n            }\n        }\n    }\n}\n"
  code: "// Euler's phi function\n// O(sqrt(n))\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\nint euler_phi(int n){\n    int res = n;\n    for(int i=2;i*i<=n;i++){\n\
    \        if(n%i == 0){\n            res = res/i * (i-1);\n            while(n%i==0)\
    \ n /= i;\n        }\n    }\n    if(n != 1) res = res/n *(n-1);\n    return res;\n\
    }\n\nvector<int> euler_table;\n\n// O(n)\nvoid build_euler_phi(int n){\n    euler_table.resize(n+1);\n\
    \    for(int i=0;i<=n;i++) euler_table[i] = i;\n    for(int i=2;i<=n;i++){\n \
    \       if(euler_table[i] == i){\n            for(int j=i;j<=n;j+=i){\n      \
    \          euler_table[j] = euler_table[j]/i*(i-1);\n            }\n        }\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/euler_phi.cpp
  requiredBy: []
  timestamp: '2019-10-21 15:05:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/euler_phi.cpp
layout: document
redirect_from:
- /library/src/math/euler_phi.cpp
- /library/src/math/euler_phi.cpp.html
title: src/math/euler_phi.cpp
---
