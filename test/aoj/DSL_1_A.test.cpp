#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
#include <iostream>
#include "../../src/data_structures/union_find_tree.cpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    UnionFindTree g(n);
    for(int i=0;i<q;i++){
        int c, x, y;
        std::cin >> c >> x >> y;
        if(c){
            std::cout << (g.same(x,y)?1:0) << std::endl;
        }else{
            g.unite(x,y);
        }
    }
    return 0;
}