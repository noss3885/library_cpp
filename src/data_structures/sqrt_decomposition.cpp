/*
平方分割
RSQ,RAQ,RUQが可能
*/
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct SqrtDecomposition {
    const ll sqrtN = 512;
    ll N, K;
    vector<ll> data;
    vector<ll> bucketSum, bucketAdd;
    vector<bool> lazyFlag;
    vector<ll> lazyUpdate;
    SqrtDecomposition(ll n = 0LL, ll x = 0LL) : N(n) {
        K = (N + sqrtN - 1) / sqrtN;
        data.assign(K*sqrtN, x);
        bucketSum.assign(K, x*sqrtN);
        bucketAdd.assign(K, 0ll);
        lazyFlag.assign(K, false);
        lazyUpdate.assign(K, x);
    }
    void init(ll n, ll x = 0LL){
        N = n;
        K = (N + sqrtN - 1) / sqrtN;
        data.assign(K*sqrtN, x);
        bucketSum.assign(K, x*sqrtN);
        bucketAdd.assign(K, 0ll);
        lazyFlag.assign(K, false);
        lazyUpdate.assign(K, x);
    }
    void eval(ll k) {
        if (lazyFlag[k]) {
            lazyFlag[k] = false;
            for (ll i = k * sqrtN; i < (k + 1) * sqrtN; ++i) {
                data[i] = lazyUpdate[k];
            }
        }
    }
    // [s, t)
    void add(ll s, ll t, ll x) {
        for (ll k = 0; k < K; ++k) {
            ll l = k * sqrtN, r = (k + 1) * sqrtN;
            if (r <= s || t <= l) continue;
            if (s <= l && r <= t) {
                bucketAdd[k] += x;
            } else {
                for (ll i = max(s, l); i < min(t, r); ++i) {
                    data[i] += x;
                    bucketSum[k] += x;
                }
            }
        }
    }
    // [s, t)
    void update(ll s, ll t, ll x) {
        for (ll k = 0; k < K; ++k) {
            ll l = k * sqrtN, r = (k + 1) * sqrtN;
            if (r <= s || t <= l) continue;
            if (s <= l && r <= t) {
                bucketSum[k] = x * sqrtN;
                bucketAdd[k] = 0ll;
                lazyFlag[k] = true;
                lazyUpdate[k] = x;
            } else {
                eval(k);
                for (ll i = l; i < r; ++i) {
                    data[i] = data[i] + bucketAdd[k];
                }
                bucketAdd[k] = 0;
                for (ll i = max(s, l); i < min(t, r); ++i) {
                    data[i] = x;
                }
                ll &sumVal = bucketSum[k] = 0ll;
                for (ll i = l; i < r; ++i) {
                    sumVal = sumVal + data[i];
                }
            }
        }
    }
    // [s, t)
    ll getSum(ll s, ll t) {
        ll sumVal = 0;
        for (ll k = 0; k < K; ++k) {
            ll l = k * sqrtN, r = (k + 1) * sqrtN;
            if (r <= s || t <= l) continue;
            if (s <= l && r <= t) {
                sumVal = sumVal + bucketSum[k] + bucketAdd[k] * sqrtN;
            } else {
                eval(k);
                for (ll i = max(s, l); i < min(t, r); ++i) {
                    sumVal = sumVal + data[i] + bucketAdd[k];
                }
            }
        }
        return sumVal;
    }
};


// varify

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
void DSL_2_D(){
    int n, q;
    cin >> n >> q;
    SqrtDecomposition ruq(n, (1LL<<31)-1);
    for(int i=0; i<q; i++){
        int c;
        cin >> c;
        if(c){
            int k;
            cin >> k;
            cout << ruq.getSum(k,k+1) << endl;
        }
        else{
            int s, t, x;
            cin >> s >> t >> x;
            ruq.update(s,t+1,x);
        }
    }
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
void DSL_2_E(){
    int n, q;
    cin >> n >> q;
    SqrtDecomposition ruq(n);
    for(int i=0; i<q; i++){
        int c;
        cin >> c;
        if(c){
            int k;
            cin >> k;
            cout << ruq.getSum(k,k+1) << endl;
        }
        else{
            int s, t, x;
            cin >> s >> t >> x;
            ruq.add(s,t+1,x);
        }
    }
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
void DSL_2_G(){
    int n, q;
    cin >> n >> q;
    SqrtDecomposition ruq(n);
    for(int i=0; i<q; i++){
        int c;
        cin >> c;
        if(c){
            int s, t;
            cin >> s >> t;
            cout << ruq.getSum(s,t+1) << endl;
        }
        else{
            int s, t, x;
            cin >> s >> t >> x;
            ruq.add(s,t+1,x);
        }
    }
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
void DSL_2_I(){
    int n, q;
    cin >> n >> q;
    SqrtDecomposition ruq(n);
    for(int i=0; i<q; i++){
        int c;
        cin >> c;
        if(c){
            int s, t;
            cin >> s >> t;
            cout << ruq.getSum(s,t+1) << endl;
        }
        else{
            int s, t, x;
            cin >> s >> t >> x;
            ruq.update(s,t+1,x);
        }
    }
}

int main(){
    //DSL_2_D();
    //DSL_2_E();
    //DSL_2_G();
    //DSL_2_I();
    return 0;
}