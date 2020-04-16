#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include <iostream>
#include <climits>
#include "../../src/data_structures/segmenttree.cpp"

int main() {
    auto f = [=](int a, int b){return std::min(a, b);};
    SegmentTree<int> seg(f,INT_MAX);
    int n, q;
    std::cin >> n >> q;
    seg.init(n);
    for(int i=0; i<q; i++){
        int c, x, y;
        std::cin >> c >> x >> y;
        if(c){
            std::cout << seg.query(x, y+1) << std::endl;
        }
        else{
            seg.update(x, y);
        }
    }
    return 0;
}