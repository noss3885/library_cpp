// x^n べき乗 計算量O(logN)
//繰り返し二乗法

#include <bits/stdc++.h>

int MOD = 1000000007;

int64_t power(int64_t x, int64_t n) {
    int64_t ans = 1;
    while (n > 0) {
        if ((n & 1) == 1) {
            ans = ans * x % MOD;
        }
        x = x * x % MOD;  //一周する度にx, x^2, x^4, x^8となる
        n >>= 1;          //桁をずらす n = n >> 1
    }
    return ans;
}