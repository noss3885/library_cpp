/*
ワーシャル・フロイド法
計算量 O(V^3)
全点対最短経路を求める
負の辺があっても可
負の閉路があるときd[i][i]<0となるiが存在する
*/
#include <algorithm>

using namespace std;

#define MAX_V 1000

int d[MAX_V][MAX_V];
int V;

void warshal_floyd() {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}