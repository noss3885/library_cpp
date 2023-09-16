/*
fibonacci with matrix
O(logN)
*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > mat;
const ll MOD = ll(1e9 + 7);

mat init(mat m, int xlen, int ylen) {
    m.resize(xlen);
    for (int i = 0; i < xlen; i++) {
        m[i].resize(ylen);
        for (int j = 0; j < ylen; j++) {
            m[i][j] = 0;
        }
    }
    return m;
}

mat mul(mat a, mat b) {
    mat c;
    c = init(c, a.size(), b[0].size());
    for (int i = 0; i < a.size(); i++) {
        for (int k = 0; k < b.size(); k++) {
            for (int j = 0; j < b[0].size(); j++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

mat pow(mat a, ll n) {
    mat b;
    b = init(b, a.size(), a.size());
    for (int i = 0; i < a.size(); i++) {
        b[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) b = mul(a, b);
        a = mul(a, a);
        n >>= 1;
    }
    return b;
}

ll fibo(ll n) {
    mat a;
    a.resize(2);
    a[0].resize(2);
    a[1].resize(2);
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;
    a = pow(a, n);
    return a[0][0] % MOD;
}

//--test--//

int main() {
    ll n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}
