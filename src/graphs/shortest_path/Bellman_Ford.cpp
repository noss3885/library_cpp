/*
ベルマンフォード法
計算量 O(VE)
最短経路を求める
負の辺があっても可
負の辺があるときV回以上更新する
*/
#include <algorithm>

using namespace std;

const int MAX_E = 10000;
const int MAX_V = 100;
const int INF = 9999999;

struct edge {
    int from, to, cost;
}; //辺の始点、終点、重み

edge es[MAX_E]; //辺

int d[MAX_V]; //最短距離
int V, E;     // Vは頂点数、Eは辺数

// S番目の頂点から各頂点への最短経路を求める
void shortest_path(int s) {
    fill(d, d + V, INF);
    d[s] = 0;
    while (true) {
        bool update = false;
        for (int i = 0; i < E; i++) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update)
            break;
    }
}