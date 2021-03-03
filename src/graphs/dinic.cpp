#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

template <typename T>
struct Dinic{
    // 行先、容量、逆辺の番号
    struct edge{
        int to, rev;
        T cap;
        edge() = default;
        edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
    };
    std::vector<std::vector<edge> > G;
    std::vector<int> level, iter;

    Dinic() = default;
    Dinic(int n) : G(n), level(n), iter(n) {}
    
    T inf = std::numeric_limits<T>::max()/2;

    void init(int n){
        G.clear();
        G.resize(n);
        level.resize(n);
        iter.resize(n);
    }

    void add_edge(int from, int to, T cap, bool directed = true){
        G[from].emplace_back(to, cap, int(G[to].size()));
        G[to].emplace_back(from, directed?0:cap, int(G[from].size())-1);
    }

    void bfs(int s){
        std::fill(level.begin(), level.end(), -1);
        std::queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(edge &e : G[v]){
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    // 増加路の探索
    T dfs(int v, int t, T f){
        if(v == t) return f;
        for(int &i = iter[v]; i<int(G[v].size()); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
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
            bfs(s);
            if(level[t] < 0) break;
            std::fill(iter.begin(), iter.end(), 0);
            T f;
            while((f = dfs(s, t, lim)) > 0){
                flow += f;
                lim -= f;
            }
        }
        return flow;
    }
    T max_flow(int s, int t){return max_flow(s, t, inf);}
};