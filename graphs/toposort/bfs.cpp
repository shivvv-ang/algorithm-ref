#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
      void dfs(int node, vector<int> adj[], vector<bool>& vis, stack<int>& s) {
          vis[node] = true;
          
          for(auto adjNode : adj[node]) {
              if(!vis[adjNode]) {
                  dfs(adjNode, adj, vis, s);
              }
          }
          
          
          s.push(node);
      }
      
    public:
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
          
          vector<int> adj[V];
          
  
          for(int i = 0; i < edges.size(); i++) {
              adj[edges[i][0]].push_back(edges[i][1]);
          }
          
          stack<int> s;
          vector<bool> vis(V, false);
          
         
          for(int i = 0; i < V; i++) {
              if(!vis[i]) {
                  dfs(i, adj, vis, s);
              }
          }
          
          vector<int> ans;
          
   
          while(!s.empty()) {
              ans.push_back(s.top());
              s.pop();
          }
          
          return ans;
      }
  };