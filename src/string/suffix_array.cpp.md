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
  bundledCode: "#line 1 \"src/string/suffix_array.cpp\"\n// Suffix Array\n// construct\
    \ O(|S|(log|S|)^2)\n// contain O(|T|log|S|)\n//\n// Longest Common Prefix Array\n\
    // construct O(|S|)\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n// BEGIN\n\
    \nstruct SuffixArray {\n    int n, k;\n    string s;\n    vector<int> rank, tmp,\
    \ sa;\n\n    function<bool(const int&, const int&)> comp = [&](const int& i, const\
    \ int& j) {\n        if (rank[i] != rank[j])\n            return rank[i] < rank[j];\n\
    \        else {\n            int ri = i + k <= n ? rank[i + k] : -1;\n       \
    \     int rj = j + k <= n ? rank[j + k] : -1;\n            return ri < rj;\n \
    \       }\n    };\n    void construct(const string& str) {\n        s = str;\n\
    \        n = s.size();\n        rank.resize(n + 1);\n        tmp.resize(n + 1);\n\
    \        sa.resize(n + 1);\n\n        for (int i = 0; i <= n; i++) {\n       \
    \     sa[i] = i;\n            rank[i] = i < n ? s[i] : -1;\n        }\n\n    \
    \    for (k = 1; k <= n; k <<= 1) {\n            sort(sa.begin(), sa.begin() +\
    \ n + 1, comp);\n            tmp[sa[0]] = 0;\n            for (int i = 1; i <=\
    \ n; i++) {\n                tmp[sa[i]] = tmp[sa[i - 1]] + (comp(sa[i - 1], sa[i])\
    \ ? 1 : 0);\n            }\n            for (int i = 0; i <= n; i++) {\n     \
    \           rank[i] = tmp[i];\n            }\n        }\n    }\n    bool contain(const\
    \ string& t) {\n        int a = 0, b = n;\n        while (b - a > 1) {\n     \
    \       int c = (a + b) / 2;\n            if (s.compare(sa[c], t.size(), t) <\
    \ 0) {\n                a = c;\n            } else {\n                b = c;\n\
    \            }\n        }\n        return s.compare(sa[b], t.size(), t) == 0;\n\
    \    }\n    // \u8F9E\u66F8\u9806\u3067i\u756A\u76EE\u3067\u3042\u308Bsuffix\u306E\
    \u958B\u59CB\u4F4D\u7F6E\n    int operator[](int i) const {\n        return sa[i];\n\
    \    }\n};\n\nstruct LCP {\n    int n;\n    vector<int> rank;\n    vector<int>\
    \ lcp;\n    SuffixArray sa;\n\n    void construct(const string& str) {\n     \
    \   int n = str.size();\n        sa.construct(str);\n        rank.resize(n + 1);\
    \  // rank[i]=\u958B\u59CB\u4F4D\u7F6E\u304Ci\u3067\u3042\u308Bsuffix\u306E\u8F9E\
    \u66F8\u9806\u4F4D\u7F6E\n        lcp.resize(n);       // sa[i]\u3068sa[i+1]\u306E\
    \ common prefix \u306E\u9577\u3055\n        for (int i = 0; i <= n; i++) rank[sa[i]]\
    \ = i;\n\n        int h = 0;\n        for (int i = 0; i < n; i++) {\n        \
    \    int j = sa[rank[i] - 1];\n            if (h > 0) h--;\n            for (;\
    \ j + h < n && i + h < n; h++) {\n                if (str[j + h] != str[i + h])\
    \ break;\n            }\n            lcp[rank[i] - 1] = h;\n        }\n    }\n\
    \    int operator[](int i) const {\n        return lcp[i];\n    }\n};\n\n// END\n"
  code: "// Suffix Array\n// construct O(|S|(log|S|)^2)\n// contain O(|T|log|S|)\n\
    //\n// Longest Common Prefix Array\n// construct O(|S|)\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// BEGIN\n\nstruct SuffixArray {\n    int n, k;\n    string\
    \ s;\n    vector<int> rank, tmp, sa;\n\n    function<bool(const int&, const int&)>\
    \ comp = [&](const int& i, const int& j) {\n        if (rank[i] != rank[j])\n\
    \            return rank[i] < rank[j];\n        else {\n            int ri = i\
    \ + k <= n ? rank[i + k] : -1;\n            int rj = j + k <= n ? rank[j + k]\
    \ : -1;\n            return ri < rj;\n        }\n    };\n    void construct(const\
    \ string& str) {\n        s = str;\n        n = s.size();\n        rank.resize(n\
    \ + 1);\n        tmp.resize(n + 1);\n        sa.resize(n + 1);\n\n        for\
    \ (int i = 0; i <= n; i++) {\n            sa[i] = i;\n            rank[i] = i\
    \ < n ? s[i] : -1;\n        }\n\n        for (k = 1; k <= n; k <<= 1) {\n    \
    \        sort(sa.begin(), sa.begin() + n + 1, comp);\n            tmp[sa[0]] =\
    \ 0;\n            for (int i = 1; i <= n; i++) {\n                tmp[sa[i]] =\
    \ tmp[sa[i - 1]] + (comp(sa[i - 1], sa[i]) ? 1 : 0);\n            }\n        \
    \    for (int i = 0; i <= n; i++) {\n                rank[i] = tmp[i];\n     \
    \       }\n        }\n    }\n    bool contain(const string& t) {\n        int\
    \ a = 0, b = n;\n        while (b - a > 1) {\n            int c = (a + b) / 2;\n\
    \            if (s.compare(sa[c], t.size(), t) < 0) {\n                a = c;\n\
    \            } else {\n                b = c;\n            }\n        }\n    \
    \    return s.compare(sa[b], t.size(), t) == 0;\n    }\n    // \u8F9E\u66F8\u9806\
    \u3067i\u756A\u76EE\u3067\u3042\u308Bsuffix\u306E\u958B\u59CB\u4F4D\u7F6E\n  \
    \  int operator[](int i) const {\n        return sa[i];\n    }\n};\n\nstruct LCP\
    \ {\n    int n;\n    vector<int> rank;\n    vector<int> lcp;\n    SuffixArray\
    \ sa;\n\n    void construct(const string& str) {\n        int n = str.size();\n\
    \        sa.construct(str);\n        rank.resize(n + 1);  // rank[i]=\u958B\u59CB\
    \u4F4D\u7F6E\u304Ci\u3067\u3042\u308Bsuffix\u306E\u8F9E\u66F8\u9806\u4F4D\u7F6E\
    \n        lcp.resize(n);       // sa[i]\u3068sa[i+1]\u306E common prefix \u306E\
    \u9577\u3055\n        for (int i = 0; i <= n; i++) rank[sa[i]] = i;\n\n      \
    \  int h = 0;\n        for (int i = 0; i < n; i++) {\n            int j = sa[rank[i]\
    \ - 1];\n            if (h > 0) h--;\n            for (; j + h < n && i + h <\
    \ n; h++) {\n                if (str[j + h] != str[i + h]) break;\n          \
    \  }\n            lcp[rank[i] - 1] = h;\n        }\n    }\n    int operator[](int\
    \ i) const {\n        return lcp[i];\n    }\n};\n\n// END"
  dependsOn: []
  isVerificationFile: false
  path: src/string/suffix_array.cpp
  requiredBy: []
  timestamp: '2023-09-16 13:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/suffix_array.cpp
layout: document
redirect_from:
- /library/src/string/suffix_array.cpp
- /library/src/string/suffix_array.cpp.html
title: src/string/suffix_array.cpp
---
