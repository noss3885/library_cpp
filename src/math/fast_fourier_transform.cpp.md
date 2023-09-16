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
    - https://atcoder.jp/contests/atc001/tasks/fft_c
  bundledCode: "#line 1 \"src/math/fast_fourier_transform.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing Real = double;\n// using Complex = complex<Real>;\n\
    \nstruct Complex {\n    Real x, y;\n    Complex() : x(0), y(0){};\n    Complex(Real\
    \ x, Real y) : x(x), y(y){};\n};\n\ninline Complex conj(Complex a) {\n    return\
    \ Complex(a.x, -a.y);\n}\ninline Complex operator+(Complex a, Complex b) {\n \
    \   return Complex(a.x + b.x, a.y + b.y);\n}\ninline Complex operator-(Complex\
    \ a, Complex b) {\n    return Complex(a.x - b.x, a.y - b.y);\n}\ninline Complex\
    \ operator*(Complex a, Complex b) {\n    return Complex(a.x * b.x - a.y * b.y,\
    \ a.x * b.y + a.y * b.x);\n}\ninline Complex operator/(Complex a, Complex b) {\n\
    \    Complex tmp = a * conj(b);\n    return Complex(tmp.x / (b.x * b.x + b.y *\
    \ b.y), tmp.y / (b.x * b.x + b.y * b.y));\n}\n\nconst Real PI = acos(-1);\n\n\
    /*\nvector<Complex> DFT(vector<Complex> &a){\n    int n = a.size();\n    if(n\
    \ == 1) return a;\n\n    vector<Complex> a0(n>>1), a1(n>>1);\n\n    // \u5076\u5947\
    \u3067\u5206\u3051\u308B\n    for(int i=0;i<n;i++){\n        if(i&1) a1[i>>1]\
    \ = a[i];\n        else a0[i>>1] = a[i];\n    }\n    // \u5206\u5272\u7D71\u6CBB\
    \n    auto inversed_a0 = DFT(a0);\n    auto inversed_a1 = DFT(a1);\n\n    // f(x)\
    \ = f0(x^2) + x*f1(x^2)\n    vector<Complex> inversed_a(n);\n    for(int i=0;i<n;i++){\n\
    \        Real theta = 2*PI*i/n;\n        Complex zeta_n_i = Complex(cos(theta),\
    \ sin(theta));\n        inversed_a[i] = inversed_a0[i%(n>>1)] + zeta_n_i * inversed_a1[i%(n>>1)];\n\
    \    }\n    return inversed_a;\n}\n\nvector<Complex> IDFT(vector<Complex> &inversed_a){\n\
    \    int n = inversed_a.size();\n\n    auto arranged = DFT(inversed_a);\n\n  \
    \  // \u4FC2\u6570\u3092\u5165\u308C\u66FF\u3048\u3066n\u3067\u5272\u308B\n  \
    \  vector<Complex> a(n);\n    for(int i=0;i<n;i++){\n        a[i] = arranged[(n-i)%n]/Complex(n,0);\n\
    \    }\n    return a;\n}\n*/\n\n// W[i][j] = exp(root(-1)*2*PI*j/(2^i))\nvector<vector<Complex>>\
    \ W;\n\nvoid init(int n) {\n    int h = 0;\n    for (int i = 0; 1 << i < n; i++)\
    \ h++;\n    W.resize(h);\n    for (int i = 0; 1 << i < n; i++) {\n        int\
    \ d = 1 << i;\n        W[i].resize(d * 2 + 1);\n        for (int j = 0; j <= d\
    \ * 2; j++) {\n            if ((j & 1) || i == 0) {\n                Real theta\
    \ = 2 * PI / (d * 2) * j;\n                W[i][j] = Complex(cos(theta), sin(theta));\n\
    \            } else {\n                W[i][j] = W[i - 1][j >> 1];\n         \
    \   }\n        }\n    }\n}\n\nvector<Complex> FFT(vector<Complex> a, bool rev\
    \ = false) {\n    int n = a.size();\n    int h = 0;\n    for (int i = 0; 1 <<\
    \ i < n; i++) h++;\n    // bit\u3092\u9006\u8EE2\u3055\u305B\u5BFE\u5FDC\u3059\
    \u308B\u4F4D\u7F6E\u3068swap\n    for (int i = 0; i < n; i++) {\n        int j\
    \ = 0;\n        // j\u306Bi\u306Ebit\u3092\u9006\u8EE2\u3055\u305B\u305F\u3082\
    \u306E\n        for (int k = 0; k < h; k++) {\n            j |= (i >> k & 1) <<\
    \ (h - 1 - k);\n        }\n        if (i < j) swap(a[i], a[j]);\n    }\n\n   \
    \ for (int i = 0; 1 << i < n; i++) {\n        int d = 1 << i;\n        for (int\
    \ k = 0; k < n; k += d * 2) {\n            for (int j = 0; j < d; j++) {\n   \
    \             Complex s = a[j + k + 0];\n                Complex t = a[j + k +\
    \ d] * W[i][rev ? j : d * 2 - j];\n                a[j + k + 0] = s + t;\n   \
    \             a[j + k + d] = s - t;\n            }\n        }\n    }\n    if (rev)\n\
    \        for (int i = 0; i < n; i++) a[i] = a[i] / Complex(n, 0);\n    return\
    \ a;\n}\n\nvector<Complex> convolute(vector<Complex>& a, vector<Complex>& b) {\n\
    \    int deg = int(a.size() + b.size()) - 1;\n    int n = 1;\n    while (n < deg)\
    \ n <<= 1;\n    a.resize(n);\n    b.resize(n);\n    init(n);\n\n    vector<Complex>\
    \ inversed_a = FFT(a);\n    vector<Complex> inversed_b = FFT(b);\n    vector<Complex>\
    \ inversed_c(n);\n\n    for (int i = 0; i < n; i++) {\n        inversed_c[i] =\
    \ inversed_a[i] * inversed_b[i];\n    }\n    vector<Complex> c = FFT(inversed_c,\
    \ true);\n    return c;\n}\n\n// TEST\n// https://atcoder.jp/contests/atc001/tasks/fft_c\n\
    int main() {\n    int n;\n    scanf(\"%d\", &n);\n    vector<Complex> a(n + 1),\
    \ b(n + 1), c(n + 1);\n    for (int i = 1; i <= n; i++) {\n        double ai,\
    \ bi;\n        scanf(\"%lf\", &ai);\n        scanf(\"%lf\", &bi);\n        a[i]\
    \ = Complex(ai, 0);\n        b[i] = Complex(bi, 0);\n    }\n    c = convolute(a,\
    \ b);\n    for (int i = 1; i <= n * 2; i++) {\n        printf(\"%d\\n\", int(c[i].x\
    \ + .1));\n    }\n    return 0;\n}\n"
  code: "\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Real = double;\n\
    // using Complex = complex<Real>;\n\nstruct Complex {\n    Real x, y;\n    Complex()\
    \ : x(0), y(0){};\n    Complex(Real x, Real y) : x(x), y(y){};\n};\n\ninline Complex\
    \ conj(Complex a) {\n    return Complex(a.x, -a.y);\n}\ninline Complex operator+(Complex\
    \ a, Complex b) {\n    return Complex(a.x + b.x, a.y + b.y);\n}\ninline Complex\
    \ operator-(Complex a, Complex b) {\n    return Complex(a.x - b.x, a.y - b.y);\n\
    }\ninline Complex operator*(Complex a, Complex b) {\n    return Complex(a.x *\
    \ b.x - a.y * b.y, a.x * b.y + a.y * b.x);\n}\ninline Complex operator/(Complex\
    \ a, Complex b) {\n    Complex tmp = a * conj(b);\n    return Complex(tmp.x /\
    \ (b.x * b.x + b.y * b.y), tmp.y / (b.x * b.x + b.y * b.y));\n}\n\nconst Real\
    \ PI = acos(-1);\n\n/*\nvector<Complex> DFT(vector<Complex> &a){\n    int n =\
    \ a.size();\n    if(n == 1) return a;\n\n    vector<Complex> a0(n>>1), a1(n>>1);\n\
    \n    // \u5076\u5947\u3067\u5206\u3051\u308B\n    for(int i=0;i<n;i++){\n   \
    \     if(i&1) a1[i>>1] = a[i];\n        else a0[i>>1] = a[i];\n    }\n    // \u5206\
    \u5272\u7D71\u6CBB\n    auto inversed_a0 = DFT(a0);\n    auto inversed_a1 = DFT(a1);\n\
    \n    // f(x) = f0(x^2) + x*f1(x^2)\n    vector<Complex> inversed_a(n);\n    for(int\
    \ i=0;i<n;i++){\n        Real theta = 2*PI*i/n;\n        Complex zeta_n_i = Complex(cos(theta),\
    \ sin(theta));\n        inversed_a[i] = inversed_a0[i%(n>>1)] + zeta_n_i * inversed_a1[i%(n>>1)];\n\
    \    }\n    return inversed_a;\n}\n\nvector<Complex> IDFT(vector<Complex> &inversed_a){\n\
    \    int n = inversed_a.size();\n\n    auto arranged = DFT(inversed_a);\n\n  \
    \  // \u4FC2\u6570\u3092\u5165\u308C\u66FF\u3048\u3066n\u3067\u5272\u308B\n  \
    \  vector<Complex> a(n);\n    for(int i=0;i<n;i++){\n        a[i] = arranged[(n-i)%n]/Complex(n,0);\n\
    \    }\n    return a;\n}\n*/\n\n// W[i][j] = exp(root(-1)*2*PI*j/(2^i))\nvector<vector<Complex>>\
    \ W;\n\nvoid init(int n) {\n    int h = 0;\n    for (int i = 0; 1 << i < n; i++)\
    \ h++;\n    W.resize(h);\n    for (int i = 0; 1 << i < n; i++) {\n        int\
    \ d = 1 << i;\n        W[i].resize(d * 2 + 1);\n        for (int j = 0; j <= d\
    \ * 2; j++) {\n            if ((j & 1) || i == 0) {\n                Real theta\
    \ = 2 * PI / (d * 2) * j;\n                W[i][j] = Complex(cos(theta), sin(theta));\n\
    \            } else {\n                W[i][j] = W[i - 1][j >> 1];\n         \
    \   }\n        }\n    }\n}\n\nvector<Complex> FFT(vector<Complex> a, bool rev\
    \ = false) {\n    int n = a.size();\n    int h = 0;\n    for (int i = 0; 1 <<\
    \ i < n; i++) h++;\n    // bit\u3092\u9006\u8EE2\u3055\u305B\u5BFE\u5FDC\u3059\
    \u308B\u4F4D\u7F6E\u3068swap\n    for (int i = 0; i < n; i++) {\n        int j\
    \ = 0;\n        // j\u306Bi\u306Ebit\u3092\u9006\u8EE2\u3055\u305B\u305F\u3082\
    \u306E\n        for (int k = 0; k < h; k++) {\n            j |= (i >> k & 1) <<\
    \ (h - 1 - k);\n        }\n        if (i < j) swap(a[i], a[j]);\n    }\n\n   \
    \ for (int i = 0; 1 << i < n; i++) {\n        int d = 1 << i;\n        for (int\
    \ k = 0; k < n; k += d * 2) {\n            for (int j = 0; j < d; j++) {\n   \
    \             Complex s = a[j + k + 0];\n                Complex t = a[j + k +\
    \ d] * W[i][rev ? j : d * 2 - j];\n                a[j + k + 0] = s + t;\n   \
    \             a[j + k + d] = s - t;\n            }\n        }\n    }\n    if (rev)\n\
    \        for (int i = 0; i < n; i++) a[i] = a[i] / Complex(n, 0);\n    return\
    \ a;\n}\n\nvector<Complex> convolute(vector<Complex>& a, vector<Complex>& b) {\n\
    \    int deg = int(a.size() + b.size()) - 1;\n    int n = 1;\n    while (n < deg)\
    \ n <<= 1;\n    a.resize(n);\n    b.resize(n);\n    init(n);\n\n    vector<Complex>\
    \ inversed_a = FFT(a);\n    vector<Complex> inversed_b = FFT(b);\n    vector<Complex>\
    \ inversed_c(n);\n\n    for (int i = 0; i < n; i++) {\n        inversed_c[i] =\
    \ inversed_a[i] * inversed_b[i];\n    }\n    vector<Complex> c = FFT(inversed_c,\
    \ true);\n    return c;\n}\n\n// TEST\n// https://atcoder.jp/contests/atc001/tasks/fft_c\n\
    int main() {\n    int n;\n    scanf(\"%d\", &n);\n    vector<Complex> a(n + 1),\
    \ b(n + 1), c(n + 1);\n    for (int i = 1; i <= n; i++) {\n        double ai,\
    \ bi;\n        scanf(\"%lf\", &ai);\n        scanf(\"%lf\", &bi);\n        a[i]\
    \ = Complex(ai, 0);\n        b[i] = Complex(bi, 0);\n    }\n    c = convolute(a,\
    \ b);\n    for (int i = 1; i <= n * 2; i++) {\n        printf(\"%d\\n\", int(c[i].x\
    \ + .1));\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/fast_fourier_transform.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/fast_fourier_transform.cpp
layout: document
redirect_from:
- /library/src/math/fast_fourier_transform.cpp
- /library/src/math/fast_fourier_transform.cpp.html
title: src/math/fast_fourier_transform.cpp
---
