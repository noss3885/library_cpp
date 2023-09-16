#include <vector>

template <typename T>
struct BIT {
    int N;
    std::vector<T> bit;

    BIT() = default;
    BIT(int n) {init(n);}
    void init(int n){
        N = n;
        bit.assign(n+1, 0);
    }
    T getSum(int i) {  // i番目までの要素の和を求める(1-index)
        T sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
    void add(int i, T x) {  // i番目の要素にxを加算
        while (i <= N) {
            bit[i] += x;
            i += i & -i;
        }
    }
};