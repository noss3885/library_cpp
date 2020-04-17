
/*
最大流(Ford-Fulkerson)
O(F|V|)
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int IINF = INT_MAX;

// BEGIN

// 行先、容量、逆辺の番号
struct edge{
    int to, cap, rev;
};

vector<vector<edge> > G;
vector<bool> used;

void add_edge(int from, int to, int cap){
    G[from].emplace_back((edge){to, cap, int(G[to].size())});
    G[to].emplace_back((edge){from, 0, int(G[from].size())-1});
}

// 増加路の探索
int dfs(int v, int t, int f){
    if(v == t) return f;
    used[v] = true;
    for(auto &e : G[v]){
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    used.resize(G.size());
    int flow = 0;
    while(1){
        fill(used.begin(), used.end(), false);
        int f = dfs(s, t, IINF);
        if(f==0) break;
        flow += f;
    }
    return flow;
}

// END

// TEST
// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
int main() {
    int V, E;
    cin >> V >> E;
    G.resize(V);
    for(int i=0;i<E;i++){
        int u, v, c;
        cin >> u >> v >> c;
        add_edge(u, v, c);
    }
    cout << max_flow(0, V-1) << endl;
    return 0;
}
