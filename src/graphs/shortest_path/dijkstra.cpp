/*
ダイクストラ法
計算量 O(Elog(V))
最短経路を求める
負の辺があるときは使えない
*/

#include <functional>
#include <queue>
#include <utility>
#include <vector>
#include <climits>

using namespace std;
typedef pair<int, int> P;  // firstは最短距離,secondは頂点の番号

const int MAX_V = int(1e5 + 5);
const int IINF = INT_MAX;

struct edge {
    int from, to, cost;
    edge(int u, int v, int c) : from(u), to(v), cost(c){};
};

vector<edge> G[MAX_V];
int dmin[MAX_V];

void add_edge(int u, int v, int cost) {
    G[u].push_back(edge(u, v, cost));
    G[v].push_back(edge(v, u, cost));
}

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;  //小さいものから取り出す
    fill(dmin, dmin + MAX_V, IINF);
    dmin[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (dmin[v] < p.first) continue;
        for (auto &e : G[v]) {
            if (dmin[e.to] > dmin[v] + e.cost) {
                dmin[e.to] = dmin[v] + e.cost;
                que.push(P(dmin[e.to], e.to));
            }
        }
    }
}