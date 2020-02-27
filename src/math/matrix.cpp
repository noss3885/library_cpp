/*
行列演算ライブラリ
要素の型は+と*が定義されている必要がある
*/
#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;

// BEGIN

template <typename T>
struct Matrix{
    using vec = std::vector<T>;

    std::vector<vec> mat;
    size_t m_rows = 0, m_columns = 0;

    Matrix() = default;
    Matrix(size_t r, size_t c):m_rows(r),m_columns(c),mat(r,vec(c)){}

    size_t rows() const {return m_rows;}
    size_t columns() const {return m_columns;}

    vec &operator[](size_t i){return mat[i];}
    vec const &operator[](size_t i) const {return mat[i];}

    Matrix &operator+=(const Matrix& rhs) {
        for(int i=0; i<m_rows; i++){
            for(int j=0; j<m_columns; j++) {
                mat[i][j] = mat[i][j] + rhs[i][j];
            }
        }
        return *this;
    }
    Matrix &operator-=(const Matrix& rhs) {
        for(int i=0; i<m_rows; i++){
            for(int j=0; j<m_columns; j++) {
                mat[i][j] = mat[i][j] - rhs[i][j];
            }
        }
        return *this;
    }
    Matrix &operator*=(const Matrix& rhs) {
        assert(m_columns != rhs.rows());
        Matrix res(m_rows, rhs.columns());
        for(int i=0; i<m_rows; i++){
            for(int k=0; k<rhs.rows(); k++){
                for(int j=0; j<m_columns; j++){
                    res[i][j] = res[i][j] + mat[i][k] * rhs[k][j];
                }
            }
        }
        (*this) = res;
        return *this;
    }
    Matrix operator+(const Matrix& rhs) const {
        return Matrix(*this) += rhs;
    }
    Matrix operator-(const Matrix& rhs) const {
        return Matrix(*this) -= rhs;
    }
    Matrix operator*(const Matrix& rhs) const {
        return Matrix(*this) *= rhs;
    }

    friend std::ostream &operator<<(std::ostream &os, Matrix &dat){
        for(int i=0; i<dat.rows(); i++){
            os << (i==0 ? '[' : ' ');
            for(int j=0; j<dat.columns(); j++){
                if(j>0) os << ",";
                os << dat[i][j];
            }
            os << (i+1<dat.rows() ? ";\n" : "]");
        }
        return os;
    }
    Matrix identity(size_t n){
        Matrix res(n,n);
        for(int i=0;i<int(n);i++) res[i][i] = T().identity();
        return res;
    }
};

// 累乗 O(N^3 log k)
template <typename T>
T mat_power(T x, ll k){
    T res = T().identity(x.rows());
    while(k > 0){
        if(k&1LL){
            res = x*res;
        }
        x = x*x;
        k >>= 1;
    }
    return res;
}

// END