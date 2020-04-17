#include <vector>
#include <algorithm>
#include <limits>

template <typename T>
struct FordFulkerson{
    // 行先、容量、逆辺の番号
    struct edge{
        int to, rev;
        T cap;
        edge() = default;
        edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
    };
    std::vector<std::vector<edge> > G;
    std::vector<bool> used;

    FordFulkerson() = default;
    FordFulkerson(int n) : G(n), used(n) {}
    
    void init(int n){
        G.clear();
        G.resize(n);
        used.resize(n);
    }

    void add_edge(int from, int to, T cap, bool directed = true){
        G[from].emplace_back(to, cap, int(G[to].size()));
        G[to].emplace_back(from, directed?0:cap, int(G[from].size())-1);
    }

    // 増加路の探索
    T dfs(int v, int t, T f){
        if(v == t) return f;
        used[v] = true;
        for(auto &e : G[v]){
            if(!used[e.to] && e.cap > 0){
                T d = dfs(e.to, t, std::min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T max_flow(int s, int t, T lim){
        T flow = 0;
        while(1){
            std::fill(used.begin(), used.end(), false);
            T f = dfs(s, t, lim);
            if(f==0) break;
            flow += f;
            lim -= f;
        }
        return flow;
    }
    T max_flow(int s, int t){return max_flow(s, t, std::numeric_limits<T>::max()/2);}
};