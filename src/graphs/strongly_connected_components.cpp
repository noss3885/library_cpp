#include <algorithm>
#include <stack>
#include <vector>

struct SCC {
    int N, p;
    std::vector<std::vector<int> > g, gr, g2i, t, tr;
    std::vector<bool> visited;
    std::vector<int> i2g;
    std::stack<int> order;

    SCC() {}
    SCC(int n) { init(n); }
    void init(int n) {
        N = n;
        g.clear();
        g.resize(N);
        gr.clear();
        gr.resize(N);
        visited.resize(N);
        i2g.resize(N);
    }
    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        gr[v].emplace_back(u);
    }

    void dfs(int x) {
        if (visited[x]) return;
        visited[x] = true;
        for (int i : g[x]) dfs(i);
        order.push(x);
    }

    void rdfs(int x, int k) {
        if (visited[x]) return;
        visited[x] = true;
        i2g[x] = k;
        for (int i : gr[x]) rdfs(i, k);
    }

    void build() {
        std::fill(visited.begin(), visited.end(), false);
        std::fill(i2g.begin(), i2g.end(), -1);
        for (int i = 0; i < N; i++) dfs(i);
        p = 0;
        std::fill(visited.begin(), visited.end(), false);
        while (!order.empty()) {
            int idx = order.top();
            order.pop();
            if (!visited[idx]) rdfs(idx, p++);
        }
        g2i.clear();
        g2i.resize(p);
        for (int i = 0; i < N; i++) {
            g2i[i2g[i]].push_back(i);
        }
        t.resize(p);
        tr.resize(p);
        for (int i = 0; i < N; i++) {
            for (auto& to : g[i]) {
                int x = i2g[i], y = i2g[to];
                if (x == y) continue;
                t[x].push_back(y);
                tr[y].push_back(x);
            }
        }
        for (int i = 0; i < p; i++) {
            sort(t[i].begin(), t[i].end());
            t[i].erase(unique(t[i].begin(), t[i].end()), t[i].end());
            sort(tr[i].begin(), tr[i].end());
            tr[i].erase(unique(tr[i].begin(), tr[i].end()), tr[i].end());
        }
    }
    int count() const { return p; }
    int operator[](int k) const { return i2g[k]; }
};

struct TwoSAT {
    int N;
    SCC scc;
    std::vector<int> v;
    TwoSAT() = default;
    TwoSAT(int n) : N(n), scc(n * 2) {}
    void init(int n) {
        N = n;
        scc.init(N * 2);
    }
    int neg(int a) { return (a + N) % (N * 2); }
    void add_edge(int a, int b) {
        scc.add_edge(a, b);
    }
    void add_if(int a, int b) {
        // a -> b <=> !b -> !a
        add_edge(a, b);
        add_edge(neg(b), neg(a));
    }
    void add_iff(int a, int b) {
        // (a <=> b) <=> a -> b and b -> a
        add_if(a, b);
        add_if(b, a);
    }
    void add_or(int a, int b) {
        // a or b <=> !a -> b and !b -> a
        add_if(neg(a), b);
    }
    void add_nand(int a, int b) {
        // a nand b <=> a -> !b and b -> !a
        add_if(a, neg(b));
    }
    void add_xor(int a, int b) {
        add_nand(a, b);
        add_or(a, b);
    }
    void set_true(int a) {
        // a <=> !a -> a
        add_edge(neg(a), a);
    }
    void set_false(int a) {
        // !a <=> a -> !a
        add_edge(a, neg(a));
    }
    bool build() {
        scc.build();
        bool ok = true;
        for (int i = 0; i < N; i++) {
            ok &= scc.i2g[i] != scc.i2g[neg(i)];
        }
        if (ok) {
            for (int i = 0; i < N; i++) {
                v.push_back(scc[i] > scc[neg(i)]);
            }
        }
        return ok;
    }
    int operator[](int k) const { return v[k]; };
};
