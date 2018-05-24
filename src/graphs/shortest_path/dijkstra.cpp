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

using namespace std;

const int MAX_V = 1000;
const int INF = 99999999;

struct edge {
    int to, cost;
};
typedef pair<int, int> P; // firstは最短距離,secondは頂点の番号

int V;
vector<edge> G[MAX_V];
int dmin[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que; //小さいものから取り出す
    fill(dmin, dmin + V, INF);
    dmin[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (dmin[v] < p.first)
            continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (dmin[e.to] > dmin[v] + e.cost) {
                dmin[e.to] = dmin[v] + e.cost;
                que.push(P(dmin[e.to], e.to));
            }
        }
    }
}