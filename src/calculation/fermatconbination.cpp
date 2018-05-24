/*
フェルマーの小定理を用いた組み合わせ数
計算量 O(log(N!)) ?
*/

typedef long long ll;

#define MAX_N 10000
const ll MOD = 1000000007;

ll factrial[MAX_N], inverse[MAX_N];  //階乗と逆元を保持

ll power(ll x, ll n) {
    ll ans = 1;
    while (n > 0) {
        if ((n & 1) == 1) {
            ans = ans * x % MOD;
        }
        x = x * x % MOD;  //一周する度にx, x^2, x^4, x^8となる
        n >>= 1;          //桁をずらす n = n >> 1
    }
    return ans;
}

void init(ll n) {
    factrial[0] = 1;
    inverse[0]  = 1;
    for (ll i = 1; i <= n; i++) {
        factrial[i] = (factrial[i - 1] * i) % MOD;  //階乗を求める
        inverse[i]  = power(factrial[i], MOD - 2) % MOD;  //フェルマーの小定理で逆元を求める
    }
}

ll conbination(ll n, ll k) {
    return factrial[n] * inverse[k] % MOD * inverse[n - k] % MOD;
}
