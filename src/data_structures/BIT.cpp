/*
BIT
計算量(クエリ) O(log(n))
区間の和を求める
ある要素に加算する
*/

struct BIT {
    static const int MAX_N = 100000;

    int bit[MAX_N + 1]{0}, n;

    int sum(int i) {  // i番目までの要素の和を求める(1-index)
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x) {  // i番目の要素にxを加算
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
}