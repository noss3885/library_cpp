// x^n べき乗 計算量O(logN)
//繰り返し二乗法

int MOD = 1000000007;

long long power(long long x, long long n) {
    long long ans = 1;
    while (n > 0) {
        if ((n & 1) == 1) {
            ans = ans * x % MOD;
        }
        x = x * x % MOD;  //一周する度にx, x^2, x^4, x^8となる
        n >>= 1;          //桁をずらす n = n >> 1
    }
    return ans;
}