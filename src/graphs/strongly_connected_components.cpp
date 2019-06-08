/*
強連結成分分解(Strongly-Connected-Components)
計算量 O(V+E)
*/
#include <vector>
#include <stack>
#include <set>
using namespace std;

typedef pair<int, int> P;

struct StronglyConnectedComponents {
    int N;
    vector<vector<int> > g, gr, g2i;
    vector<bool> visited;
    vector<int> i2g;
    vector<P> edges;
    stack<int> st;

    StronglyConnectedComponents(){};
    StronglyConnectedComponents(int n){init(n);}
    void init(int n){
        N = n;
        g.clear();
        g.resize(n);
        gr.clear();
        gr.resize(n);
        edges.clear();
        visited.resize(n);
        i2g.resize(n);
    }
    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
        edges.push_back(P(u, v));
    }

    void dfs(int x) {
        if (visited[x]) return;
        visited[x] = true;
        for (int i : g[x]) dfs(i);
        st.push(x);
    }

    void rdfs(int x, int k) {
        if (i2g[x] != -1) return;
        i2g[x] = k;
        for (int i : gr[x]) rdfs(i, k);
    }

    void build(vector<vector<int> > &t) {
        fill(visited.begin(), visited.end(), false);
        fill(i2g.begin(), i2g.end(), -1);
        for (int i = 0; i < N; i++) dfs(i);
        int p = 0;
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            if (i2g[v] == -1) {
                rdfs(v, p);
                p++;
            }
        }
        g2i.clear();
        g2i.resize(p);
        for(int i=0;i<N;i++){
            g2i[i2g[i]].push_back(i);
        }
        set<P> connected;
        for (auto &e : edges) {
            int x = i2g[e.first], y = i2g[e.second];
            if (x == y) continue;
            if (connected.count({x, y})) continue;
            t[x].push_back(y);
            connected.insert({x, y});
        }
    }
};
