/*
フェルマーの小定理を用いた組み合わせ数
計算量 O(log(N!)) ?
*/

typedef long long ll;

const ll MAX_N = ll(1e5 + 5);
const ll MOD = ll(1e9 + 7);

ll factrial[MAX_N], inverse[MAX_N];  //階乗と逆元を保持

ll mod_power(ll x, ll n) {  //繰り返し二乗法
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
    factrial[0] = 1;
    inverse[0] = 1;
    for (ll i = 1; i <= n; i++) {
        factrial[i] = (factrial[i - 1] * i) % MOD;  //階乗を求める
        inverse[i] = mod_power(factrial[i], MOD - 2) % MOD;  //オイラーの定理で逆元を求める
    }
}

ll nCk(ll n, ll k) {
    if(n < 0 || k < 0 || n < k) return 0;
    return factrial[n] * inverse[k] % MOD * inverse[n - k] % MOD;
}
