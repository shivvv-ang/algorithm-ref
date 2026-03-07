#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        int n = adj.size();
        vector<int> dis(n, 1e9);
        dis[src] = 0;
        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (dis[node] + 1 < dis[it])
                {
                    dis[it] = 1 + dis[node];
                    q.push(it);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (dis[i] == 1e9)
            {
                dis[i] = -1;
            }
        }

        return dis;
    }
};