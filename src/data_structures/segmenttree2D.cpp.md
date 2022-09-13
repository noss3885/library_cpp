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
  bundledCode: "#line 1 \"src/data_structures/segmenttree2D.cpp\"\n#include <vector>\r\
    \n#include <algorithm>\r\n\r\nusing namespace std;\r\n\r\nstruct segtree {\r\n\
    \    int H, W;\r\n    const int inf = 99999999;\r\n    vector<vector<int>> dat;\r\
    \n    segtree() {}\r\n    segtree(vector<vector<int>> &f) {\r\n        H = W =\
    \ 1;\r\n        while (H < (int)f.size()) H <<= 1;\r\n        while (W < (int)f[0].size())\
    \ W <<= 1;\r\n        dat.assign(2 * H - 1, vector<int>(2 * W - 1, inf));\r\n\
    \        init(f);\r\n    }\r\n    void init(vector<vector<int>> &f) {\r\n    \
    \    for (int i = 0; i < (int)f.size(); i++)\r\n            for (int j = 0; j\
    \ < (int)f[0].size(); j++)\r\n                dat[i + H - 1][j + W - 1] = f[i][j];\r\
    \n        for (int i = 2 * H - 2; i > H - 2; i--)\r\n            for (int j =\
    \ W - 2; j >= 0; j--)\r\n                dat[i][j] = min(dat[i][2 * j + 1], dat[i][2\
    \ * j + 2]);\r\n        for (int i = H - 2; i >= 0; i--)\r\n            for (int\
    \ j = 0; j < 2 * W - 1; j++)\r\n                dat[i][j] = min(dat[2 * i + 1][j],\
    \ dat[2 * i + 2][j]);\r\n    }\r\n    int minimum(int li, int lj, int ri, int\
    \ rj) {\r\n        return minimum_h(li, lj, ri, rj, 0, H, 0);\r\n    }\r\n   \
    \ int minimum_h(int li, int lj, int ri, int rj, int si, int ti, int k) {\r\n \
    \       if (ri <= si || ti <= li) return inf;\r\n        if (li <= si && ti <=\
    \ ri) return minimum_w(lj, rj, 0, W, k, 0);\r\n        const int mi = (si + ti)\
    \ / 2;\r\n        return min(minimum_h(li, lj, ri, rj, si, mi, 2 * k + 1),\r\n\
    \                   minimum_h(li, lj, ri, rj, mi, ti, 2 * k + 2));\r\n    }\r\n\
    \    int minimum_w(int lj, int rj, int sj, int tj, int i, int k) {\r\n       \
    \ if (rj <= sj || tj <= lj) return inf;\r\n        if (lj <= sj && tj <= rj) return\
    \ dat[i][k];\r\n        const int mj = (sj + tj) / 2;\r\n        return min(minimum_w(lj,\
    \ rj, sj, mj, i, 2 * k + 1),\r\n                   minimum_w(lj, rj, mj, tj, i,\
    \ 2 * k + 2));\r\n    }\r\n};\n"
  code: "#include <vector>\r\n#include <algorithm>\r\n\r\nusing namespace std;\r\n\
    \r\nstruct segtree {\r\n    int H, W;\r\n    const int inf = 99999999;\r\n   \
    \ vector<vector<int>> dat;\r\n    segtree() {}\r\n    segtree(vector<vector<int>>\
    \ &f) {\r\n        H = W = 1;\r\n        while (H < (int)f.size()) H <<= 1;\r\n\
    \        while (W < (int)f[0].size()) W <<= 1;\r\n        dat.assign(2 * H - 1,\
    \ vector<int>(2 * W - 1, inf));\r\n        init(f);\r\n    }\r\n    void init(vector<vector<int>>\
    \ &f) {\r\n        for (int i = 0; i < (int)f.size(); i++)\r\n            for\
    \ (int j = 0; j < (int)f[0].size(); j++)\r\n                dat[i + H - 1][j +\
    \ W - 1] = f[i][j];\r\n        for (int i = 2 * H - 2; i > H - 2; i--)\r\n   \
    \         for (int j = W - 2; j >= 0; j--)\r\n                dat[i][j] = min(dat[i][2\
    \ * j + 1], dat[i][2 * j + 2]);\r\n        for (int i = H - 2; i >= 0; i--)\r\n\
    \            for (int j = 0; j < 2 * W - 1; j++)\r\n                dat[i][j]\
    \ = min(dat[2 * i + 1][j], dat[2 * i + 2][j]);\r\n    }\r\n    int minimum(int\
    \ li, int lj, int ri, int rj) {\r\n        return minimum_h(li, lj, ri, rj, 0,\
    \ H, 0);\r\n    }\r\n    int minimum_h(int li, int lj, int ri, int rj, int si,\
    \ int ti, int k) {\r\n        if (ri <= si || ti <= li) return inf;\r\n      \
    \  if (li <= si && ti <= ri) return minimum_w(lj, rj, 0, W, k, 0);\r\n       \
    \ const int mi = (si + ti) / 2;\r\n        return min(minimum_h(li, lj, ri, rj,\
    \ si, mi, 2 * k + 1),\r\n                   minimum_h(li, lj, ri, rj, mi, ti,\
    \ 2 * k + 2));\r\n    }\r\n    int minimum_w(int lj, int rj, int sj, int tj, int\
    \ i, int k) {\r\n        if (rj <= sj || tj <= lj) return inf;\r\n        if (lj\
    \ <= sj && tj <= rj) return dat[i][k];\r\n        const int mj = (sj + tj) / 2;\r\
    \n        return min(minimum_w(lj, rj, sj, mj, i, 2 * k + 1),\r\n            \
    \       minimum_w(lj, rj, mj, tj, i, 2 * k + 2));\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/segmenttree2D.cpp
  requiredBy: []
  timestamp: '2018-05-24 17:23:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structures/segmenttree2D.cpp
layout: document
redirect_from:
- /library/src/data_structures/segmenttree2D.cpp
- /library/src/data_structures/segmenttree2D.cpp.html
title: src/data_structures/segmenttree2D.cpp
---
