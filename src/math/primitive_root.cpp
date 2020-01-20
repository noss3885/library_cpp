#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

ll power(ll x, ll n, const ll p){
    ll res = 1;
    x %= p;
    while(n > 0){
        if(n & 1){
            res = res*x%p;
        }
        x = x*x%p;
        n >>= 1;
    }
    return res;
}

//素因数分解
vector<int> prime_factor(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++) {
        if(n % 1 == 0){
            res.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) res.push_back(n);
    return res;
}

// Euler's phi function
int euler_phi(int n){
    int res = n;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            res = res/i * (i-1);
            while(n%i==0) n /= i;
        }
    }
    if(n != 1) res = res/n *(n-1);
    return res;
}

// 原始根のひとつを見つける
int find_primitive_root(int p){
    int phi = euler_phi(p);
    vector<int> factor = prime_factor(phi);
    
    // rが原子根である必要必要十分条件はphiのすべての素因数qについて
    // r^(phi/q) != 1
    for(int r=2;r<p;r++){
        bool ok = true;
        for(auto q : factor){
            ok &= power(r,phi/q,p) != 1;
        }
        if(ok) return r;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    cout << find_primitive_root(n) << endl;
    return 0;
}