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
  bundledCode: "#line 1 \"src/other/timer.cpp\"\n#include<chrono>\r\n\r\nclass Timer{\r\
    \nprivate:\r\n    std::chrono::system_clock::time_point start_time, end_time;\r\
    \npublic:\r\n    Timer():start_time(std::chrono::system_clock::now()){}\r\n  \
    \  void start(){\r\n        start_time = std::chrono::system_clock::now();\r\n\
    \    }\r\n    double elapsed(){\r\n        end_time = std::chrono::system_clock::now();\r\
    \n        return static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count());\r\
    \n    }\r\n};\n"
  code: "#include<chrono>\r\n\r\nclass Timer{\r\nprivate:\r\n    std::chrono::system_clock::time_point\
    \ start_time, end_time;\r\npublic:\r\n    Timer():start_time(std::chrono::system_clock::now()){}\r\
    \n    void start(){\r\n        start_time = std::chrono::system_clock::now();\r\
    \n    }\r\n    double elapsed(){\r\n        end_time = std::chrono::system_clock::now();\r\
    \n        return static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count());\r\
    \n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/other/timer.cpp
  requiredBy: []
  timestamp: '2020-04-10 09:39:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/other/timer.cpp
layout: document
redirect_from:
- /library/src/other/timer.cpp
- /library/src/other/timer.cpp.html
title: src/other/timer.cpp
---
