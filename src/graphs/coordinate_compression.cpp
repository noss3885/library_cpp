/*
座標圧縮
計算量: 初期構築 O(NlogN), 圧縮 O(logN), 展開 O(1)
座標の範囲が広いとき座標の大小や位置関係を維持しながら範囲を狭める
*/
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<int, int> zip;
vector<int> unzip;

void compress(vector<int> &x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    unzip.resize(x.size());
    for (int i = 0; i < x.size(); i++) {
        zip[x[i]] = i;
        unzip[i] = x[i];
    }
}
