#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int timer = 0;

private:
    void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges)
    {

        vis[node] = 1;

        tin[node] = low[node] = timer;

        timer++;

        for (auto adjnode : adj[node])
        {

            if (adjnode == parent)
                continue;

            if (vis[adjnode] == 0)
            {

                dfs(adjnode, node, adj, vis, tin, low, bridges);

                low[node] = min(low[node], low[adjnode]);

                if (low[adjnode] > tin[node])
                {
                    bridges.push_back({node, adjnode});
                }
            }
            else
            {

                low[node] = min(low[node], low[adjnode]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int v, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(v);

        for (int i = 0; i < edges.size(); i++)
        {

            int u = edges[i][0];

            int v = edges[i][1];

            adj[u].push_back(v);

            adj[v].push_back(u);
        }

        vector<vector<int>> bridges;

        vector<int> tin(v);
        vector<int> low(v);
        vector<int> vis(v, 0);

        dfs(0, -1, adj, vis, tin, low, bridges);

        return bridges;
    }
};