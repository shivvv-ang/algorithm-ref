#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    bool detectCycleInUndirectedGraph(int src, vector<int> adj[],int vis[]){
        vis[src] = true;

        queue<pair<int,int>>q;

        q.push({src,-1});

        while(!q.empty()){
            int node = q.front().first;
            int parentNode = q.front().second;

            q.pop();

            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push({it,node});
                }else if(parentNode!=it){
                    return true;
                }
            }
        }

        return false;
    }
public:
    bool detectCycle(int V, vector<int> adj[]) {
      int vis[V] = {0};

      for(int i=0;i<V;i++){
          if(!vis[i]){
              if(detectCycleInUndirectedGraph(i,adj,vis)) return true;
          }
      }

      return false;
    }
};