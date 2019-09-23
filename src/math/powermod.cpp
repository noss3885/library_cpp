// x^n べき乗 計算量O(logN)
//繰り返し二乗法

#include <bits/stdc++.h>

typedef long long ll;
ll MOD = 1000000007;

ll power(ll x, ll n) {
    x %= MOD;
    ll ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * x % MOD;
        }
        x = x * x % MOD;  //一周する度にx, x^2, x^4, x^8となる
        n >>= 1;          //桁をずらす n = n >> 1
    }
    return ans;
}