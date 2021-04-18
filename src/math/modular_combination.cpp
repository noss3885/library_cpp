/*
フェルマーの小定理を用いた組み合わせ数
計算量 O(N) ?
*/
#include<vector>
using namespace std;

using ll = long long int;

constexpr ll MOD = ll(1e9 + 7);

vector<ll> factrial, inverse;  //階乗と逆元を保持

ll mod_power(ll x, ll n) {  //繰り返し二乗法
    x %= MOD;
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

void init(ll n) {
    if(n >= MOD){
        n = MOD-1;
    }
    factrial.resize(n+1);
    inverse.resize(n+1);
    factrial[0] = 1;
    inverse[0] = 1;
    for (ll i = 1; i <= n; i++) {
        factrial[i] = (factrial[i - 1] * i) % MOD;
        inverse[i] = mod_power(factrial[i], MOD - 2);
    }
}

ll nCk(ll n, ll k) {
    if(n < 0 || k < 0 || n < k) return 0;
    if(n < MOD) return factrial[n] * inverse[k] % MOD * inverse[n - k] % MOD;
    // if n >= mod, use Lucas's theorem
    ll res = 1;
    while(n|k){
        res = res * nCk(n%MOD, k%MOD) % MOD;
        n /= MOD; k /= MOD;
    }
    return res;
}
