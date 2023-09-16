#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"
#include <iostream>
#include "../../src/graphs/ford_fulkerson.cpp"

int main() {
    int V, E;
    std::cin >> V >> E;
    FordFulkerson<int> g(V);
    for (int i = 0; i < E; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        g.add_edge(u, v, c);
    }
    std::cout << g.max_flow(0, V - 1) << std::endl;
    return 0;
}