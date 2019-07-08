/*
最小有向全域木 (minimum spanning arborescence)
Chu-Liu/Edmonds' algorithm
O(VE)
*/
#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int from, to;
    int64_t weight;
    Edge(){};
    Edge(int u, int v, int64_t w){
        from = u;
        to = v;
        weight = w;
    };
};
bool operator < (const Edge &e, const Edge &f){
    if(e.weight != f.weight){
        return e.weight < f.weight;
    }
    else if(e.from != f.from){
        return e.from < f.from;
    }
    else{
        return e.to < f.to;
    }
}

bool operator > (const Edge &e, const Edge &f){
    if(e.weight != f.weight){
        return e.weight > f.weight;
    }
    else if(e.from != f.from){
        return e.from > f.from;
    }
    else{
        return e.to > f.to;
    }
}

// 最小有向全域木
struct ChuLiu_Edmonds
{
    int N, root;
    vector< vector< Edge > > g, gr;
    vector<bool> onCycle, visited;
    vector< Edge > minEdge;

    ChuLiu_Edmonds(){};
    ChuLiu_Edmonds(int siz, int r){init(siz, r);}
    void init(int siz, int r){
        N = siz;
        root = r;
        g.clear();
        g.resize(N);
        gr.clear();
        gr.resize(N);
        onCycle.resize(N);
        visited.resize(N);
        minEdge.resize(N);
    }
    void addEdge(int from, int to, int64_t weight){
        if(from == to)return;
        g[from].push_back(Edge(from, to, weight));
        gr[to].push_back(Edge(from, to, weight));
    }

    // 閉路を縮約した新たなグラフを構築し、再帰的に解を得る
    int64_t rec(int v){
        ChuLiu_Edmonds sub(N, root);
        auto getIndex = [&](int u){return onCycle[u] ? v : u;};
        for(int u=0;u<N;u++){
            for(auto &e : gr[u]){
                sub.addEdge(getIndex(e.from), getIndex(e.to), e.weight - (onCycle[u] ? minEdge[u].weight : 0));
            }
        }
        int64_t res = sub.build();
        return res;
    }

    int64_t build(){
        fill(onCycle.begin(), onCycle.end(), false);

        // 頂点iへの辺のうち最小コストの辺を得る
        for(int i=0;i<N;i++){
            if(i==root || gr[i].size()==0)continue;
            sort(gr[i].begin(), gr[i].end());
            minEdge[i] = gr[i][0];
        }
        
        // 閉路検出
        vector<int> deg(N, 0);
        queue<int> que;
        for(int i=0;i<N;i++){
            if(i==root || gr[i].size()==0)continue;
            deg[minEdge[i].from]++;
        }
        for(int i=0;i<N;i++){
            if(i==root || gr[i].size()==0)continue;
            if(deg[i]==0) que.push(i);
        }
        while(!que.empty()){  // 出次数0の頂点から取り除く
            int v = que.front();
            que.pop();
            if(gr[v].size()>0){
                int pre = minEdge[v].from;
                deg[pre]--;
                if(pre != root && deg[pre]==0) que.push(pre);
            }
        }
        for(int i=0;i<N;i++){
            if(deg[i] > 0){  // 閉路がある
                onCycle[i] = true;
                int pre = minEdge[i].from;
                while(pre != i){
                    onCycle[pre] = true;
                    pre = minEdge[pre].from;
                }
                int64_t sum = 0;
                sum += rec(i);
                for(int j=0;j<N;j++){
                    if(onCycle[j]) sum += minEdge[j].weight;
                }
                return sum;
            }
        }
        // 閉路がない
        int64_t res = 0;
        for(int i=0;i<N;i++){
            if(i==root || gr[i].size()==0)continue;
            res += minEdge[i].weight;
        }
        return res;
    }
    bool connected(){
        fill(visited.begin(), visited.end(), false);
        queue<int> que;
        que.push(root);
        visited[root] = true;
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(auto &e : g[v]){
                if(!visited[e.to]){
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        bool res = true;
        for(int i=0;i<N;i++){
            res &= visited[i];
        }
        return res;
    }
};

// VARIFY
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B

ChuLiu_Edmonds graph;

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    graph.init(V, r);
    for(int i=0;i<E;i++){
        int u, v;
        int64_t w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }
    cout << graph.build() << endl;
    return 0;
}

// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2124