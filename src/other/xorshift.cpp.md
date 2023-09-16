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
  bundledCode: "#line 1 \"src/other/xorshift.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// \u5468\u671F 2^128-1\nuint32_t xorshift(void) {\n    static\
    \ uint32_t x = 123456789;\n    static uint32_t y = 362436069;\n    static uint32_t\
    \ z = 521288629;\n    static uint32_t w = 88675123;\n    uint32_t t;\n\n    t\
    \ = x ^ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n    return w = (w ^ (w\
    \ >> 19)) ^ (t ^ (t >> 8));\n}\n\nstruct Random {\n    using uint = unsigned int;\n\
    \    uint x = 123456789;\n    uint y = 362436069;\n    uint z = 521288629;\n \
    \   uint w = 88675123;\n    uint t;\n\n    uint rand() {\n        t = x ^ (x <<\
    \ 11);\n        x = y;\n        y = z;\n        z = w;\n        return w = (w\
    \ ^ (w >> 19)) ^ (t ^ (t >> 8));\n    }\n    // [0,1)\n    double randFloat()\
    \ {\n        return static_cast<double>(rand() % 0x10000) / static_cast<double>(0x10000);\n\
    \    }\n    // [aMin,aMax)\n    double randFloat(double aMin, double aMax) {\n\
    \        return aMin + randFloat() * (aMax - aMin);\n    }\n    void spin(int\
    \ n) {\n        for (; n > 0; --n) (void)rand();\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// \u5468\u671F 2^128-1\n\
    uint32_t xorshift(void) {\n    static uint32_t x = 123456789;\n    static uint32_t\
    \ y = 362436069;\n    static uint32_t z = 521288629;\n    static uint32_t w =\
    \ 88675123;\n    uint32_t t;\n\n    t = x ^ (x << 11);\n    x = y;\n    y = z;\n\
    \    z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n}\n\nstruct Random\
    \ {\n    using uint = unsigned int;\n    uint x = 123456789;\n    uint y = 362436069;\n\
    \    uint z = 521288629;\n    uint w = 88675123;\n    uint t;\n\n    uint rand()\
    \ {\n        t = x ^ (x << 11);\n        x = y;\n        y = z;\n        z = w;\n\
    \        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n    }\n    // [0,1)\n \
    \   double randFloat() {\n        return static_cast<double>(rand() % 0x10000)\
    \ / static_cast<double>(0x10000);\n    }\n    // [aMin,aMax)\n    double randFloat(double\
    \ aMin, double aMax) {\n        return aMin + randFloat() * (aMax - aMin);\n \
    \   }\n    void spin(int n) {\n        for (; n > 0; --n) (void)rand();\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/other/xorshift.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/other/xorshift.cpp
layout: document
redirect_from:
- /library/src/other/xorshift.cpp
- /library/src/other/xorshift.cpp.html
title: src/other/xorshift.cpp
---
