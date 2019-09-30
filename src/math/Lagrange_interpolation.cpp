/*
Lagrange interpolation polynomial
x = 0,1,2,...N
O(N)
*/
#include<vector>
using namespace std;

typedef long long ll;
constexpr ll MOD = 998244353;

ll power(ll x, ll n){
    x %= MOD;
    ll res = 1;
    while(n > 0){
        if(n&1){
            res = res*x%MOD;
            res %= MOD;
        }
        x = x*x % MOD;
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x){
    return power(x, MOD-2);
}

// calclate P(t) from (0,P(0)),(1,P(1)),...,(N,P(N))
ll interpolate(vector<ll> y, ll t){
    ll n = ll(y.size())-1, q = 1, res = 0;
    if(t <= n) return y[t];
    for(ll i=0;i<=n;i++){
        q *= t-i;
        q = (q%MOD+MOD)%MOD;
    }
    vector<ll> fac(n+1), inv(n+1);
    fac[0] = 1; inv[0] = 1;
    for(ll i=0;i<n;i++){
        fac[i+1] = fac[i]*(i+1)%MOD;
        inv[i+1] = mod_inv(fac[i+1]);
    }
    for(int i=0;i<=n;i++){
        ll tmp = y[i] * q % MOD * inv[i] % MOD * inv[n-i] % MOD * mod_inv(t-i);
        if((n-i)&1) res -= tmp;
        else res += tmp;
        res = (res%MOD+MOD)%MOD;
    }
    return res;
}