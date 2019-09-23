/*
強連結成分分解(Strongly-Connected-Components)
計算量 O(V+E)
*/
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef pair<int, int> P;

struct SCC {
    int N;
    vector<vector<int> > g, gr, g2i, t;
    vector<bool> visited;
    vector<int> i2g;
    stack<int> order;

    SCC(){};
    SCC(int n){init(n);}
    void init(int n){
        N = n;
        g.clear();
        g.resize(n);
        gr.clear();
        gr.resize(n);
        visited.resize(n);
        i2g.resize(n);
    }
    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        gr[v].emplace_back(u);
    }

    void dfs(int x) {
        if (visited[x]) return;
        visited[x] = true;
        for (int i : g[x]) dfs(i);
        order.push(x);
    }

    void rdfs(int x, int k) {
        if (i2g[x] != -1) return;
        i2g[x] = k;
        for (int i : gr[x]) rdfs(i, k);
    }

    void build() {
        fill(visited.begin(), visited.end(), false);
        fill(i2g.begin(), i2g.end(), -1);
        for (int i = 0; i < N; i++) dfs(i);
        int p = 0;
        while (!order.empty()) {
            rdfs(order.top(), p++);
            order.pop();
        }
        g2i.clear();
        g2i.resize(p);
        for(int i=0;i<N;i++){
            g2i[i2g[i]].push_back(i);
        }
        t.resize(p);
        for(int i=0;i<N;i++){
            for (auto &to : g[i]) {
                int x = i2g[i], y = i2g[to];
                if (x == y) continue;
                t[x].push_back(y);
            }
        }
        for(int i=0;i<p;i++){
            sort(t[i].begin(), t[i].end());
            t[i].erase(unique(t[i].begin(), t[i].end()),t[i].end());
        }
    }
};
