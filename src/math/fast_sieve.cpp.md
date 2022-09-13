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
  bundledCode: "#line 1 \"src/math/fast_sieve.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// N=1e8 150ms\n// N=1e9 1500ms\n\n// BEGIN\n\nconstexpr uint64_t\
    \ MAX_N = 1e8+5;\nconstexpr uint32_t b64 = 6;\n\nuint64_t flag[MAX_N];\n\nvoid\
    \ reset_flag(uint64_t i){\n    flag[i>>b64] &= ~(1ULL<<(i&((1ULL<<b64)-1)));\n\
    }\n\nbool get_flag(uint64_t i){\n    return (flag[i>>b64]>>(i&((1ULL<<b64)-1)))&1;\n\
    }\n\nbool isPrime(int n){\n    if(n <= 1) return false;\n    if(n == 2) return\
    \ true;\n    else return n&1 && get_flag(n/2);\n}\n\nvoid sieve(const int64_t\
    \ n){\n    const uint64_t siz = n/2, sqrtN = ceil(sqrt(n)+0.1)/2;\n    const uint64_t\
    \ B = 1<<20;\n    fill(flag, flag+(siz>>b64)+1, -1);\n    for(uint64_t l=1; l<=siz;\
    \ l+=B){\n        const uint64_t r = min(l+B, siz), sqrtR = ceil(sqrt(r*2+1)+0.1)/2;\n\
    \        for(uint64_t i=1; i<=sqrtR; ++i){\n            if(get_flag(i)){\n   \
    \             const uint64_t p = 2*i+1;\n                uint64_t s;\n       \
    \         if(l < 2*i*(i+1)) s = 2*i*(i+1);\n                else if((2*l+1)%p\
    \ == 0) s = l;\n                else {\n                    s = (2*l+1) - (2*l+1)%p\
    \ + p;\n                    if(s%2==0) s+=p;\n                    s /= 2;\n  \
    \              }\n                for(uint64_t j = s; j<=r; j+=p){\n         \
    \           reset_flag(j);\n                }\n            }\n        }\n    }\n\
    }\n\n// END\n\n// simple ver.\n// N=1e8 150ms\n// N=1e9 3500ms\n/*\nvoid sieve(const\
    \ int64_t n){\n    const uint64_t siz = n/2, sqrtN = ceil(sqrt(n)+0.1)/2;\n  \
    \  fill(flag, flag+(siz>>b64)+1, -1);\n    for(uint64_t i=1; i<=sqrtN; ++i){\n\
    \        if(get_flag(i)){\n            const uint64_t p = 2*i+1;\n           \
    \ for(uint64_t j = 2*i*(i+1); j<=siz; j+=p){\n                reset_flag(j);\n\
    \            }\n        }\n    }\n}\n*/\n\n\n// TEST\nint main() {\n    int N\
    \ = 1e8;\n    sieve(N);\n\n     // \u7D20\u6570\u30AB\u30A6\u30F3\u30C8\n    int\
    \ cnt = 1;\n    for(int i=3;i<=N;i+=2){\n        if(isPrime(i))cnt++;\n    }\n\
    \    cout << cnt << endl;\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// N=1e8 150ms\n// N=1e9\
    \ 1500ms\n\n// BEGIN\n\nconstexpr uint64_t MAX_N = 1e8+5;\nconstexpr uint32_t\
    \ b64 = 6;\n\nuint64_t flag[MAX_N];\n\nvoid reset_flag(uint64_t i){\n    flag[i>>b64]\
    \ &= ~(1ULL<<(i&((1ULL<<b64)-1)));\n}\n\nbool get_flag(uint64_t i){\n    return\
    \ (flag[i>>b64]>>(i&((1ULL<<b64)-1)))&1;\n}\n\nbool isPrime(int n){\n    if(n\
    \ <= 1) return false;\n    if(n == 2) return true;\n    else return n&1 && get_flag(n/2);\n\
    }\n\nvoid sieve(const int64_t n){\n    const uint64_t siz = n/2, sqrtN = ceil(sqrt(n)+0.1)/2;\n\
    \    const uint64_t B = 1<<20;\n    fill(flag, flag+(siz>>b64)+1, -1);\n    for(uint64_t\
    \ l=1; l<=siz; l+=B){\n        const uint64_t r = min(l+B, siz), sqrtR = ceil(sqrt(r*2+1)+0.1)/2;\n\
    \        for(uint64_t i=1; i<=sqrtR; ++i){\n            if(get_flag(i)){\n   \
    \             const uint64_t p = 2*i+1;\n                uint64_t s;\n       \
    \         if(l < 2*i*(i+1)) s = 2*i*(i+1);\n                else if((2*l+1)%p\
    \ == 0) s = l;\n                else {\n                    s = (2*l+1) - (2*l+1)%p\
    \ + p;\n                    if(s%2==0) s+=p;\n                    s /= 2;\n  \
    \              }\n                for(uint64_t j = s; j<=r; j+=p){\n         \
    \           reset_flag(j);\n                }\n            }\n        }\n    }\n\
    }\n\n// END\n\n// simple ver.\n// N=1e8 150ms\n// N=1e9 3500ms\n/*\nvoid sieve(const\
    \ int64_t n){\n    const uint64_t siz = n/2, sqrtN = ceil(sqrt(n)+0.1)/2;\n  \
    \  fill(flag, flag+(siz>>b64)+1, -1);\n    for(uint64_t i=1; i<=sqrtN; ++i){\n\
    \        if(get_flag(i)){\n            const uint64_t p = 2*i+1;\n           \
    \ for(uint64_t j = 2*i*(i+1); j<=siz; j+=p){\n                reset_flag(j);\n\
    \            }\n        }\n    }\n}\n*/\n\n\n// TEST\nint main() {\n    int N\
    \ = 1e8;\n    sieve(N);\n\n     // \u7D20\u6570\u30AB\u30A6\u30F3\u30C8\n    int\
    \ cnt = 1;\n    for(int i=3;i<=N;i+=2){\n        if(isPrime(i))cnt++;\n    }\n\
    \    cout << cnt << endl;\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/fast_sieve.cpp
  requiredBy: []
  timestamp: '2019-06-07 10:58:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/fast_sieve.cpp
layout: document
redirect_from:
- /library/src/math/fast_sieve.cpp
- /library/src/math/fast_sieve.cpp.html
title: src/math/fast_sieve.cpp
---
