#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int, int>>> adj(n + 1);

    for(auto graph : g){
        int u = graph.first.first;
        int v = graph.first.second;
        int w = graph.second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<pair<pair<int, int>, int>> res;

    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
    > pq;

    vector<bool> vis(n + 1, false);

    pq.push({0, {1, -1}});

    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        int weight = top.first;
        int node = top.second.first;
        int parent = top.second.second;

        if(vis[node]) continue;

        vis[node] = true;

        if(parent != -1){
            res.push_back({{parent, node}, weight});
        }

        for(auto a : adj[node]){
            int adjnode = a.first;
            int wt = a.second;

            if(!vis[adjnode]){
                pq.push({wt, {adjnode, node}});
            }
        }
    }

    return res;
}