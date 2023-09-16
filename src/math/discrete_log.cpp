// discrete log
// compute x that a^x = b mod m
//
// baby-step giant-step algorithm
// O(sqrt(m))

#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

ll power(ll x, ll n, const ll p) {
    x %= p;
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % p;
        }
        x = x * x % p;
        n >>= 1;
    }
    return res;
}

// return x, a^x = b mod m
ll discrete_log(ll a, ll b, ll m) {
    ll h = ceil(sqrt(m) + .1);
    unordered_map<ll, ll> table;
    for (ll i = 0, t = 1; i < h; i++) {
        table[t] = i;
        t = t * a % m;
    }
    ll e = b, inv = power(a, m - 1 - h, m);
    for (ll i = 0; i < h; i++) {
        if (table.find(e) != table.end()) {
            ll j = table[e];
            return i * h + j;
        }
        e = e * inv % m;
    }
    return -1;
}

// TEST
// https://atcoder.jp/contests/arc042/tasks/arc042_d

int main() {
    ll x, p, a, b, k;
    cin >> x >> p >> a >> b;
    k = b - a + 1;
    a %= p - 1;
    b %= p - 1;
    if (a == 0 || a > b || k >= p - 1) {
        cout << 1 << endl;
        return 0;
    }
    if (k < 1 << 24) {
        ll ans = p, tmp = power(x, a, p);
        for (ll i = 0; i < k; i++) {
            ans = min(ans, tmp);
            tmp = tmp * x % p;
        }
        cout << ans << endl;
    } else {  // baby-step giant-step
        for (int i = 1; i < p; i++) {
            ll y = discrete_log(x, i, p);
            if (y != p && y >= a && y <= b) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}