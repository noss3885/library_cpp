#include <utility>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define MAX_V 1000
#define INF 99999999

struct edge {int to, cost;};
typedef pair<int, int> P;

class Graph{
   private:
      int V;
      vector<edge> G[MAX_V];
      
   public:
      int dmin[MAX_V];

      Graph(int n){
         V = n;
      };

      void add(int u, int v, int cost){
         G[u].push_back({v,cost});
         G[v].push_back({u,cost}); //無向グラフ
      };

      void dijkstra(int s){
      priority_queue<P, vector<P>, greater<P>()> que; //小さいものから取り出す
      fill(dmin, dmin+V, INF);
      dmin[s] = 0;
      que.push(P(0,s));

      while(!que.empty()){
         P p = que.top(); que.pop();
         int v = p.second;
         if(dmin[v] < p.first)continue;
      for(int i=0;i<G[v].size();i++){
            edge e = G[v][i];
            if(dmin[e.to] > dmin[v] + e.cost){
               dmin[e.to] = dmin[v] + e.cost;
               que.push(P(dmin[e.to],e.to));
            }
         }
      }
   };
};