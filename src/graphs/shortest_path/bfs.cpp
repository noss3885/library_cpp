/*
幅優先探索
計算量 O(HW)
グリッド状の迷路の最短経路を求める
*/

#include <string>
#include <queue>
using namespace std;

const int IINF = 10000;

queue<int> px, py;
int h, w, sx, sy, gx, gy, d[50][50], dx[4] = {0, 1, 0, -1},
                                     dy[4] = {1, 0, -1, 0};
string s[50];

int bfs() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            d[i][j] = IINF;
        }
    }
    px.push(sx - 1);
    py.push(sy - 1);
    d[sy][sx] = 0;

    while (px.size()) {
        int x = px.front(), y = py.front();
        px.pop();
        py.pop();
        if (x == gx && y == gy) {
            return d[y][x];
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= w )continue;
            if (ny < 0 || ny <= h )continue;
            if (s[ny][nx] == '.' && d[ny][nx] == IINF) {
                d[ny][nx] = d[y][x] + 1;
                px.push(nx);
                py.push(ny);
            }
        }
    }
    return IINF;
}