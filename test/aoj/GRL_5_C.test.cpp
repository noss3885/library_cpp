#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
#include <iostream>
#include "../../src/graphs/lowest_common_ancestor.cpp"

int main() {
    int n, q;
    std::cin >> n;
    LCA lca(n);
    for(int i=0;i<n;i++){
        int k;
        std::cin >> k;
        for(int j=0;j<k;j++){
            int c;
            std::cin >> c;
            lca.add_edge(i,c);
        }
    }
    lca.build();
    std::cin >> q;
    for(int i=0;i<q;i++){
        int u, v;
        std::cin >> u >> v;
        std::cout << lca.query(u, v) << std::endl;
    }
    return 0;
}