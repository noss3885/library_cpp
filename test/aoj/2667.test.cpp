#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2677"
#include <iostream>
#include <queue>
#include "../../src/graphs/lowest_common_ancestor.cpp"

using ll = long long int;

int main() {
    int n;
    std::cin >> n;
    LCA lca(n);
    for (int i = 0; i < n - 1; i++) {
        int p;
        std::cin >> p;
        p--;
        lca.add_edge(p, i + 1);
    }
    // LCAの前計算
    lca.build();
    // BFS
    int prev = 0;
    ll ans = 0;
    std::vector<bool> visited(n, false);
    std::queue<int> que;
    que.push(lca.root);
    while (!que.empty()) {
        int idx = que.front();
        que.pop();
        visited[idx] = true;
        ans += lca.dist(prev, idx);
        prev = idx;
        for (auto e : lca.graph[idx]) {
            if (!visited[e.to]) que.push(e.to);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
