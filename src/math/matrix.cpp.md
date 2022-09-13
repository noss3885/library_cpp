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
  bundledCode: "#line 1 \"src/math/matrix.cpp\"\n/*\n\u884C\u5217\u6F14\u7B97\u30E9\
    \u30A4\u30D6\u30E9\u30EA\n\u8981\u7D20\u306E\u578B\u306F+\u3068*\u304C\u5B9A\u7FA9\
    \u3055\u308C\u3066\u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\n*/\n#include <cassert>\n\
    #include <iostream>\n#include <vector>\n\n// BEGIN\n\nusing ll = long long int;\n\
    \ntemplate <typename T> struct Matrix {\n    using vec = std::vector<T>;\n\n \
    \   std::vector<vec> mat;\n    size_t m_rows = 0, m_columns = 0;\n\n    Matrix()\
    \ = default;\n    Matrix(size_t r, size_t c) : m_rows(r), m_columns(c), mat(r,\
    \ vec(c)) {}\n    Matrix(size_t r, size_t c, T e)\n        : m_rows(r), m_columns(c),\
    \ mat(r, vec(c, e)) {}\n\n    size_t rows() const { return m_rows; }\n    size_t\
    \ columns() const { return m_columns; }\n\n    vec& operator[](size_t i) { return\
    \ mat[i]; }\n    vec const& operator[](size_t i) const { return mat[i]; }\n\n\
    \    Matrix& operator+=(const Matrix& rhs) {\n        for (int i = 0; i < m_rows;\
    \ i++) {\n            for (int j = 0; j < m_columns; j++) {\n                mat[i][j]\
    \ = mat[i][j] + rhs[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n    Matrix& operator-=(const Matrix& rhs) {\n        for (int i = 0; i\
    \ < m_rows; i++) {\n            for (int j = 0; j < m_columns; j++) {\n      \
    \          mat[i][j] = mat[i][j] - rhs[i][j];\n            }\n        }\n    \
    \    return *this;\n    }\n    Matrix& operator*=(const Matrix& rhs) {\n     \
    \   assert(m_columns == rhs.rows());\n        Matrix res(m_rows, rhs.columns());\n\
    \        for (int i = 0; i < m_rows; i++) {\n            for (int k = 0; k < rhs.rows();\
    \ k++) {\n                for (int j = 0; j < m_columns; j++) {\n            \
    \        res[i][j] = res[i][j] + mat[i][k] * rhs[k][j];\n                }\n \
    \           }\n        }\n        (*this) = res;\n        return *this;\n    }\n\
    \    Matrix operator+(const Matrix& rhs) const { return Matrix(*this) += rhs;\
    \ }\n    Matrix operator-(const Matrix& rhs) const { return Matrix(*this) -= rhs;\
    \ }\n    Matrix operator*(const Matrix& rhs) const { return Matrix(*this) *= rhs;\
    \ }\n\n    friend std::ostream& operator<<(std::ostream& os, Matrix& dat) {\n\
    \        for (int i = 0; i < dat.rows(); i++) {\n            os << (i == 0 ? '['\
    \ : ' ');\n            for (int j = 0; j < dat.columns(); j++) {\n           \
    \     if (j > 0) os << \",\";\n                os << dat[i][j];\n            }\n\
    \            os << (i + 1 < dat.rows() ? \";\\n\" : \"]\");\n        }\n     \
    \   return os;\n    }\n    static Matrix identity(size_t n, T e0, T e1) {\n  \
    \      Matrix res(n, n, e0);\n        for (int i = 0; i < int(n); i++) res[i][i]\
    \ = e1;\n        return res;\n    }\n};\n\n// \u884C\u5217\u7D2F\u4E57 O(N^3 log\
    \ k)\ntemplate <typename T> Matrix<T> mat_power(Matrix<T> x, ll k, T e0, T e1)\
    \ {\n    Matrix<T> res = Matrix::identity(x.rows(), e0, e1);\n    while (k > 0)\
    \ {\n        if (k & 1LL) {\n            res = x * res;\n        }\n        x\
    \ = x * x;\n        k >>= 1;\n    }\n    return res;\n}\n\n// END\n"
  code: "/*\n\u884C\u5217\u6F14\u7B97\u30E9\u30A4\u30D6\u30E9\u30EA\n\u8981\u7D20\u306E\
    \u578B\u306F+\u3068*\u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B\u5FC5\u8981\
    \u304C\u3042\u308B\n*/\n#include <cassert>\n#include <iostream>\n#include <vector>\n\
    \n// BEGIN\n\nusing ll = long long int;\n\ntemplate <typename T> struct Matrix\
    \ {\n    using vec = std::vector<T>;\n\n    std::vector<vec> mat;\n    size_t\
    \ m_rows = 0, m_columns = 0;\n\n    Matrix() = default;\n    Matrix(size_t r,\
    \ size_t c) : m_rows(r), m_columns(c), mat(r, vec(c)) {}\n    Matrix(size_t r,\
    \ size_t c, T e)\n        : m_rows(r), m_columns(c), mat(r, vec(c, e)) {}\n\n\
    \    size_t rows() const { return m_rows; }\n    size_t columns() const { return\
    \ m_columns; }\n\n    vec& operator[](size_t i) { return mat[i]; }\n    vec const&\
    \ operator[](size_t i) const { return mat[i]; }\n\n    Matrix& operator+=(const\
    \ Matrix& rhs) {\n        for (int i = 0; i < m_rows; i++) {\n            for\
    \ (int j = 0; j < m_columns; j++) {\n                mat[i][j] = mat[i][j] + rhs[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n    Matrix& operator-=(const\
    \ Matrix& rhs) {\n        for (int i = 0; i < m_rows; i++) {\n            for\
    \ (int j = 0; j < m_columns; j++) {\n                mat[i][j] = mat[i][j] - rhs[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n    Matrix& operator*=(const\
    \ Matrix& rhs) {\n        assert(m_columns == rhs.rows());\n        Matrix res(m_rows,\
    \ rhs.columns());\n        for (int i = 0; i < m_rows; i++) {\n            for\
    \ (int k = 0; k < rhs.rows(); k++) {\n                for (int j = 0; j < m_columns;\
    \ j++) {\n                    res[i][j] = res[i][j] + mat[i][k] * rhs[k][j];\n\
    \                }\n            }\n        }\n        (*this) = res;\n       \
    \ return *this;\n    }\n    Matrix operator+(const Matrix& rhs) const { return\
    \ Matrix(*this) += rhs; }\n    Matrix operator-(const Matrix& rhs) const { return\
    \ Matrix(*this) -= rhs; }\n    Matrix operator*(const Matrix& rhs) const { return\
    \ Matrix(*this) *= rhs; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, Matrix& dat) {\n        for (int i = 0; i < dat.rows(); i++) {\n       \
    \     os << (i == 0 ? '[' : ' ');\n            for (int j = 0; j < dat.columns();\
    \ j++) {\n                if (j > 0) os << \",\";\n                os << dat[i][j];\n\
    \            }\n            os << (i + 1 < dat.rows() ? \";\\n\" : \"]\");\n \
    \       }\n        return os;\n    }\n    static Matrix identity(size_t n, T e0,\
    \ T e1) {\n        Matrix res(n, n, e0);\n        for (int i = 0; i < int(n);\
    \ i++) res[i][i] = e1;\n        return res;\n    }\n};\n\n// \u884C\u5217\u7D2F\
    \u4E57 O(N^3 log k)\ntemplate <typename T> Matrix<T> mat_power(Matrix<T> x, ll\
    \ k, T e0, T e1) {\n    Matrix<T> res = Matrix::identity(x.rows(), e0, e1);\n\
    \    while (k > 0) {\n        if (k & 1LL) {\n            res = x * res;\n   \
    \     }\n        x = x * x;\n        k >>= 1;\n    }\n    return res;\n}\n\n//\
    \ END"
  dependsOn: []
  isVerificationFile: false
  path: src/math/matrix.cpp
  requiredBy: []
  timestamp: '2021-10-01 02:18:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/matrix.cpp
layout: document
redirect_from:
- /library/src/math/matrix.cpp
- /library/src/math/matrix.cpp.html
title: src/math/matrix.cpp
---
