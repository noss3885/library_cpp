#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"
#include <iostream>
#include <numeric>
#include "../../src/graphs/ford_fulkerson.cpp"

int main() {
    int n, m;
    while(std::cin >> m >> n, m){
        FordFulkerson<int> G(m+n+2);
        std::vector<int> a(m), b(n);
        for(int i=0;i<m;i++) std::cin >> a[i];
        for(int i=0;i<n;i++) std::cin >> b[i];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(std::gcd(a[i], b[j]) > 1){
                    G.add_edge(i,j+m,1);
                }
            }
        }
        int S = n+m, T = n+m+1;
        for(int i=0;i<m;i++){
            G.add_edge(S,i,1);
        }
        for(int i=0;i<n;i++){
            G.add_edge(i+m,T,1);
        }
        std::cout << G.max_flow(S, T+1) << std::endl;
    }
    return 0;
}