#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2748"
#include <iostream>
#include "../../src/graphs/strongly_connected_components.cpp"

#define ERROR "1e-5"

int main() {
    while (1) {
        int N;
        double p[100];
        std::cin >> N;
        if (N == 0) break;
        SCC G(N);
        for(int i=0; i<N; i++) {
            std::cin >> p[i];
            int m;
            std::cin >> m;
            for(int j=0; j<m; j++) {
                int a;
                std::cin >> a;
                a--;
                G.add_edge(i, a);
            }
        }
        G.build();
        double ans = 1;
        for (int i=0; i<G.count(); i++) {
            if (G.tr[i].empty()) {
                double q = 1;
                for (int idx : G.g2i[i]) {
                    q *= p[idx];
                }
                ans *= (1 - q);
            }
        }
        printf("%.8lf\n", ans);
    }
    return 0;
}