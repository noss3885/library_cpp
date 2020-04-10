#include <bits/stdc++.h>
typedef long long ll;

constexpr int M = 2;
constexpr ll MODS[M] = {ll(1e9+7), ll(1e9+9)};

struct RollingHash{
    std::vector<std::vector<ll> > powb, rhash;
    int N;
    void build(const std::string& str, const ll base = ll(1e5 + 7)) {
        N = str.size();
        powb.resize(M);
        rhash.resize(M);
        for(int k=0;k<M;k++){
            powb[k].resize(N + 1);
            rhash[k].resize(N + 1);
            powb[k][0] = 1;
            rhash[k][0] = 0;
            for (int i=0; i<N; i++) {
                rhash[k][i+1] = (rhash[k][i] * base + str[i]) % MODS[k];
                powb[k][i+1] = powb[k][i] * base % MODS[k];
            }
        }
    }
    
    //[l,r)
    ll get_hash(int k, int l, int r) { return (rhash[k][r] - rhash[k][l]*powb[k][r-l]%MODS[k]+MODS[k])%MODS[k]; }
    
    bool match(int l1, int r1, int l2, int r2){
        bool res = true;
        for(int k=0; k<M; k++){
            res &= get_hash(k, l1, r1) == get_hash(k, l2, r2);
        }
        return res;
    }
};