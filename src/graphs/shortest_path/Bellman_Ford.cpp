/*
ベルマンフォード法
計算量 O(VE)
最短経路を求める
負の辺があっても可
負の辺があるときV回以上更新する
*/
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

const int MAX_V = 1000;
const int IINF = INT32_MAX;

struct edge {
    int from, to, cost;
    edge(int u, int v, int c) : from(u), to(v), cost(c){};
};  //辺の始点、終点、重み

vector<edge> es;  //辺
int dmin[MAX_V];  //最短距離

void add_edge(int u, int v, int cost) {
    es.push_back(edge(u, v, cost));
}

// S番目の頂点から各頂点への最短経路を求める
void shortest_path(int s) {
    fill(dmin, dmin + MAX_V, IINF);
    dmin[s] = 0;
    while (true) {
        bool update = false;
        for (auto &e : es) {
            if (dmin[e.from] != IINF && dmin[e.to] > dmin[e.from] + e.cost) {
                dmin[e.to] = dmin[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}