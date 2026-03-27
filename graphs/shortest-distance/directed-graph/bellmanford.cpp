#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int>dis(V,1e8);
    dis[src] =  0;
    
    for(int i=0;i<V-1;i++){
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            
            if(dis[u] !=1e8 && dis[u] + weight < dis[v] ){
                dis[v] = dis[u] + weight;
            }
        }
    }
    
    
    for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            
            if(dis[u] !=1e8 && dis[u] + weight < dis[v] ){
               return {-1};
            }
        }
    
    return dis;
 }