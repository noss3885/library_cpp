#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include <iostream>
#include <climits>
#include "../../src/data_structures/lazy_segmenttree.cpp"

using ll = long long int;

// RMQ & RAQ
int main(){
    int n, q;
    std::cin >> n >> q;
    auto f = [=](ll a, ll b){return std::min(a,b);};
    auto g = [=](ll a, ll b){return a+b;};
    LazySegmentTree<ll, ll> seg(f,g,g,INT_MAX,0);
    std::vector<ll> v;
    v.assign(n, 0);
    seg.build(v);
    for(int i=0;i<q;i++){
        int c, s, t;
        std::cin >> c >> s >> t;
        if(c==0){
            ll x;
            std::cin >> x;
            seg.update(s, t+1, x);
        }
        else{
            std::cout << seg.query(s,t+1) << std::endl;
        }
    }
    return 0;
}