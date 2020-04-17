#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"
#include <iostream>
#include "../../src/graphs/strongly_connected_components.cpp"

int main() {
    int V, E;
    std::cin >> V >> E;
    SCC G(V);
    for(int i=0;i<E;i++){
        int s, t;
        std::cin >> s >> t;
        G.add_edge(s,t);
    }
    G.build();
    std::cout << (G.count() < V) << std::endl;
    return 0;
}