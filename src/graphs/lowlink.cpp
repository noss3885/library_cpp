/*
lowlink
関節点、橋を求める
O(V+E)
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

vector<vector<int> > g;
vector<int> ord, low;
vector<bool> is_articulation;
vector<P> bridges;

void dfs(int u, int par, int& k) {
    ord[u] = k;
    k++;
    low[u] = ord[u];
    int cnt = 0;
    for (auto v : g[u]) {
        // dfsの子ノードへ移動
        if (ord[v] == -1) {
            cnt++;
            dfs(v, u, k);
            low[u] = min(low[u], low[v]);
            if (par != -1 && ord[u] <= low[v]) {
                is_articulation[u] = true;
            }
            if (ord[u] < low[v]) {
                bridges.push_back(make_pair(min(u, v), max(u, v)));
            }
        }
        // dfs木の後退辺を移動
        else if (v != par)
            low[u] = min(low[u], ord[v]);
    }
    if (par == -1) {
        is_articulation[u] = cnt >= 2;  // 根はdfs木の次数が2以上ならば関節点
    }
}

void lowlink() {
    ord.resize(g.size(), -1);
    low.resize(g.size());
    is_articulation.resize(g.size(), false);
    int k = 0;
    dfs(0, -1, k);
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    return 0;
}
