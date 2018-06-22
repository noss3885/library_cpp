/*
強連結成分分解(Strongly-Connected-Components)
計算量 O(V+E)
*/
#include <vector>
#include <stack>
#include <set>
using namespace std;

typedef pair<int, int> P;

struct SCC {
    vector<vector<int> > g, gr;
    vector<int> visited, num;
    vector<P> es;
    stack<int> st;

    SCC(int n) : g(n), gr(n), visited(n, 0), num(n, -1) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
        es.push_back(P(u, v));
    }

    void dfs(int x) {
        if (visited[x]) return;
        for (int i : g[x]) dfs(i);
        st.push(x);
    }

    void rdfs(int x, int k) {
        if (num[x] != -1) return;
        num[x] = k;
        for (int i : gr[x]) rdfs(i, k);
    }
    void build(vector<vector<int> > &t) {
        for (int i = 0; i < g.size(); i++) dfs(i);
        int p = 0;
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            if (num[v] == -1) {
                rdfs(v, p);
                p++;
            }
        }
        set<P> connected;
        for (auto &e : es) {
            int x = num[e.first], y = num[e.second];
            if (x == y) continue;
            if (connected.count({x, y})) continue;
            t[x].push_back(y);
            connected.insert({x, y});
        }
    }
};
