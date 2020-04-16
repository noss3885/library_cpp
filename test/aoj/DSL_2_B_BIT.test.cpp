#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include <iostream>
#include "../../src/data_structures/BIT.cpp"

using ll = long long int;

int main() {
    int n, q;
    std::cin >> n >> q;
    BIT<ll> bit(n);
    for(int i=0; i<q; i++){
        ll c, x, y;
        std::cin >> c >> x >> y;
        if(c){
            std::cout << bit.getSum(y) - bit.getSum(x-1) << std::endl;
        }else{
            bit.add(x,y);
        }
    }
    return 0;
}