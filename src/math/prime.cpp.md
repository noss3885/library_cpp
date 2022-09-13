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
  bundledCode: "#line 1 \"src/math/prime.cpp\"\n\r\n#include <vector>\r\n#include\
    \ <map>\r\n\r\nusing namespace std;\r\n\r\ntypedef long long ll;\r\n\r\n//\u7D20\
    \u6570\u5224\u5B9A\r\nbool isprime(int n) {\r\n    if (n % 2 == 0) return false;\r\
    \n    for (int i = 3; i * i <= n; i += 2) {\r\n        if (n % i == 0) return\
    \ false;\r\n    }\r\n    return n != 1;\r\n}\r\n\r\n//\u7D04\u6570\u306E\u5217\
    \u6319\r\nvector<int> divisor(int n) {\r\n    vector<int> res;\r\n    for (int\
    \ i = 1; i * i <= n; i++) {\r\n        if (n % i == 0) {\r\n            res.push_back(i);\r\
    \n            if (i != n / i) res.push_back(n / i);\r\n        }\r\n    }\r\n\
    \    return res;\r\n}\r\n\r\n//\u7D20\u56E0\u6570\u5206\u89E3\r\nmap<int, int>\
    \ prime_factor(int n) {\r\n    map<int, int> res;\r\n    for (int i = 2; i * i\
    \ <= n; i++) {\r\n        while (n % i == 0) {\r\n            ++res[i];\r\n  \
    \          n /= i;\r\n        }\r\n    }\r\n    if (n != 1) res[n] = 1;\r\n  \
    \  return res;\r\n}\r\n\r\n//\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
    \r\nvector<bool> IsPrime;\r\nvector<int> primes;\r\n\r\nvoid sieve(int max) {\r\
    \n    IsPrime.resize(max + 1, true);\r\n    IsPrime[0] = IsPrime[1] = false;\r\
    \n    for (int i = 2; i * i <= max; ++i){\r\n        if (IsPrime[i]){\r\n    \
    \        for (int j = i * i; j <= max; j += i) IsPrime[j] = false;\r\n       \
    \ }\r\n    }\r\n    for(int i = 0; i <= max; ++i)if(IsPrime[i])primes.push_back(i);\r\
    \n}\r\n\r\n//\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\r\nvector<int> min_factor;\r\
    \n\r\nvoid f_sieve(int max){\r\n    IsPrime.resize(max + 1, true);\r\n    min_factor.resize(max\
    \ + 1, 0);\r\n    IsPrime[0] = IsPrime[1] = false;\r\n    min_factor[1] = 1;\r\
    \n    for (int i = 2; i <= max; ++i)\r\n        if (IsPrime[i]){\r\n         \
    \   primes.push_back(i);\r\n            for (ll j = ll(i) * i; j <= max; j +=\
    \ i){\r\n                IsPrime[j] = false;\r\n                min_factor[j]\
    \ = i;\r\n            }\r\n        }\r\n}\r\n\r\nmap<int, int> fast_prime_factor(int\
    \ n){\r\n    map<int, int> res;\r\n    while(n > 1){\r\n        int factor = min_factor[n];\r\
    \n        res[factor]++;\r\n        n /= factor;\r\n    }\r\n    return res;\r\
    \n}\n"
  code: "\r\n#include <vector>\r\n#include <map>\r\n\r\nusing namespace std;\r\n\r\
    \ntypedef long long ll;\r\n\r\n//\u7D20\u6570\u5224\u5B9A\r\nbool isprime(int\
    \ n) {\r\n    if (n % 2 == 0) return false;\r\n    for (int i = 3; i * i <= n;\
    \ i += 2) {\r\n        if (n % i == 0) return false;\r\n    }\r\n    return n\
    \ != 1;\r\n}\r\n\r\n//\u7D04\u6570\u306E\u5217\u6319\r\nvector<int> divisor(int\
    \ n) {\r\n    vector<int> res;\r\n    for (int i = 1; i * i <= n; i++) {\r\n \
    \       if (n % i == 0) {\r\n            res.push_back(i);\r\n            if (i\
    \ != n / i) res.push_back(n / i);\r\n        }\r\n    }\r\n    return res;\r\n\
    }\r\n\r\n//\u7D20\u56E0\u6570\u5206\u89E3\r\nmap<int, int> prime_factor(int n)\
    \ {\r\n    map<int, int> res;\r\n    for (int i = 2; i * i <= n; i++) {\r\n  \
    \      while (n % i == 0) {\r\n            ++res[i];\r\n            n /= i;\r\n\
    \        }\r\n    }\r\n    if (n != 1) res[n] = 1;\r\n    return res;\r\n}\r\n\
    \r\n//\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\r\nvector<bool> IsPrime;\r\
    \nvector<int> primes;\r\n\r\nvoid sieve(int max) {\r\n    IsPrime.resize(max +\
    \ 1, true);\r\n    IsPrime[0] = IsPrime[1] = false;\r\n    for (int i = 2; i *\
    \ i <= max; ++i){\r\n        if (IsPrime[i]){\r\n            for (int j = i *\
    \ i; j <= max; j += i) IsPrime[j] = false;\r\n        }\r\n    }\r\n    for(int\
    \ i = 0; i <= max; ++i)if(IsPrime[i])primes.push_back(i);\r\n}\r\n\r\n//\u9AD8\
    \u901F\u7D20\u56E0\u6570\u5206\u89E3\r\nvector<int> min_factor;\r\n\r\nvoid f_sieve(int\
    \ max){\r\n    IsPrime.resize(max + 1, true);\r\n    min_factor.resize(max + 1,\
    \ 0);\r\n    IsPrime[0] = IsPrime[1] = false;\r\n    min_factor[1] = 1;\r\n  \
    \  for (int i = 2; i <= max; ++i)\r\n        if (IsPrime[i]){\r\n            primes.push_back(i);\r\
    \n            for (ll j = ll(i) * i; j <= max; j += i){\r\n                IsPrime[j]\
    \ = false;\r\n                min_factor[j] = i;\r\n            }\r\n        }\r\
    \n}\r\n\r\nmap<int, int> fast_prime_factor(int n){\r\n    map<int, int> res;\r\
    \n    while(n > 1){\r\n        int factor = min_factor[n];\r\n        res[factor]++;\r\
    \n        n /= factor;\r\n    }\r\n    return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/prime.cpp
  requiredBy: []
  timestamp: '2018-11-19 11:33:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/prime.cpp
layout: document
redirect_from:
- /library/src/math/prime.cpp
- /library/src/math/prime.cpp.html
title: src/math/prime.cpp
---
