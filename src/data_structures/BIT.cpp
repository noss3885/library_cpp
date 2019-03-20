/*
BIT
計算量(クエリ) O(log(n))
区間の和を求める
ある要素に加算する
*/
#include<vector>
using namespace std;

struct BIT {
    int N;
    vector<int> bit;

    void init(int _n){
        N = _n;
        bit.resize(_n, 0);
    }

    int getSum(int i) {  // i番目までの要素の和を求める(1-index)
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }

    void add(int i, int x) {  // i番目の要素にxを加算
        while (i <= N) {
            bit[i] += x;
            i += i & -i;
        }
    }
};