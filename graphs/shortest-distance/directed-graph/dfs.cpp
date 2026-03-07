#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<bool>& visited, stack<int>& s){
    visited[node] = true;

    for(auto adjnode : adj[node]){
        if(!visited[adjnode.first]){
            dfs(adjnode.first, adj, visited, s);
        }
    }

    s.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pair<int,int>>> adj(n);

    for(int i=0;i<m;i++){
        auto edge = edges[i];
        adj[edge[0]].push_back({edge[1],edge[2]});
    }

    vector<bool> visited(n,false);
    stack<int> s;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,s);
        }
    }

    vector<int> dis(n,INT_MAX);
    dis[0] = 0;

    while(!s.empty()){
        int node = s.top();
        s.pop();

        if(dis[node] != INT_MAX){
            for(auto adjnode : adj[node]){
                int v = adjnode.first;
                int wt = adjnode.second;

                if(dis[node] + wt < dis[v]){
                    dis[v] = dis[node] + wt;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        if(dis[i] == INT_MAX){
            dis[i] = -1;
        }
    }

    return dis;
}