#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &pathVisited)
    {
        vis[node] = true;
        pathVisited[node] = true;

        for (auto ajdnode : adj[node])
        {
            if (!vis[ajdnode])
            {

                if (dfs(ajdnode, adj, vis, pathVisited) == true)
                    return true;
            }
            else if (pathVisited[ajdnode])
            {

                return true;
            }
        }

        pathVisited[node] = false;

        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {

        vector<int> adj[V];

        for (int i = 0; i < edges.size(); i++)
        {
            auto current = edges[i];
            adj[current[0]].push_back(current[1]);
        }

        vector<bool> vis(V, false);
        vector<bool> pathVisited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, pathVisited) == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
};