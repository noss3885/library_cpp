/*
プリム法
計算量 O(V^2)
要改善ダイクストラのようにpriority_queueを用いる
*/
#include <algorithm>

using namespace std;

#define MAX_V 10000
#define INF 99999999

int cost[MAX_V][MAX_V]; //u-v
int mincost[MAX_V];
bool used[MAX_V];
int V;

int prim(){
   for(int i=0;i<V;i++){
      mincost[i] = INF;
      used[i] = false;
   }
   mincost[0]=0;
   int res = 0;

   while(true){
      int v = -1;

      for(int u=0;u<V;u++){
         if(!used[u] && (v==-1 || mincost[u] < mincost[v]))
            v = u;
      }
      if(v==-1)break;
      used[v]=true;
      res += mincost[v];

      for(int u=0; u<V; u++){
         mincost[u]=min(mincost[u],cost[u][v]);
      }
   }
   return res;
}