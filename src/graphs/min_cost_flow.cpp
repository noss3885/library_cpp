/*
最小費用流
O(FElogV)
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
constexpr int IINF = INT_MAX;

// BEGIN

struct edge{
    int to, cap, cost, rev;
};

vector<vector<edge> > G;
vector<int> h, dist, prevv, preve;

void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, int(G[to].size())});
    G[to].push_back((edge){from, 0, -cost, int(G[from].size())-1});
}

// 最小費用流
int min_cost_flow(int s, int t, int f){
    h.resize(G.size());
    dist.resize(G.size());
    prevv.resize(G.size());
    preve.resize(G.size());
    int res = 0;
    fill(h.begin(), h.end(), 0);
    while(f > 0){
        priority_queue<P, vector<P>, greater<P> > que;
        fill(dist.begin(), dist.end(), IINF);
        dist[s] = 0;
        que.push({0,s});
        while(!que.empty()){
            P p = que.top();
            que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(int i=0;i<int(G[v].size());i++){
                auto &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push({dist[e.to], e.to});
                }
            }
        }
        if(dist[t] == IINF){
            return -1;
        }
        for(int v=0; v<G.size(); v++) h[v] += dist[v];
        int d = f;
        for(int v=t; v!=s; v=prevv[v]){
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d*h[t];
        for(int v=t; v!=s; v=prevv[v]){
            auto &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

// END

// TEST
// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
int main() {
    int V, E, F;
    cin >> V >> E >> F;
    G.resize(V);
    for(int i=0;i<E;i++){
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        add_edge(u, v, c, d);
    }
    cout << min_cost_flow(0, V-1, F) << endl;
    return 0;
}
