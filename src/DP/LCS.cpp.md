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
  bundledCode: "#line 1 \"src/DP/LCS.cpp\"\n/*\r\n\u6700\u9577\u5171\u901A\u90E8\u5206\
    \u5217(Longest Common Subsequence)\r\n\u8A08\u7B97\u91CF O(ST)\r\n*/\r\n\r\n#include\
    \ <string>\r\n#include <algorithm>\r\nusing namespace std;\r\n\r\nconst int MAX_N\
    \ = int(1e3) + 5;\r\n\r\nint dp[MAX_N][MAX_N];\r\nstring s, t;\r\n\r\nint lcs()\
    \ {\r\n    for (int i = 0; i <= s.size(); i++) fill(dp[i], dp[i] + t.size() +\
    \ 1, 0);\r\n    for (int i = 0; i < s.size(); i++) {\r\n        for (int j = 0;\
    \ j < t.size(); j++) {\r\n            if (s[i] == t[j]) {\r\n                dp[i\
    \ + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);\r\n            }\r\n    \
    \        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);\r\n         \
    \   dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);\r\n        }\r\n \
    \   }\r\n    return dp[s.size()][t.size()];\r\n}\r\n\r\n//\u5FA9\u5143\r\nstring\
    \ get_lcs() {\r\n    int i = s.size(), j = t.size();\r\n    string res = \"\"\
    ;\r\n    while (i > 0 && j > 0) {\r\n        if (dp[i][j - 1] == dp[i][j]) {\r\
    \n            j--;\r\n        } else if (dp[i - 1][j] == dp[i][j]) {\r\n     \
    \       i--;\r\n        } else {\r\n            res += s[i - 1];\r\n         \
    \   i--;\r\n            j--;\r\n        }\r\n    }\r\n    reverse(res.begin(),\
    \ res.end());\r\n    return res;\r\n}\r\n"
  code: "/*\r\n\u6700\u9577\u5171\u901A\u90E8\u5206\u5217(Longest Common Subsequence)\r\
    \n\u8A08\u7B97\u91CF O(ST)\r\n*/\r\n\r\n#include <string>\r\n#include <algorithm>\r\
    \nusing namespace std;\r\n\r\nconst int MAX_N = int(1e3) + 5;\r\n\r\nint dp[MAX_N][MAX_N];\r\
    \nstring s, t;\r\n\r\nint lcs() {\r\n    for (int i = 0; i <= s.size(); i++) fill(dp[i],\
    \ dp[i] + t.size() + 1, 0);\r\n    for (int i = 0; i < s.size(); i++) {\r\n  \
    \      for (int j = 0; j < t.size(); j++) {\r\n            if (s[i] == t[j]) {\r\
    \n                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);\r\n\
    \            }\r\n            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i +\
    \ 1][j]);\r\n            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);\r\
    \n        }\r\n    }\r\n    return dp[s.size()][t.size()];\r\n}\r\n\r\n//\u5FA9\
    \u5143\r\nstring get_lcs() {\r\n    int i = s.size(), j = t.size();\r\n    string\
    \ res = \"\";\r\n    while (i > 0 && j > 0) {\r\n        if (dp[i][j - 1] == dp[i][j])\
    \ {\r\n            j--;\r\n        } else if (dp[i - 1][j] == dp[i][j]) {\r\n\
    \            i--;\r\n        } else {\r\n            res += s[i - 1];\r\n    \
    \        i--;\r\n            j--;\r\n        }\r\n    }\r\n    reverse(res.begin(),\
    \ res.end());\r\n    return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DP/LCS.cpp
  requiredBy: []
  timestamp: '2018-06-24 10:01:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DP/LCS.cpp
layout: document
redirect_from:
- /library/src/DP/LCS.cpp
- /library/src/DP/LCS.cpp.html
title: src/DP/LCS.cpp
---
